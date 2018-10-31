#include <Windows.h>
#include <TlHelp32.h>
#include <DbgHelp.h>
#include <algorithm>
#include <d3d11.h>

typedef BOOL (WINAPI* PFNSWAPBUFFERSPRCO)(HDC);
typedef HRESULT (WINAPI* PFND3D10CREATEDEVICEANDSWAPCHAINPRCO)(IDXGIAdapter *pAdapter, D3D10_DRIVER_TYPE DriverType, HMODULE Software,UINT Flags,UINT SDKVersion, DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,IDXGISwapChain **ppSwapChain,ID3D10Device **ppDevice);
typedef HRESULT (WINAPI* PFNPRESENTPROC)(IDXGISwapChain* This, UINT SyncInterval, UINT Flags);

HWND window = nullptr;

PFNPRESENTPROC __Present = nullptr;
PFNSWAPBUFFERSPRCO __SwapBuffers = nullptr;

FARPROC IATGetProcAddress(const char* dllname, const char* method)
{
	PIMAGE_DOS_HEADER library = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	if (library->e_magic != IMAGE_DOS_SIGNATURE)
	{
		OutputDebugString("Error: Invalid Token: e_magic, dll is not a PE");
		return NULL;
	}

	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)((BYTE*)library + library->e_lfanew);
	if (header->Signature != IMAGE_NT_SIGNATURE)
	{
		OutputDebugString("Error: Invalid Token: Signature, dll is not a PE");
		return NULL;
	}

	PIMAGE_DATA_DIRECTORY iat = (PIMAGE_DATA_DIRECTORY)(&header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]);
	PIMAGE_IMPORT_DESCRIPTOR module = (PIMAGE_IMPORT_DESCRIPTOR)((BYTE*)library + iat->VirtualAddress);
	if (module == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return NULL;
	}

	FARPROC address = GetProcAddress(GetModuleHandle(dllname), method);
	if (address == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return NULL;
	}

	for (; module->FirstThunk != 0; module++)
	{
		char* name = (char*)library + module->Name;
		if (stricmp(name, dllname) == 0)
			break;
	}

	if (module->FirstThunk)
	{
		PIMAGE_THUNK_DATA thunk = (PIMAGE_THUNK_DATA)((BYTE*)library + module->FirstThunk);
		for (; thunk->u1.Function; thunk++)
		{
			if (thunk->u1.Function == (ULONGLONG)address)
				return address;
		}
	}

	return NULL;
}

BOOL IATSetProcAddress(const char* dllname, const char* method, FARPROC function)
{
	PIMAGE_DOS_HEADER library = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	if (library->e_magic != IMAGE_DOS_SIGNATURE) {
		OutputDebugString("Error: Invalid Token: e_magic, dll is not a PE");
		return FALSE;
	}

	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)((BYTE*)library + library->e_lfanew);
	if (header->Signature != IMAGE_NT_SIGNATURE) {
		OutputDebugString("Error: Invalid Token: Signature, dll is not a PE");
		return FALSE;
	}

	PIMAGE_DATA_DIRECTORY iat = (PIMAGE_DATA_DIRECTORY)(&header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]);
	PIMAGE_IMPORT_DESCRIPTOR module = (PIMAGE_IMPORT_DESCRIPTOR)((BYTE*)library + iat->VirtualAddress);
	if (module == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return FALSE;
	}

	FARPROC address = GetProcAddress(GetModuleHandle(dllname), method);
	if (address == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return FALSE;
	}

	for (; module->FirstThunk != 0; module++)
	{
		char* name = (char*)library + module->Name;
		if (stricmp(name, dllname) == 0)
			break;
	}

	if (!module->FirstThunk)
		return FALSE;

	PIMAGE_THUNK_DATA thunk = (PIMAGE_THUNK_DATA)((BYTE*)library + module->FirstThunk);
	for (; thunk->u1.Function; thunk++)
	{
		if (thunk->u1.Function == (ULONGLONG)address)
		{
			MEMORY_BASIC_INFORMATION mbi;
			VirtualQuery(thunk, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
			VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect);

			thunk->u1.Function = (ULONGLONG)function;

			DWORD protect;
			VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &protect);
			break;
		}
	}

	return TRUE;
}

