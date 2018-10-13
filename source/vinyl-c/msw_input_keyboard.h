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
			virtual void onActivate() noexcept;
			virtual void onDeactivate() noexcept;

			virtual void onInputEvent(const InputEvent& event) noexcept;

		private:
			MSWInputKeyboard(const MSWInputKeyboard&) noexcept = delete;
			MSWInputKeyboard& operator=(const MSWInputKeyboard&) noexcept = delete;
		};
	}
}

#endif