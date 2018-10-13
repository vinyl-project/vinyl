#ifndef VINYL_IINPUT_CONTROLLER_H_
#define VINYL_IINPUT_CONTROLLER_H_

#include <vinyl/input_event.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputController
		{
		public:
			IInputController() noexcept = default;
			virtual ~IInputController() noexcept = default;

			virtual void setActive(bool enable) noexcept(false) = 0;
			virtual bool getActive() const noexcept = 0;

			virtual void reset() noexcept = 0;

			virtual void sendInputEvent(const InputEvent& event) noexcept(false) = 0;

			virtual IInputControllerPtr clone() const noexcept(false) = 0;

		private:
			IInputController(const IInputController&) noexcept = delete;
			IInputController& operator=(const IInputController&)noexcept = delete;
		};
	}
}

#endif