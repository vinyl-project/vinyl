#ifndef VINYL_HOOK_H_
#define VINYL_HOOK_H_

#include <cstdio>

#ifndef VINYL_HOOK_C_LINKAGE
#	ifdef __cplusplus
#		define VINYL_HOOK_LINKAGE extern "C"
#	else
#		define VINYL_HOOK_LINKAGE extern
#	endif
#endif

#if defined(VINYL_BUILD_PLATFORM_WINDOWS)
#	if defined(VINYL_BUILD_DLL_EXPORT)
#		define VINYL_HOOK_EXPORT __declspec(dllexport)
#	else
#		if defined(VINYL_STATIC)
#			define VINYL_HOOK_EXPORT
#		else
#			define VINYL_HOOK_EXPORT __declspec(dllimport)
#		endif
#	endif

#	define VINYL_HOOK_CALL __stdcall
#else
#	define VINYL_HOOK_CALL
#endif

VINYL_HOOK_LINKAGE VINYL_HOOK_EXPORT void* VINYL_HOOK_CALL IATSetProcAddress(const char* dllname, const char* method, void* function);
VINYL_HOOK_LINKAGE VINYL_HOOK_EXPORT void* VINYL_HOOK_CALL IATGetProcAddress(const char* dllname, const char* method);
VINYL_HOOK_LINKAGE VINYL_HOOK_EXPORT void* VINYL_HOOK_CALL VtableHook(void* This, std::size_t method, void* function);

#endif