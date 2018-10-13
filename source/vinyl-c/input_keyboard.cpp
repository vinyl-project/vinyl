#include <vinyl/input_keyboard.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputKeyboard::InputKeyboard() noexcept
		{
		}

		InputKeyboard::~InputKeyboard() noexcept
		{
		}

		IInputControllerPtr
		InputKeyboard::clone() const noexcept
		{
			return std::make_shared<InputKeyboard>();
		}
	}
}