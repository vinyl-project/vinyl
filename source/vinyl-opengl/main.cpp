#include <Windows.h>
#include "hook.h"

typedef BOOL (WINAPI* PFNSWAPBUFFERSPRCO)(HDC);

PFNSWAPBUFFERSPRCO __SwapBuffers = nullptr;

BOOL WINAPI HookSwapBuffers(HDC hdc)
{
	return __SwapBuffers(hdc);
}

bool InstallHook()
{
	__SwapBuffers = (PFNSWAPBUFFERSPRCO)IATSetProcAddress("gdi32.dll", "SwapBuffers", (FARPROC)HookSwapBuffers);
	return __SwapBuffers ? true : false;
}