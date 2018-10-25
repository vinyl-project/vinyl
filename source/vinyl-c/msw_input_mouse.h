#ifndef VINYL_INPUT_MSW_MOUSE_H_
#define VINYL_INPUT_MSW_MOUSE_H_

#include <vinyl/input_mouse.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputMouse final : public InputMouse
		{
		public:
			MSWInputMouse() noexcept;
			~MSWInputMouse() noexcept;

			virtual IInputControllerPtr clone() const noexcept override;

		private:
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
			MSWInputMouse(const MSWInputMouse&) = delete;
			MSWInputMouse& operator=(const MSWInputMouse&) = delete;
		};
	}
}

#endif