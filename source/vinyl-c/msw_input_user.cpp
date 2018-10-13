#include "msw_input_user.h"
#include <cstring> // std::memset
#include <thread>

namespace vinyl
{
	namespace input
	{
		MSWInputUser::MSWInputUser() noexcept
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
			case InputEvent::GetDesktopSize:
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
							for (int i = 0; i < length; i++)
								::PostMessage(hwnd, WM_IME_CHAR, buffer[i], NULL);
						}
					}
				}
			}
			break;
			case InputEvent::Command:
				if (event.message.message)
					std::system(event.message.message);
				break;
			}
		}
	}
}