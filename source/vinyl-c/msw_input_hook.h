#ifndef VINYL_MSW_INPUT_HOOK_H_
#define VINYL_MSW_INPUT_HOOK_H_

#include <vinyl/input_controller.h>
#include <map>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputHook final : public InputController
		{
		public:
			MSWInputHook() noexcept;
			virtual ~MSWInputHook() noexcept;

			MSWInputHook& getInstance() const noexcept;

			void screenshot(const ScreenshotEvent& event) noexcept;

		public:
			virtual IInputControllerPtr clone() const noexcept;

		private:
			void installHook(HWND window) noexcept;
			void uninstallHook(HWND window) noexcept;
			void uninstallHooks() noexcept;

		private:
			MSWInputHook(const MSWInputHook&) noexcept = delete;
			MSWInputHook& operator=(const MSWInputHook&) noexcept = delete;

		private:
			std::map<HWND, HHOOK> hook_;
		};
	}
}

#endif