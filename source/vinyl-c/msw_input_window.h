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
			virtual void onNewWindow(const FindWindowEvent& event) noexcept override;

			virtual void onFindWindowFromPos(const FindWindowEvent& event) noexcept override;
			virtual void onFindWindowFromTitle(const FindWindowEvent& event) noexcept override;
			virtual void onFindWindowFromClassName(const FindWindowEvent& event) noexcept override;

			virtual void onGetWindowPos(const PosEvent& event) noexcept override;
			virtual void onGetWindowSize(const SizeEvent& event) noexcept override;
			virtual void onGetWindowTitle(const WindowEvent& event) noexcept override;
			virtual void onGetWindowClassName(const WindowEvent& event) noexcept override;

			virtual void onMessageBox(const MessageEvent& event) noexcept override;
			virtual void onSayString(const MessageEvent& event) noexcept override;

			virtual void onSleep(const SleepEvent& event) noexcept override;
			virtual void onCommand(const MessageEvent& event) noexcept override;

		private:
			MSWInputWindow(const MSWInputWindow&) noexcept = delete;
			MSWInputWindow& operator=(const MSWInputWindow&) noexcept = delete;
		};
	}
}

#endif