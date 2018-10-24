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

		void
		InputKeyboard::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::KeyDown:
				this->onKeyDown(event.key);
				break;
			case InputEvent::KeyUp:
				this->onKeyUp(event.key);
				break;
			case InputEvent::IsKeyDown:
				this->onIsKeyDown(event.key);
				break;
			case InputEvent::IsKeyUp:
				this->onIsKeyUp(event.key);
				break;
			case InputEvent::WaitKey:
				this->onWaitKey(event.waitKey);
				break;
			default:
				break;
			}
		}

		void
		InputKeyboard::onKeyDown(const KeyboardEvent& event) noexcept
		{			
		}

		void
		InputKeyboard::onKeyUp(const KeyboardEvent& event) noexcept
		{			
		}

		void
		InputKeyboard::onIsKeyDown(const KeyboardEvent& event) noexcept
		{			
		}

		void
		InputKeyboard::onIsKeyUp(const KeyboardEvent& event) noexcept
		{			
		}

		void
		InputKeyboard::onWaitKey(const WaitKeyEvent& event) noexcept
		{			
		}

		IInputControllerPtr
		InputKeyboard::clone() const noexcept
		{
			return std::make_shared<InputKeyboard>();
		}
	}
}