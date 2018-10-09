#ifndef VINYL_INPUT_MSW_MOUSE_H_
#define VINYL_INPUT_MSW_MOUSE_H_

#include <vinyl/input_mouse.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputMouse final : public DefaultInputMouse
		{
		public:
			MSWInputMouse() noexcept;
			MSWInputMouse(WindHandle window) noexcept;
			~MSWInputMouse() noexcept;

			IInputMousePtr clone() const noexcept;

			void getPosition(InputButton::Type& x, InputButton::Type& y) const noexcept override;

			bool isButtonDown(InputButton::Code key) const noexcept override;
			bool isButtonUp(InputButton::Code key) const noexcept override;
			bool isButtonPressed(InputButton::Code key) const noexcept override;

		private:
			void onShowMouse() noexcept;
			void onHideMouse() noexcept;

			void onChangePosition(InputButton::Type x, InputButton::Type y) noexcept;

			void onInputEvent(const InputEvent& event) noexcept override;

		private:
			MSWInputMouse(const MSWInputMouse&) = delete;
			MSWInputMouse& operator=(const MSWInputMouse&) = delete;

		private:
			bool focusWindow_;
			WindHandle window_;
		};
	}
}

#endif