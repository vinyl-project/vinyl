#include "msw_input_mouse.h"

namespace vinyl
{
	namespace input
	{
		#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
		#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

		MSWInputMouse::MSWInputMouse() noexcept
			: focusWindow_(false)
			, window_(0)
		{
		}

		MSWInputMouse::MSWInputMouse(WindHandle window) noexcept
			: focusWindow_(false)
			, window_(window)
		{
		}

		MSWInputMouse::~MSWInputMouse() noexcept
		{
		}

		void
		MSWInputMouse::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::MouseMove:
			{
				auto x = event.motion.xrel;
				auto y = event.motion.yrel;

				mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
				Sleep(event.motion.delay);
			}
			break;
			case InputEvent::MouseMoveTo:
			{
				auto x = event.motion.xrel;
				auto y = event.motion.yrel;

				SetCursorPos(x, y);
				Sleep(event.motion.delay);
			}
			break;
			case InputEvent::MouseButtonDown:
			{
				auto x = event.motion.xrel;
				auto y = event.motion.yrel;

				switch (event.button.button)
				{
				case InputButton::Code::Left:
					mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
					break;
				case InputButton::Code::Right:
					mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
					break;
				case InputButton::Code::Middle:
					mouse_event(MOUSEEVENTF_MIDDLEDOWN, x, y, 0, 0);
					break;
				default:
					break;
				}

				Sleep(event.button.delay);
			}
			break;
			case InputEvent::MouseButtonUp:
			{
				auto x = event.motion.xrel;
				auto y = event.motion.yrel;

				switch (event.button.button)
				{
				case InputButton::Code::Left:
					mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
					break;
				case InputButton::Code::Right:
					mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
					break;
				case InputButton::Code::Middle:
					mouse_event(MOUSEEVENTF_MIDDLEUP, x, y, 0, 0);
					break;
				}

				Sleep(event.button.delay);
			}
			break;
			case InputEvent::MouseWheelUp:
			{
				mouse_event(MOUSEEVENTF_WHEEL, 0, 0, WHEEL_DELTA, 0);
				Sleep(event.wheel.delay);
			}
			break;
			case InputEvent::MouseWheelDown:
			{
				mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -WHEEL_DELTA, 0);
				Sleep(event.wheel.delay);
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
			case InputEvent::GetFocus:
			{
				window_ = (WindHandle)event.window.windowID;
				focusWindow_ = true;
			}
			break;
			case InputEvent::LostFocus:
			{
				window_ = (WindHandle)event.window.windowID;
				focusWindow_ = false;
			}
			break;
			default:
				break;
			}
		}

		IInputMousePtr
		MSWInputMouse::clone() const noexcept
		{
			return std::make_shared<MSWInputMouse>();
		}
	}
}