#ifndef VINYL_MSW_INPUT_WINDOW_H_
#define VINYL_MSW_INPUT_WINDOW_H_

#include <vinyl/input_window.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputWindow final : public InputWindow
		{
		public:
			MSWInputWindow() noexcept;
			virtual ~MSWInputWindow() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

		private:
			MSWInputWindow(const MSWInputWindow&) noexcept = delete;
			MSWInputWindow& operator=(const MSWInputWindow&) noexcept = delete;
		};
	}
}

#endif