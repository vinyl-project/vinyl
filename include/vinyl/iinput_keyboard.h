#ifndef VINYL_IINPUT_KEYBOARD_H_
#define VINYL_IINPUT_KEYBOARD_H_

#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputKeyboard : public InputController
		{
		public:
			IInputKeyboard() noexcept = default;
			virtual ~IInputKeyboard() = default;

			virtual IInputKeyboardPtr clone() const noexcept = 0;

		private:
			IInputKeyboard(const IInputKeyboard&) noexcept = delete;
			IInputKeyboard& operator=(const IInputKeyboard&) noexcept = delete;
		};
	}
}

#endif