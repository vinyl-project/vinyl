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

			virtual void lockMouse() noexcept = 0;
			virtual void unlockMouse() noexcept = 0;
			virtual bool isLockedMouse() const noexcept = 0;

			virtual void showMouse() noexcept = 0;
			virtual void hideMouse() noexcept = 0;
			virtual bool isShowMouse() noexcept = 0;

			virtual float getAxis(InputAxis::Code axis) const noexcept = 0;

			virtual void setPosition(InputButton::Type x, InputButton::Type y) noexcept = 0;
			virtual void getPosition(InputButton::Type& x, InputButton::Type& y) const noexcept = 0;

			virtual bool isButtonDown(InputButton::Code key) const noexcept = 0;
			virtual bool isButtonUp(InputButton::Code key) const noexcept = 0;
			virtual bool isButtonPressed(InputButton::Code key) const noexcept = 0;

			virtual IInputMousePtr clone() const noexcept = 0;

		private:
			IInputMouse(const IInputMouse&) noexcept = delete;
			IInputMouse& operator=(const IInputMouse&) noexcept = delete;
		};
	}
}

#endif