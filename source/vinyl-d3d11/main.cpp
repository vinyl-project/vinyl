#include <d3d11.h>
#include <cstring>

#include "hook.h"

typedef HRESULT (WINAPI* PFNPRESENTPROC)(IDXGISwapChain* This, UINT SyncInterval, UINT Flags);

PFNPRESENTPROC __Present = nullptr;

HRESULT WINAPI HookPresent(IDXGISwapChain* swapchain, UINT SyncInterval, UINT Flags)
{
	IID riid;
	ID3D11Device* device = nullptr;
	swapchain->GetDevice(riid, (void**)&device);
	if (device)
	{
		IDXGIDevice *hDxgiDevice = NULL;
		device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&hDxgiDevice));
	}

	return __Present(swapchain, SyncInterval, Flags);
}

HWND WINAPI CreateHookWindow()
{
	WNDCLASSEXA wc;
	std::memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.hInstance = ::GetModuleHandle(NULL);
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = "HookDXSwapchain";
	if (!::RegisterClassEx(&wc))
		return false;

	HWND hwnd = CreateWindow("DXSwapchain", "HookDXSwapchain", WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, 0, NULL);

	return hwnd;
}

BOOL WINAPI HookDX11Swapchain(HWND hwnd)
{
	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain* swapchain;

	DXGI_SWAP_CHAIN_DESC sd = { 0 };
	sd.BufferDesc.Width = 600; // use window’s client area dims
	sd.BufferDesc.Height = 400;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hwnd;
	sd.Windowed = true;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};

	D3D11CreateDeviceAndSwapChain(
		0,
		D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE, 
		0, 
		createDeviceFlags, 
		featureLevels,
		ARRAYSIZE(featureLevels), 
		D3D11_SDK_VERSION, 
		&sd, 
		&swapchain, 
		&device, 
		&featureLevel,
		&deviceContext
	);

	__Present = (PFNPRESENTPROC)VtableHook(swapchain, 8, (FARPROC)HookPresent);

	swapchain->Present(0, 0);

	swapchain->Release();
	device->Release();

	return true;
}

bool InstallHook()
{
	return HookDX11Swapchain(CreateHookWindow());
}