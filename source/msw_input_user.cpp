#include "msw_input_user.h"
#include <cstring> // std::memset
#include <thread>
#include <iostream>

namespace vinyl
{
	namespace input
	{
		MSWInputUser::MSWInputUser() noexcept
			: tracePrint_(false)
		{
		}

		MSWInputUser::~MSWInputUser() noexcept
		{
		}

		IInputUserPtr
		MSWInputUser::clone() const noexcept
		{
			return std::make_shared<MSWInputUser>();
		}

		void
		MSWInputUser::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::Sleep:
				std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(event.sleep.milliseconds));
				break;
			case InputEvent::Alert:
				if (event.message.message)
					MessageBox(NULL, event.message.message, " ", 0);
				break;
			case InputEvent::TracePrint:
				tracePrint_ = event.debug.trace ? true : false;
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
				case InputEvent::FinxPic: std::cout << "FinxPic" << std::endl; break;
				case InputEvent::GamePadButtonDown: std::cout << "GamePadButtonDown" << std::endl; break;
				case InputEvent::GamePadButtonUp: std::cout << "GamePadButtonUp" << std::endl; break;
				case InputEvent::TouchMotionMove: std::cout << "TouchMotionMove" << std::endl; break;
				case InputEvent::TouchMotionDown: std::cout << "TouchMotionDown" << std::endl; break;
				case InputEvent::TouchMotionUp: std::cout << "TouchMotionUp" << std::endl; break;
				case InputEvent::TouchMotionCancel: std::cout << "TouchMotionCancel" << std::endl; break;
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