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
			if (event.windowID)
			{
				auto hook = hook_[(HWND)event.windowID];
				if (!hook)
				{
					installHook((HWND)event.windowID);
				}
			}
		}

		MSWInputHook&
		MSWInputHook::getInstance() noexcept
		{
			return instance_;
		}

		void 
		MSWInputHook::installHook(HWND window) noexcept(false)
		{
#if _DEBUG
			auto dllname = "vinyl-hook_d.dll";
#else
			auto dllname = "vinyl-hook.dll";
#endif
			auto module = LoadLibrary(dllname);
			if (module == NULL)
				throw std::runtime_error("Error: The Dll could not be found.");

			auto func = (HOOKPROC)GetProcAddress(module, "HookProc");
			if (func == NULL)
				throw std::runtime_error("Error: The DLL exported function was not found.");

			DWORD processid;
			DWORD threadid = ::GetWindowThreadProcessId(window, &processid);
			if (func == NULL)
				throw std::runtime_error("Error: The Thread ID was not found.");

			HHOOK hook = ::SetWindowsHookEx(WH_GETMESSAGE, func, module, threadid);
			if (!hook)
				throw std::runtime_error("Error: SetWindowsHookEx() failed.");
			
			PostThreadMessageW(threadid, WM_NULL, (WPARAM)window, (LPARAM)window);
			hook_[window] = hook;
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