#include "msw_input_window.h"
#include <cstring> // std::memset
#include <thread>

namespace vinyl
{
	namespace input
	{
		MSWInputWindow::MSWInputWindow() noexcept
		{
		}

		MSWInputWindow::~MSWInputWindow() noexcept
		{
		}

		IInputControllerPtr
		MSWInputWindow::clone() const noexcept
		{
			return std::make_shared<MSWInputWindow>();
		}

		void
		MSWInputWindow::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::FindWindowFromPos:
			{
				POINT pt;
				pt.x = event.handle.x;
				pt.y = event.handle.y;

				*event.handle.windowID = WindowFromPoint(pt);
			}
			break;
			case InputEvent::FindWindowFromTile:
			{
				constexpr std::size_t PATHLIMITS = 4096;

				int size = MultiByteToWideChar(CP_UTF8, 0, event.handle.tile, -1, 0, 0) + 1;
				if (size > 1 && size < PATHLIMITS)
				{
					wchar_t buffer[PATHLIMITS];
					if (MultiByteToWideChar(CP_UTF8, 0, event.handle.tile, -1, buffer, size) > 0)
						*event.handle.windowID = FindWindowW(nullptr, buffer);
				}				
			}
			break;
			case InputEvent::GetWindowPos:
				this->onGetWindowPos(event.pos);
				break;
			case InputEvent::GetWindowSize:
				this->onGetWindowSize(event.size);
				break;
			case InputEvent::Alert:
				this->onMessageBox(event.message);
				break;
			case InputEvent::SayString:
				this->onSayString(event.message);
				break;
			case InputEvent::Sleep:
				std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(event.sleep.milliseconds));
				break;
			case InputEvent::Command:
			{
				if (event.message.message)
				{
					std::string str = event.message.message;
					std::thread thread([=]() {std::system(str.c_str()); });
					thread.detach();
				}
			}
			break;
			}
		}

		void
		MSWInputWindow::onGetWindowPos(const PosEvent& event) noexcept
		{
			if (event.x && event.y)
			{
				if (event.windowID)
				{
					RECT rc;
					if (GetWindowRect((HWND)event.windowID, &rc))
					{
						*event.x = rc.left;
						*event.y = rc.top;
					}
					else
					{
						*event.x = std::numeric_limits<std::uint16_t>::max();
						*event.y = std::numeric_limits<std::uint16_t>::max();
					}
				}
				else
				{
					*event.x = 0;
					*event.y = 0;
				}
			}
		}

		void 
		MSWInputWindow::onGetWindowSize(const SizeEvent& event) noexcept
		{
			if (event.w && event.h)
			{
				if (event.windowID)
				{
					RECT rc;
					if (GetWindowRect((HWND)event.windowID, &rc))
					{
						*event.w = rc.right - rc.left;
						*event.h = rc.bottom - rc.top;
					}
					else
					{
						*event.w = std::numeric_limits<std::uint16_t>::max();
						*event.h = std::numeric_limits<std::uint16_t>::max();
					}
				}
				else
				{
					*event.w = GetSystemMetrics(SM_CXFULLSCREEN);
					*event.h = GetSystemMetrics(SM_CYFULLSCREEN);
				}
			}
		}

		void 
		MSWInputWindow::onMessageBox(const MessageEvent& event) noexcept
		{
			if (event.message)
			{
				constexpr std::size_t PATHLIMITS = 4096;

				int size = MultiByteToWideChar(CP_UTF8, 0, event.message, -1, 0, 0) + 1;
				if (size > 1 && size < PATHLIMITS)
				{
					wchar_t buffer[PATHLIMITS];
					if (MultiByteToWideChar(CP_UTF8, 0, event.message, -1, buffer, size) > 0)
						MessageBoxW(event.windowID > 0 ? (HWND)event.windowID : 0, buffer, L" ", 0);
				}
			}
		}

		void 
		MSWInputWindow::onSayString(const MessageEvent& event) noexcept
		{
			constexpr std::size_t PATHLIMITS = 4096;

			if (event.message)
			{
				int size = MultiByteToWideChar(CP_UTF8, 0, event.message, -1, 0, 0) + 1;
				if (size > 1 && size < PATHLIMITS)
				{
					wchar_t buffer[PATHLIMITS];
					int length = MultiByteToWideChar(CP_UTF8, 0, event.message, -1, buffer, size);
					if (length > 0)
					{
						HWND hwnd = event.windowID > 0 ? (HWND)event.windowID : ::GetForegroundWindow();
						if (hwnd)
						{
							HWND top = ::GetTopWindow(hwnd);
							for (int i = 0; i < length; i++)
								::PostMessageW(top ? top : hwnd, WM_IME_CHAR, buffer[i], NULL);
						}
					}
				}
			}
		}
	}
}