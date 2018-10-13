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
					RECT rect;
					GetClientRect(::GetDesktopWindow(), &rect);

					*event.size.w = rect.right - rect.left;
					*event.size.h = rect.bottom - rect.top;
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
			case InputEvent::Command:
				if (event.message.message)
					std::system(event.message.message);
				break;
			}
		}
	}
}