#include <Windows.h>

typedef bool(__stdcall* PFNINSTALLHOOKPROC)();

void InstallHook(HWND window)
{
	HMODULE library = nullptr;

	HMODULE opengl32 = GetModuleHandle("opengl32.dll");
	if (opengl32)
	{
#if _DEBUG
		library = LoadLibrary("vinyl-opengl-d.dll");
#else
		library = LoadLibrary("vinyl-opengl.dll");
#endif
	}
	else
	{
		HMODULE d3d11 = GetModuleHandle("d3d11.dll");
		if (d3d11)
		{
#if _DEBUG
			library = LoadLibrary("vinyl-d3d11-d.dll");
#else
			library = LoadLibrary("vinyl-d3d11.dll");
#endif
		}
	}

	if (library)
	{
		PFNINSTALLHOOKPROC install = (PFNINSTALLHOOKPROC)GetProcAddress(library, "InstallHook");
		if (install())
		{
			MessageBox(window, "安装成功", "Success", 0);
			return;
		}
	}
	else
	{
		MessageBox(window, "目标程序没有使用OpenGL或D3D11", "Success", 0);
	}
}

extern "C" __declspec(dllexport) LRESULT _stdcall HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	MSG* msg = (MSG*)lParam;
	if (msg->message == WM_NULL)
		InstallHook(GetActiveWindow());

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