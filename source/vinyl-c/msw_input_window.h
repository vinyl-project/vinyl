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

		private:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

			virtual void onGetWindowPos(const PosEvent& event) noexcept;
			virtual void onGetWindowSize(const SizeEvent& event) noexcept;
			virtual void onMessageBox(const MessageEvent& event) noexcept;
			virtual void onSayString(const MessageEvent& event) noexcept;

		private:
			MSWInputWindow(const MSWInputWindow&) noexcept = delete;
			MSWInputWindow& operator=(const MSWInputWindow&) noexcept = delete;
		};
	}
}

#endif