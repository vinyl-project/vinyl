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

		IInputMousePtr
		InputMouse::clone() const noexcept
		{
			return std::make_shared<InputMouse>();
		}

		void
		InputMouse::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::GetFocus:
				this->obtainCaptures();
				break;
			case InputEvent::LostFocus:
				this->releaseCapture();
				break;
			case InputEvent::Reset:
				this->reset();
				break;
			default:
				break;
			}
		}
	}
}