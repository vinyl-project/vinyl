#include <vinyl/input_mouse.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputMouse::InputMouse() noexcept
		{
		}

		InputMouse::~InputMouse() noexcept
		{
		}

		IInputControllerPtr
		InputMouse::clone() const noexcept
		{
			return std::make_shared<InputMouse>();
		}
	}
}