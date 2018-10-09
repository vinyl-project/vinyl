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

			virtual bool isKeyDown(InputKey::Code key) const noexcept = 0;
			virtual bool isKeyUp(InputKey::Code key) const noexcept = 0;
			virtual bool isKeyPressed(InputKey::Code key) const noexcept = 0;

			virtual IInputKeyboardPtr clone() const noexcept = 0;

		private:
			IInputKeyboard(const IInputKeyboard&) noexcept = delete;
			IInputKeyboard& operator=(const IInputKeyboard&) noexcept = delete;
		};
	}
}

#endif