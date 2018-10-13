#include <vinyl/input_debug.h>
#include <iostream>

namespace vinyl
{
	namespace input
	{
		InputDebug::InputDebug() noexcept
			: tracePrint_(false)
		{
		}

		InputDebug::~InputDebug() noexcept
		{
		}

		IInputControllerPtr
		InputDebug::clone() const noexcept
		{
			return std::make_shared<InputDebug>();
		}

		void
		InputDebug::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::TracePrint:
				tracePrint_ = event.debug.trace ? true : false;
				break;
			default:
				break;
			}

			if (tracePrint_)
			{
				switch (event.event)
				{
				case InputEvent::KeyDown: std::cout << "KeyDown" << std::endl; break;
				case InputEvent::KeyUp: std::cout << "KeyUp" << std::endl; break;
				case InputEvent::WaitKey: std::cout << "WaitKey" << std::endl; break;
				case InputEvent::GetLastKey: std::cout << "GetLastKey" << std::endl; break;
				case InputEvent::SetSimMode: std::cout << "SetSimMode" << std::endl; break;
				case InputEvent::MouseMove: std::cout << "MouseMove" << std::endl; break;
				case InputEvent::MouseMoveTo: std::cout << "MouseMoveTo" << std::endl; break;
				case InputEvent::MouseButtonDown: std::cout << "MouseButtonDown" << std::endl; break;
				case InputEvent::MouseButtonUp: std::cout << "MouseButtonUp" << std::endl; break;
				case InputEvent::MouseWheelUp: std::cout << "MouseWheelUp" << std::endl; break;
				case InputEvent::MouseWheelDown: std::cout << "MouseWheelDown" << std::endl; break;
				case InputEvent::LockMouse: std::cout << "LockMouse" << std::endl; break;
				case InputEvent::UnlockMouse: std::cout << "UnlockMouse" << std::endl; break;
				case InputEvent::WaitMouse: std::cout << "WaitMouse" << std::endl; break;
				case InputEvent::FindColor: std::cout << "FindColor" << std::endl; break;
				case InputEvent::FindColorEx: std::cout << "FindColorEx" << std::endl; break;
				case InputEvent::FindCenterColor: std::cout << "FindCenterColor" << std::endl; break;
				case InputEvent::FindPic: std::cout << "FinxPic" << std::endl; break;
				case InputEvent::Sleep: std::cout << "Sleep" << std::endl; break;
				case InputEvent::Alert: std::cout << "Alert" << std::endl; break;
				case InputEvent::TracePrint: std::cout << "TracePrint" << std::endl; break;
				case InputEvent::Screenshot: std::cout << "Screenshot" << std::endl; break;
				case InputEvent::GetFocus: std::cout << "GetFocus" << std::endl; break;
				case InputEvent::LostFocus: std::cout << "LostFocus" << std::endl; break;
				default:
					break;
				}
			}
		}
	}
}