FARPROC VtableHook(void* This, std::size_t method, FARPROC function)
{
	MEMORY_BASIC_INFORMATION mbi = {0};

	try
	{
		FARPROC* vtbl;
		vtbl = reinterpret_cast<FARPROC*>(This);
		vtbl = reinterpret_cast<FARPROC*>(vtbl[0]);

		VirtualQuery(vtbl, &mbi, sizeof(MEMORY_BASIC_INFORMATION));

		if (VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect))
		{
			FARPROC old = vtbl[method];
			vtbl[method] = function;

			DWORD protect;
			VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &protect);

			return old;
		}
	}
	catch (...)
	{
		DWORD protect;
		VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &protect);
	}

	return nullptr;
}

BOOL WINAPI HookSwapBuffers(HDC hdc)
{
	return __SwapBuffers(hdc);
}

HRESULT WINAPI HookPresent(IDXGISwapChain* This, UINT SyncInterval, UINT Flags)
{
	return __Present(This, SyncInterval, Flags);
}

BOOL WINAPI HookDX10Swapchain()
{
	WNDCLASSEXA wc;
	std::memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.hInstance = ::GetModuleHandle(NULL);
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = "GL33";
	if (!::RegisterClassEx(&wc))
		return false;

	HWND hwnd = CreateWindow("GL33", "This is my test ! ", WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, 0, NULL);

	ID3D10Device* device;
	IDXGISwapChain* swapchain;
	DXGI_SWAP_CHAIN_DESC swap_chain_description = { 0 };
	swap_chain_description.BufferDesc.Width = 600; // use window’s client area dims
	swap_chain_description.BufferDesc.Height = 400;
	swap_chain_description.BufferDesc.RefreshRate.Numerator = 60;
	swap_chain_description.BufferDesc.RefreshRate.Denominator = 1;
	swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swap_chain_description.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swap_chain_description.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swap_chain_description.SampleDesc.Count = 1;
	swap_chain_description.SampleDesc.Quality = 0;
	swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap_chain_description.BufferCount = 1;
	swap_chain_description.OutputWindow = hwnd;
	swap_chain_description.Windowed = true;
	swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swap_chain_description.Flags = 0;

	HMODULE d3d10 = LoadLibrary("d3d10.dll");
	PFND3D10CREATEDEVICEANDSWAPCHAINPRCO __D3D10CreateDeviceAndSwapChain = (PFND3D10CREATEDEVICEANDSWAPCHAINPRCO)GetProcAddress(d3d10, "D3D10CreateDeviceAndSwapChain");

	UINT createDeviceFlags = 0;
	__D3D10CreateDeviceAndSwapChain(0, D3D10_DRIVER_TYPE_HARDWARE, 0, createDeviceFlags, D3D10_SDK_VERSION, &swap_chain_description, &swapchain, &device);
	__Present = (PFNPRESENTPROC)VtableHook(swapchain, 8, (FARPROC)HookPresent);

	swapchain->Present(0, 0);

	swapchain->Release();
	device->Release();

	return true;
}

void initOpenGL()
{
	__SwapBuffers = (PFNSWAPBUFFERSPRCO)GetProcAddress(GetModuleHandle("gdi32.dll"), "SwapBuffers");

	IATSetProcAddress("gdi32.dll", "SwapBuffers", (FARPROC)HookSwapBuffers);
}

void initD3D10()
{
	HookDX10Swapchain();
}

void InstallHook()
{
	bool isOpengl = IATGetProcAddress("opengl32.dll", "SwapBuffers") ? true : false;
	if (isOpengl)
		initOpenGL();

	bool hasD3D10CreateDevice = IATGetProcAddress("d3d10.dll", "D3D10CreateDevice") ? true : false;
	bool hasD3D10CreateDeviceAndSwapChain = IATGetProcAddress("d3d10.dll", "D3D10CreateDeviceAndSwapChain") ? true : false;
	if (hasD3D10CreateDevice || hasD3D10CreateDeviceAndSwapChain)
		initD3D10();
}

extern "C" __declspec(dllexport) LRESULT _stdcall HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	MSG* msg = (MSG*)lParam;
	if (msg->message == WM_NULL)
	{
		window = (HWND)wParam;
		MessageBox(0, "安装成功", 0, 0);

		InstallHook();
	}

	return TRUE;
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}