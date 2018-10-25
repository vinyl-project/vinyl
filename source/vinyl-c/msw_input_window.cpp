#include "msw_input_window.h"
#include <cstring> // std::memset
#include <thread>

namespace vinyl
{
	namespace input
	{
		constexpr std::size_t PATHLIMITS = 4096;

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
		MSWInputWindow::onNewWindow(const FindWindowEvent& event) noexcept
		{
			STARTUPINFO si = {0};
			PROCESS_INFORMATION pi;
			si.cb = sizeof(si);

			int size = MultiByteToWideChar(CP_UTF8, 0, event.str, -1, 0, 0) + 1;
			if (size > 1 && size < PATHLIMITS)
			{
				wchar_t buffer[PATHLIMITS];
				int length = MultiByteToWideChar(CP_UTF8, 0, event.str, -1, buffer, size);
				if (length > 0)
				{
					if (!CreateProcess(0, (LPSTR)event.str, 0, 0, 0, 0, 0, 0, &si, &pi))
					{
						*event.windowID = nullptr;
						return;
					}
				}
			}

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
					*event.windowID = (WindHandle)(*(HWND **)&pi.dwProcessId);
				else
					*event.windowID = nullptr;

				if (*event.windowID)
					break;

				Sleep(100);
			}

			if (!*event.windowID)
				TerminateProcess(pi.hProcess, 0);
		}

		void
		MSWInputWindow::onFindWindowFromPos(const FindWindowEvent& event) noexcept
		{			
			POINT pt;
			pt.x = event.x;
			pt.y = event.y;

			*event.windowID = WindowFromPoint(pt);
		}

		void
		MSWInputWindow::onFindWindowFromTitle(const FindWindowEvent& event) noexcept
		{
			int size = MultiByteToWideChar(CP_UTF8, 0, event.str, -1, 0, 0) + 1;
			if (size > 1 && size < PATHLIMITS)
			{
				wchar_t buffer[PATHLIMITS];
				if (MultiByteToWideChar(CP_UTF8, 0, event.str, -1, buffer, size) > 0)
					*event.windowID = FindWindowW(nullptr, buffer);
			}
		}

		void
		MSWInputWindow::onFindWindowFromClassName(const FindWindowEvent& event) noexcept
		{
			int size = MultiByteToWideChar(CP_UTF8, 0, event.str, -1, 0, 0) + 1;
			if (size > 1 && size < PATHLIMITS)
			{
				wchar_t buffer[PATHLIMITS];
				if (MultiByteToWideChar(CP_UTF8, 0, event.str, -1, buffer, size) > 0)
					*event.windowID = FindWindowW(buffer, nullptr);
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
		MSWInputWindow::onGetWindowTitle(const WindowEvent& event) noexcept
		{
			if (event.output)
			{
				if (event.windowID)
				{
					wchar_t buffer[PATHLIMITS];
					GetWindowTextW((HWND)event.windowID, buffer, PATHLIMITS);
					WideCharToMultiByte(CP_UTF8, 0, buffer, std::wcslen(buffer), (LPSTR)event.output, PATHLIMITS, 0, 0);
				}
			}
		}

		void 
		MSWInputWindow::onGetWindowClassName(const WindowEvent& event) noexcept
		{
			if (event.output)
			{
				if (event.windowID)
				{
					wchar_t buffer[PATHLIMITS];
					GetClassNameW((HWND)event.windowID, buffer, PATHLIMITS);
					WideCharToMultiByte(CP_UTF8, 0, buffer, std::wcslen(buffer), (LPSTR)event.output, PATHLIMITS, 0, 0);
				}
			}
		}

		void 
		MSWInputWindow::onMessageBox(const MessageEvent& event) noexcept
		{
			if (event.message)
			{
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

		void 
		MSWInputWindow::onSleep(const SleepEvent& event) noexcept
		{
			std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(event.milliseconds));
		}

		void 
		MSWInputWindow::onCommand(const MessageEvent& event) noexcept
		{
			if (event.message)
			{
				std::string str = event.message;
				std::thread thread([=]() {std::system(str.c_str()); });
				thread.detach();
			}
		}
	}
}