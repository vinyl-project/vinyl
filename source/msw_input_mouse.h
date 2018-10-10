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
			MSWInputMouse(WindHandle window) noexcept;
			~MSWInputMouse() noexcept;

			virtual IInputMousePtr clone() const noexcept override;

		private:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

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