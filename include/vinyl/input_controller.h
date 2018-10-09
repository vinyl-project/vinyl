#ifndef VINYL_INPUT_CONTROLLER_H_
#define VINYL_INPUT_CONTROLLER_H_

#include <vinyl/iinput_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputController : public IInputListener
		{
		public:
			InputController() noexcept;
			virtual ~InputController() noexcept;

			virtual void obtainCaptures() noexcept;
			virtual void releaseCapture() noexcept;
			virtual bool capture() const noexcept;

			virtual void onFrameBegin() noexcept;
			virtual void onFrameEnd() noexcept;

			virtual void onReset() noexcept;

			virtual void onObtainCapture() noexcept;
			virtual void onReleaseCapture() noexcept;

		private:
			InputController(const InputController&) noexcept = delete;
			InputController& operator=(const InputController&) noexcept = delete;

		private:
			bool capture_;
		};
	}
}

#endif