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

		void
		InputMouse::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::MouseMove:
			{
				this->onMouseMove(event.motion);
			}
			break;
			case InputEvent::MouseMoveTo:
			{
				this->onMouseMoveTo(event.motion);
			}
			break;
			case InputEvent::MouseButtonDown:
			{
				this->onMouseButtonDown(event.button);
			}
			break;
			case InputEvent::MouseButtonUp:
			{
				this->onMouseButtonUp(event.button);
			}
			break;
			case InputEvent::IsMouseButtonDown:
			{
				this->onIsMouseButtonDown(event.button);
			}
			break;
			case InputEvent::IsMouseButtonUp:
			{
				this->onIsMouseButtonUp(event.button);
			}
			break;
			case InputEvent::MouseWheelUp:
			{
				this->onMouseWheelUp(event.wheel);
			}
			break;
			case InputEvent::MouseWheelDown:
			{
				this->onMouseWheelDown(event.wheel);
			}
			break;
			case InputEvent::WaitButton:
			{
				this->onWaitButton(event.waitButton);
			}
			break;
			case InputEvent::LockMouse:
			{
			}
			break;
			case InputEvent::UnlockMouse:
			{
			}
			break;
			case InputEvent::GetMousePos:
			{
				this->onGetMousePos(event.pos);
			}
			break;
			default:
				break;
			}
		}

		void
		InputMouse::onMouseMove(const MouseMotionEvent& event) noexcept
		{			
		}

		void
		InputMouse::onMouseMoveTo(const MouseMotionEvent& event) noexcept
		{			
		}

		void
		InputMouse::onMouseButtonDown(const MouseButtonEvent& event) noexcept
		{			
		}

		void
		InputMouse::onMouseButtonUp(const MouseButtonEvent& event) noexcept
		{			
		}

		void
		InputMouse::onIsMouseButtonDown(const MouseButtonEvent& event) noexcept
		{			
		}

		void
		InputMouse::onIsMouseButtonUp(const MouseButtonEvent& event) noexcept
		{			
		}

		void
		InputMouse::onMouseWheelUp(const MouseWheelEvent& event) noexcept
		{			
		}

		void
		InputMouse::onMouseWheelDown(const MouseWheelEvent& event) noexcept
		{			
		}

		void
		InputMouse::onWaitButton(const WaitButtonEvent& event) noexcept
		{			
		}

		void
		InputMouse::onLockMouse(const InputEvent& event) noexcept
		{			
		}

		void
		InputMouse::onUnlockMouse(const InputEvent& event) noexcept
		{			
		}

		void
		InputMouse::onGetMousePos(const PosEvent& event) noexcept
		{			
		}
	}
}