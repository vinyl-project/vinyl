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
			case InputEvent::GetWindowSize:
			{
				if (event.size.w && event.size.h)
				{
					*event.size.w = GetSystemMetrics(SM_CXFULLSCREEN);
					*event.size.h = GetSystemMetrics(SM_CYFULLSCREEN);
				}
			}
			break;
			case InputEvent::Sleep:
				std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(event.sleep.milliseconds));
				break;
			case InputEvent::Alert:
			{
				if (event.message.message)
				{
					constexpr std::size_t PATHLIMITS = 4096;

					int size = MultiByteToWideChar(CP_UTF8, 0, event.message.message, -1, 0, 0) + 1;
					if (size > 1 && size < PATHLIMITS)
					{
						wchar_t buffer[PATHLIMITS];
						if (MultiByteToWideChar(CP_UTF8, 0, event.message.message, -1, buffer, size) > 0)
							MessageBoxW(NULL, buffer, L" ", 0);
					}
				}
			}
			break;
			case InputEvent::SayString:
			{
				if (event.message.message)
				{
					constexpr std::size_t PATHLIMITS = 4096;

					int size = MultiByteToWideChar(CP_UTF8, 0, event.message.message, -1, 0, 0) + 1;
					if (size > 1 && size < PATHLIMITS)
					{
						wchar_t buffer[PATHLIMITS];
						int length = MultiByteToWideChar(CP_UTF8, 0, event.message.message, -1, buffer, size);
						if (length > 0)
						{
							HWND hwnd = GetForegroundWindow();
							if (hwnd)
							{
								HWND top = GetTopWindow(hwnd);
								for (int i = 0; i < length; i++)
									PostMessageW(top ? top : hwnd, WM_IME_CHAR, buffer[i], NULL);
							}
						}
					}
				}
			}
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
	}
}