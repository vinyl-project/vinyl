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

		IInputKeyboardPtr
		InputKeyboard::clone() const noexcept
		{
			return std::make_shared<InputKeyboard>();
		}

		void
		InputKeyboard::onInputEvent(const InputEvent& event) noexcept
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