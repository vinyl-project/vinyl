#include <vinyl/input_user.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputUser::InputUser() noexcept
		{
		}

		InputUser::~InputUser() noexcept
		{
		}

		IInputUserPtr
		InputUser::clone() const noexcept
		{
			return std::make_shared<InputUser>();
		}

		void
		InputUser::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::GetFocus:
				this->obtainCaptures();
				break;
			case InputEvent::LostFocus:
				this->releaseCapture();
				break;
			case InputEvent::Reset:
				this->reset();
				break;
			default:
				break;
			}
		}
	}
}