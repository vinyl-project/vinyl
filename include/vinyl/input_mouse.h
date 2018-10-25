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

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept;

			virtual void onMouseMove(const MouseMotionEvent& event) noexcept;
			virtual void onMouseMoveTo(const MouseMotionEvent& event) noexcept;
			virtual void onMouseButtonDown(const MouseButtonEvent& event) noexcept;
			virtual void onMouseButtonUp(const MouseButtonEvent& event) noexcept;

			virtual void onIsMouseButtonDown(const MouseButtonEvent& event) noexcept;
			virtual void onIsMouseButtonUp(const MouseButtonEvent& event) noexcept;

			virtual void onMouseWheelUp(const MouseWheelEvent& event) noexcept;
			virtual void onMouseWheelDown(const MouseWheelEvent& event) noexcept;

			virtual void onWaitButton(const WaitButtonEvent& event) noexcept;

			virtual void onLockMouse(const InputEvent& event) noexcept;
			virtual void onUnlockMouse(const InputEvent& event) noexcept;
			
			virtual void onGetMousePos(const PosEvent& event) noexcept;

		private:
			InputMouse(const InputMouse&) noexcept = delete;
			InputMouse& operator=(const InputMouse&) noexcept = delete;
		};
	}
}

#endif