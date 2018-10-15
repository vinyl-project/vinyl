#include <vinyl/input_window.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputWindow::InputWindow() noexcept
		{
		}

		InputWindow::~InputWindow() noexcept
		{
		}

		IInputControllerPtr
		InputWindow::clone() const noexcept
		{
			return std::make_shared<InputWindow>();
		}
	}
}