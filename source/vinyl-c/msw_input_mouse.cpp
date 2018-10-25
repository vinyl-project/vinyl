#include "msw_input_mouse.h"
#include <algorithm>

namespace vinyl
{
	namespace input
	{
		#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
		#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

		MSWInputMouse::MSWInputMouse() noexcept
		{
		}

		MSWInputMouse::~MSWInputMouse() noexcept
		{
		}

		IInputControllerPtr
		MSWInputMouse::clone() const noexcept
		{
			return std::make_shared<MSWInputMouse>();
		}

		void
		MSWInputMouse::onMouseMove(const MouseMotionEvent& event) noexcept
		{
			POINT cur;
			GetCursorPos(&cur);

			POINT pt;
			pt.x = cur.x + event.x;
			pt.y = cur.y + event.y;

			SetCursorPos(pt.x, pt.y);
			Sleep(event.delay);
		}

		void
		MSWInputMouse::onMouseMoveTo(const MouseMotionEvent& event) noexcept
		{
			POINT pt;
			pt.x = event.x;
			pt.y = event.y;

			if (event.windowID)
			{
				RECT rc;
				GetWindowRect((HWND)event.windowID, &rc);
				pt.x = std::min(rc.left + pt.x, rc.right);
				pt.y = std::min(rc.top + pt.y, rc.bottom);
			}

			SetCursorPos(pt.x, pt.y);
			Sleep(event.delay);
		}

		void
		MSWInputMouse::onMouseButtonDown(const MouseButtonEvent& event) noexcept
		{
			auto x = event.x;
			auto y = event.y;

			switch (event.button)
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

			Sleep(event.delay);
		}

		void
		MSWInputMouse::onMouseButtonUp(const MouseButtonEvent& event) noexcept
		{
			auto x = event.x;
			auto y = event.y;

			switch (event.button)
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

			Sleep(event.delay);
		}

		void
		MSWInputMouse::onIsMouseButtonDown(const MouseButtonEvent& event) noexcept
		{			
			if (event.state)
			{
				switch (event.button)
				{
				case InputButton::Code::Left:
					*event.state = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? true : false;
					break;
				case InputButton::Code::Right:
					*event.state = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? true : false;
					break;
				case InputButton::Code::Middle:
					*event.state = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? true : false;
					break;
				}
			}
		}

		void
		MSWInputMouse::onIsMouseButtonUp(const MouseButtonEvent& event) noexcept
		{
			if (event.state)
			{
				switch (event.button)
				{
				case InputButton::Code::Left:
					*event.state = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? false : true;
					break;
				case InputButton::Code::Right:
					*event.state = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? false : true;
					break;
				case InputButton::Code::Middle:
					*event.state = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? false : true;
					break;
				}
			}
		}

		void
		MSWInputMouse::onMouseWheelUp(const MouseWheelEvent& event) noexcept
		{
			if (event.windowID > 0)
			{
				POINT pt = {0};
				GetCursorPos(&pt);

				PostMessage((HWND)event.windowID, WM_MOUSEWHEEL, MAKEWORD(0, 1), MAKEWORD(pt.x, pt.y));
				Sleep(event.delay);
			}
			else
			{
				mouse_event(MOUSEEVENTF_WHEEL, 0, 0, WHEEL_DELTA, 0);
				Sleep(event.delay);
			}
		}

		void
		MSWInputMouse::onMouseWheelDown(const MouseWheelEvent& event) noexcept
		{
			if (event.windowID > 0)
			{
				POINT pt = { 0 };
				GetCursorPos(&pt);

				PostMessage((HWND)event.windowID, WM_MOUSEWHEEL, MAKEWORD(0, -1), MAKEWORD(pt.x, pt.y));
				Sleep(event.delay);
			}
			else
			{
				mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -WHEEL_DELTA, 0);
				Sleep(event.delay);
			}
		}


		void
		MSWInputMouse::onWaitButton(const WaitButtonEvent& event) noexcept
		{
			*event.button = InputButton::Code::NumButtonCodes;

			while (*event.button == InputButton::Code::NumButtonCodes)
			{
				for (std::size_t i = 0x01; i < 0x07; i++)
				{
					if (GetAsyncKeyState(i) & 0x8000)
					{
						switch (i)
						{
						case VK_LBUTTON:
							*event.button = InputButton::Code::Left;
							break;
						case VK_RBUTTON:
							*event.button = InputButton::Code::Right;
							break;
						case VK_MBUTTON:
							*event.button = InputButton::Code::Middle;
							break;
						case VK_XBUTTON1:
							*event.button = InputButton::Code::Mouse3;
							break;
						case VK_XBUTTON2:
							*event.button = InputButton::Code::Mouse4;
							break;
						}

						if (event.windowID > 0)
						{
							if (event.windowID == (std::uint64_t)GetForegroundWindow())
								break;
							else
								*event.button = InputButton::Code::NumButtonCodes;
						}
						else
						{
							break;
						}
					}
				}

				Sleep(event.delay);
			}
		}

		void
		MSWInputMouse::onLockMouse(const InputEvent& event) noexcept
		{			
		}

		void
		MSWInputMouse::onUnlockMouse(const InputEvent& event) noexcept
		{			
		}

		void
		MSWInputMouse::onGetMousePos(const PosEvent& event) noexcept
		{
			if (event.x && event.y)
			{
				POINT pt;
				if (GetCursorPos(&pt))
				{
					*event.x = pt.x;
					*event.y = pt.y;

					if (event.windowID)
					{
						RECT rc;
						if (GetWindowRect((HWND)event.windowID, &rc))
						{
							*event.x = pt.x - rc.left;
							*event.y = pt.y - rc.top;
						}
						else
						{
							*event.x = std::numeric_limits<std::uint16_t>::max();
							*event.y = std::numeric_limits<std::uint16_t>::max();
						}
					}
				}
				else
				{
					*event.x = std::numeric_limits<std::uint16_t>::max();
					*event.y = std::numeric_limits<std::uint16_t>::max();
				}
			}
		}
	}
}