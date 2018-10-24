#ifndef VINYL_INPUT_MSW_KEYBOARD_H_
#define VINYL_INPUT_MSW_KEYBOARD_H_

#include <vinyl/input_key.h>
#include <vinyl/input_keyboard.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputKeyboard final : public InputKeyboard
		{
		public:
			MSWInputKeyboard() noexcept;
			virtual ~MSWInputKeyboard() noexcept;

			virtual IInputControllerPtr clone() const noexcept override;

		private:
			virtual void onActivate() noexcept override;
			virtual void onDeactivate() noexcept override;

			virtual void onKeyDown(const KeyboardEvent& event) noexcept override;
			virtual void onKeyUp(const KeyboardEvent& event) noexcept override;

			virtual void onIsKeyDown(const KeyboardEvent& event) noexcept override;
			virtual void onIsKeyUp(const KeyboardEvent& event) noexcept override;

			virtual void onWaitKey(const WaitKeyEvent& event) noexcept override;

		private:
			static LRESULT KeybdProc(int code, WPARAM wParam, LPARAM lParam) noexcept;

		private:
			MSWInputKeyboard(const MSWInputKeyboard&) noexcept = delete;
			MSWInputKeyboard& operator=(const MSWInputKeyboard&) noexcept = delete;

		private:
			static HHOOK hook_;
		};
	}
}

#endif