#ifndef VINYL_IINPUT_CONTROLLER_H_
#define VINYL_IINPUT_CONTROLLER_H_

#include <vinyl/input_event.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputListener
		{
		public:
			IInputListener() noexcept;
			virtual ~IInputListener() noexcept;

			virtual void onAttach() noexcept;
			virtual void onDetach() noexcept;

			virtual void onInputEvent(const InputEvent& event) noexcept(false) = 0;

		private:
			IInputListener(const IInputListener&) noexcept = delete;
			IInputListener& operator=(const IInputListener&)noexcept = delete;
		};
	}
}

#endif