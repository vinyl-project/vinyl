#ifndef VINYL_INPUT_CONTROLLER_H_
#define VINYL_INPUT_CONTROLLER_H_

#include <vinyl/iinput_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputController : public IInputController
		{
		public:
			InputController() noexcept;
			virtual ~InputController() noexcept;

			virtual void setActive(bool enable) noexcept(false);
			virtual bool getActive() const noexcept;

			virtual void reset() noexcept;

			virtual void sendInputEvent(const InputEvent& event) noexcept(false);

		protected:
			virtual void onReset() noexcept;

			virtual void onActivate() noexcept;
			virtual void onDeactivate() noexcept;

			virtual void onInputEvent(const InputEvent& event) noexcept(false);

		private:
			InputController(const InputController&) noexcept = delete;
			InputController& operator=(const InputController&) noexcept = delete;

		private:
			bool active_;
		};
	}
}

#endif