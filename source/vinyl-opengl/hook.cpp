#include "hook.h"

#include <Windows.h>
#include <TlHelp32.h>
#include <DbgHelp.h>
#include <algorithm>

void* VINYL_HOOK_CALL IATGetProcAddress(const char* dllname, const char* method)
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

void* IATSetProcAddress(const char* dllname, const char* method, void* function)
{
	PIMAGE_DOS_HEADER library = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	if (library->e_magic != IMAGE_DOS_SIGNATURE) {
		OutputDebugString("Error: Invalid Token: e_magic, dll is not a PE");
		return nullptr;
	}

	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)((BYTE*)library + library->e_lfanew);
	if (header->Signature != IMAGE_NT_SIGNATURE) {
		OutputDebugString("Error: Invalid Token: Signature, dll is not a PE");
		return nullptr;
	}

	PIMAGE_DATA_DIRECTORY iat = (PIMAGE_DATA_DIRECTORY)(&header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]);
	PIMAGE_IMPORT_DESCRIPTOR module = (PIMAGE_IMPORT_DESCRIPTOR)((BYTE*)library + iat->VirtualAddress);
	if (module == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return nullptr;
	}

	FARPROC address = GetProcAddress(GetModuleHandle(dllname), method);
	if (address == NULL)
	{
		OutputDebugString("Error: Failed to get the first import table, dll is not a PE");
		return nullptr;
	}

	for (; module->FirstThunk != 0; module++)
	{
		char* name = (char*)library + module->Name;
		if (stricmp(name, dllname) == 0)
			break;
	}

	if (!module->FirstThunk)
		return nullptr;

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
			
			return address;
		}
	}

	return nullptr;
}

void* VtableHook(void* This, std::size_t method, FARPROC function)
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