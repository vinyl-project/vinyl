#include "msw_input_hook.h"


namespace vinyl
{
	namespace input
	{
		thread_local MSWInputHook instance_;

		MSWInputHook::MSWInputHook() noexcept
		{
		}

		MSWInputHook::~MSWInputHook() noexcept
		{
			this->uninstallHooks();
		}

		void 
		MSWInputHook::screenshot(const ScreenshotEvent& event) noexcept
		{
		}

		MSWInputHook&
		MSWInputHook::getInstance() const noexcept
		{
			return instance_;
		}

		void 
		MSWInputHook::installHook(HWND window) noexcept
		{
			DWORD processid;
			DWORD threadid = ::GetWindowThreadProcessId(window, &processid);
				
			HANDLE process = ::OpenProcess(PROCESS_ALL_ACCESS, 0, processid);
			if (process)
			{
				BOOL wow64;
				::IsWow64Process(process, &wow64);				
				::CloseHandle(process);

				auto dllname = wow64 ? "vinyl-hook.dll" : "vinyl-hook-86.dll";
				auto HookProc = [](int nCode, WPARAM wParam, LPARAM lParam) -> LRESULT
				{
					MSG* msg = (MSG*)lParam;
					if (msg->message == WM_NULL)
					{
						BOOL wow64;
						::IsWow64Process(GetCurrentProcess(), &wow64);
						::LoadLibrary(wow64 ? "vinyl-hook.dll" : "vinyl-hook-86.dll");
					}
						
					return TRUE;
				};

				HHOOK hook = ::SetWindowsHookEx(WH_GETMESSAGE, HookProc, ::GetModuleHandleA(dllname), threadid);
				if (hook)
				{
					PostThreadMessageW(threadid, WM_NULL, 0, 0);
					hook_[window] = hook;
				}
			}
		}

		void 
		MSWInputHook::uninstallHook(HWND window) noexcept
		{
			HHOOK hook = hook_[window];
			if (hook)
			{
				UnhookWindowsHookEx(hook);
				hook_[window] = nullptr;
			}
		}

		void
		MSWInputHook::uninstallHooks() noexcept
		{
			for (auto& it : hook_)
				uninstallHook(it.first);
		}

		IInputControllerPtr
		MSWInputHook::clone() const noexcept
		{
			return std::make_shared<MSWInputHook>();
		}
	}
}