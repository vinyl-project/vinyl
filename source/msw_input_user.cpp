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
			case InputEvent::Sleep:
				std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(event.sleep.milliseconds));
				break;
			case InputEvent::Alert:
				if (event.message.message)
					MessageBox(NULL, event.message.message, " ", 0);
				break;
			case InputEvent::Command:
				if (event.message.message)
					std::system(event.message.message);
				break;
			}
		}
	}
}