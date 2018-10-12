#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		InputController::InputController() noexcept
			:capture_(true)
		{
		}

		InputController::~InputController() noexcept
		{
		}

		void
		InputController::obtainCaptures() noexcept
		{
			if (!capture_)
			{
				this->onObtainCapture();
				capture_ = true;
			}
		}

		void
		InputController::releaseCapture() noexcept
		{
			if (capture_)
			{
				this->onReleaseCapture();
				capture_ = false;
			}
		}

		bool
		InputController::capture() const noexcept
		{
			return capture_;
		}

		void
		InputController::reset() noexcept
		{
			this->onReset();
		}

		void
		InputController::onObtainCapture() noexcept
		{
		}

		void
		InputController::onReleaseCapture() noexcept
		{
		}

		void
		InputController::onReset() noexcept
		{
		}
	}
}