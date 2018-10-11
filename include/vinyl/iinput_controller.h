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

			virtual void onAttach() noexcept {};
			virtual void onDetach() noexcept {};

			virtual void onInputEvent(const InputEvent& event) noexcept(false) = 0;

		private:
			IInputController(const IInputController&) noexcept = delete;
			IInputController& operator=(const IInputController&)noexcept = delete;
		};
	}
}

#endif