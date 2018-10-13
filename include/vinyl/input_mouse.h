#ifndef VINYL_INPUT_MOUSE_H_
#define VINYL_INPUT_MOUSE_H_

#include <vinyl/iinput_mouse.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputMouse : public IInputMouse
		{
		public:
			InputMouse() noexcept;
			virtual ~InputMouse() noexcept;

			virtual IInputControllerPtr clone() const noexcept override;

		private:
			InputMouse(const InputMouse&) noexcept = delete;
			InputMouse& operator=(const InputMouse&) noexcept = delete;
		};
	}
}

#endif