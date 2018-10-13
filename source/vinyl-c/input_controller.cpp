#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		InputController::InputController() noexcept
			: active_(false)
		{
		}

		InputController::~InputController() noexcept
		{
		}

		void
		InputController::setActive(bool active) noexcept(false)
		{
			if (active_ != active)
			{
				if (active)
					this->onActivate();
				else
					this->onDeactivate();

				active_ = active;
			}
		}

		bool
		InputController::getActive() const noexcept
		{
			return active_;
		}

		void
		InputController::reset() noexcept
		{
			this->onReset();
		}

		void
		InputController::sendInputEvent(const InputEvent& event) noexcept(false)
		{
			switch (event.event)
			{
			case InputEvent::GetFocus:
				this->setActive(true);
				break;
			case InputEvent::LostFocus:
				this->setActive(false);
				break;
			case InputEvent::Reset:
				this->reset();
				break;
			default:
				break;
			}

			this->onInputEvent(event);
		}

		void
		InputController::onActivate() noexcept
		{
		}

		void
		InputController::onDeactivate() noexcept
		{
		}

		void
		InputController::onReset() noexcept
		{
		}

		void
		InputController::onInputEvent(const InputEvent& event) noexcept(false)
		{
		}
	}
}