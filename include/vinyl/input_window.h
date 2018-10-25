#ifndef VINYL_INPUT_WINDOW_H_
#define VINYL_INPUT_WINDOW_H_

#include <vinyl/iinput_window.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputWindow : public IInputWindow
		{
		public:
			InputWindow() noexcept;
			virtual ~InputWindow() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept;

			virtual void onNewWindow(const FindWindowEvent& event) noexcept;

			virtual void onFindWindowFromPos(const FindWindowEvent& event) noexcept;
			virtual void onFindWindowFromTitle(const FindWindowEvent& event) noexcept;
			virtual void onFindWindowFromClassName(const FindWindowEvent& event) noexcept;

			virtual void onGetWindowPos(const PosEvent& event) noexcept;
			virtual void onGetWindowSize(const SizeEvent& event) noexcept;
			virtual void onGetWindowTitle(const WindowEvent& event) noexcept;
			virtual void onGetWindowClassName(const WindowEvent& event) noexcept;

			virtual void onMessageBox(const MessageEvent& event) noexcept;
			virtual void onSayString(const MessageEvent& event) noexcept;

			virtual void onSleep(const SleepEvent& event) noexcept;
			virtual void onCommand(const MessageEvent& event) noexcept;

		private:
			InputWindow(const InputWindow&) noexcept = delete;
			InputWindow& operator=(const InputWindow&) noexcept = delete;
		};
	}
}

#endif