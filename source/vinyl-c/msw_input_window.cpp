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
			case InputEvent::NewWindow:
			{
				STARTUPINFO si;
				PROCESS_INFORMATION pi;
				ZeroMemory(&si, sizeof(si));
				si.cb = sizeof(si);

				if (CreateProcess(0, (LPSTR)event.handle.str, 0, 0, 0, 0, 0, 0, &si, &pi))
				{
					auto EnumWindowsProc = [](HWND hwnd, LPARAM lParam) -> BOOL
					{
						DWORD dwCurProcessId = *((DWORD*)lParam);
						DWORD dwProcessId = 0;
						GetWindowThreadProcessId(hwnd, &dwProcessId);

						if (dwProcessId == dwCurProcessId && GetParent(hwnd) == NULL)
						{
							*((HWND *)lParam) = hwnd;
							return FALSE;
						}

						return TRUE;
					};

					for (int time = 0; time < 5000; time += 100)
					{
						if (!EnumWindows(EnumWindowsProc, (LPARAM)&pi.dwProcessId))
							*event.handle.windowID = (WindHandle)pi.dwProcessId;
						else
							*event.handle.windowID = nullptr;

						if (*event.handle.windowID)
							break;

						Sleep(100);
					}
				}
			}
			break;
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

				int size = MultiByteToWideChar(CP_UTF8, 0, event.handle.str, -1, 0, 0) + 1;
				if (size > 1 && size < PATHLIMITS)
				{
					wchar_t buffer[PATHLIMITS];
					if (MultiByteToWideChar(CP_UTF8, 0, event.handle.str, -1, buffer, size) > 0)
						*event.handle.windowID = FindWindowW(nullptr, buffer);
				}				
			}
			break;
			case InputEvent::FindWindowFromClassName:
			{
				constexpr std::size_t PATHLIMITS = 4096;

				int size = MultiByteToWideChar(CP_UTF8, 0, event.handle.str, -1, 0, 0) + 1;
				if (size > 1 && size < PATHLIMITS)
				{
					wchar_t buffer[PATHLIMITS];
					if (MultiByteToWideChar(CP_UTF8, 0, event.handle.str, -1, buffer, size) > 0)
						*event.handle.windowID = FindWindowW(buffer, nullptr);
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
					*event.w = GetSystemMetrics(SM_CXSCREEN);
					*event.h = GetSystemMetrics(SM_CYSCREEN);
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