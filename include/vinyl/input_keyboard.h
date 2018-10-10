#ifndef VINYL_INPUT_KEYBOARD_H_
#define VINYL_INPUT_KEYBOARD_H_

#include <vinyl/iinput_keyboard.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputKeyboard : public IInputKeyboard
		{
		public:
			InputKeyboard() noexcept;
			virtual ~InputKeyboard() noexcept;

			virtual IInputKeyboardPtr clone() const noexcept override;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

		private:
			InputKeyboard(const InputKeyboard&) noexcept = delete;
			InputKeyboard& operator=(const InputKeyboard&) noexcept = delete;
		};
	}
}

#endif