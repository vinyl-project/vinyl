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
				POINT pt;
				pt.x = event.motion.x;
				pt.y = event.motion.y;

				mouse_event(MOUSEEVENTF_MOVE, pt.x, pt.y, 0, 0);
				Sleep(event.motion.delay);
			}
			break;
			case InputEvent::MouseMoveTo:
			{
				POINT pt;
				pt.x = event.motion.x;
				pt.y = event.motion.y;

				if (event.motion.windowID)
					ScreenToClient((HWND)event.motion.windowID, &pt);

				SetCursorPos(pt.x, pt.y);
				Sleep(event.motion.delay);
			}
			break;
			case InputEvent::MouseButtonDown:
			{
				auto x = event.motion.x;
				auto y = event.motion.y;

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
				auto x = event.motion.x;
				auto y = event.motion.y;

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
			case InputEvent::IsMouseButtonDown:
			{
				if (event.button.state)
				{
					switch (event.button.button)
					{
					case InputButton::Code::Left:
						*event.button.state = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? true : false;
						break;
					case InputButton::Code::Right:
						*event.button.state = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? true : false;
						break;
					case InputButton::Code::Middle:
						*event.button.state = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? true : false;
						break;
					}
				}
			}
			break;
			case InputEvent::IsMouseButtonUp:
			{
				if (event.button.state)
				{
					switch (event.button.button)
					{
					case InputButton::Code::Left:
						*event.button.state = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? false : true;
						break;
					case InputButton::Code::Right:
						*event.button.state = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? false : true;
						break;
					case InputButton::Code::Middle:
						*event.button.state = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? false : true;
						break;
					}
				}
			}
			break;
			case InputEvent::MouseWheelUp:
			{
				if (event.wheel.windowID > 0)
				{
					POINT pt = {0};
					if (GetCursorPos(&pt))
					{
						*event.pos.x = pt.x;
						*event.pos.y = pt.y;
					}

					PostMessage((HWND)event.wheel.windowID, WM_MOUSEWHEEL, MAKEWORD(0, 1), MAKEWORD(pt.x, pt.y));
					Sleep(event.wheel.delay);
				}
				else
				{
					mouse_event(MOUSEEVENTF_WHEEL, 0, 0, WHEEL_DELTA, 0);
					Sleep(event.wheel.delay);
				}
			}
			break;
			case InputEvent::MouseWheelDown:
			{
				if (event.wheel.windowID > 0)
				{
					POINT pt = { 0 };
					if (GetCursorPos(&pt))
					{
						*event.pos.x = pt.x;
						*event.pos.y = pt.y;
					}

					PostMessage((HWND)event.wheel.windowID, WM_MOUSEWHEEL, MAKEWORD(0, 1), MAKEWORD(pt.x, pt.y));
					Sleep(event.wheel.delay);
				}
				else
				{
					mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -WHEEL_DELTA, 0);
					Sleep(event.wheel.delay);
				}
			}
			break;
			case InputEvent::WaitButton:
			{
				*event.waitButton.button = InputButton::Code::NumButtonCodes;

				while (*event.waitButton.button == InputButton::Code::NumButtonCodes)
				{
					for (std::size_t i = 0x01; i < 0x07; i++)
					{
						if (GetAsyncKeyState(i) & 0x8000)
						{
							switch (i)
							{
							case VK_LBUTTON:
								*event.waitButton.button = InputButton::Code::Left;
								break;
							case VK_RBUTTON:
								*event.waitButton.button = InputButton::Code::Right;
								break;
							case VK_MBUTTON:
								*event.waitButton.button = InputButton::Code::Middle;
								break;
							case VK_XBUTTON1:
								*event.waitButton.button = InputButton::Code::Mouse3;
								break;
							case VK_XBUTTON2:
								*event.waitButton.button = InputButton::Code::Mouse4;
								break;
							}

							if (event.waitButton.windowID > 0)
							{
								if (event.waitButton.windowID == (std::uint64_t)GetForegroundWindow())
									break;
								else
									*event.waitButton.button = InputButton::Code::NumButtonCodes;
							}
							else
							{
								break;
							}
						}
					}

					Sleep(event.waitButton.delay);
				}
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
				if (event.pos.x && event.pos.y)
				{
					POINT pt;
					if (GetCursorPos(&pt))
					{
						*event.pos.x = pt.x;
						*event.pos.y = pt.y;

						if (event.pos.windowID)
						{
							if (!ScreenToClient((HWND)event.pos.windowID, &pt))
							{
								*event.pos.x = std::numeric_limits<std::uint16_t>::max();
								*event.pos.y = std::numeric_limits<std::uint16_t>::max();
							}
						}
					}
					else
					{
						*event.pos.x = std::numeric_limits<std::uint16_t>::max();
						*event.pos.y = std::numeric_limits<std::uint16_t>::max();
					}
				}
			}
			break;
			case InputEvent::ObtainCapture:
			{
				window_ = (WindHandle)event.window.windowID;
				focusWindow_ = true;
			}
			break;
			case InputEvent::LostCapture:
			{
				window_ = (WindHandle)event.window.windowID;
				focusWindow_ = false;
			}
			break;
			default:
				break;
			}
		}

		IInputControllerPtr
		MSWInputMouse::clone() const noexcept
		{
			return std::make_shared<MSWInputMouse>();
		}
	}
}