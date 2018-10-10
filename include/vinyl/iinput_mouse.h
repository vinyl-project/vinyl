#ifndef VINYL_IINPUT_MOUSE_H_
#define VINYL_IINPUT_MOUSE_H_

#include <vinyl/input_controller.h>
#include <vinyl/input_button.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputMouse : public InputController
		{
		public:
			IInputMouse() noexcept = default;
			virtual ~IInputMouse() = default;

			virtual IInputMousePtr clone() const noexcept = 0;

		private:
			IInputMouse(const IInputMouse&) noexcept = delete;
			IInputMouse& operator=(const IInputMouse&) noexcept = delete;
		};
	}
}

#endif