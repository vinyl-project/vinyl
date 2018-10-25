#include <vinyl/input_window.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputWindow::InputWindow() noexcept
		{
		}

		InputWindow::~InputWindow() noexcept
		{
		}

		IInputControllerPtr
		InputWindow::clone() const noexcept
		{
			return std::make_shared<InputWindow>();
		}

		void
		InputWindow::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::NewWindow:
				this->onNewWindow(event.handle);
				break;
			case InputEvent::FindWindowFromPos:
				this->onFindWindowFromPos(event.handle);
				break;
			case InputEvent::FindWindowFromTitle:
				this->onFindWindowFromTitle(event.handle);
				break;
			case InputEvent::FindWindowFromClassName:
				this->onFindWindowFromClassName(event.handle);
				break;
			case InputEvent::GetWindowPos:
				this->onGetWindowPos(event.pos);
				break;
			case InputEvent::GetWindowSize:
				this->onGetWindowSize(event.size);
				break;
			case InputEvent::GetWindowTitle:
				this->onGetWindowTitle(event.window);
				break;
			case InputEvent::GetWindowClassName:
				this->onGetWindowClassName(event.window);
				break;
			case InputEvent::Alert:
				this->onMessageBox(event.message);
				break;
			case InputEvent::SayString:
				this->onSayString(event.message);
				break;
			case InputEvent::Sleep:
				this->onSleep(event.sleep);
				break;
			case InputEvent::Command:
				this->onCommand(event.message);
				break;
			}
		}

		void
		InputWindow::onNewWindow(const FindWindowEvent& event) noexcept
		{			
		}

		void
		InputWindow::onFindWindowFromPos(const FindWindowEvent& event) noexcept
		{			
		}

		void
		InputWindow::onFindWindowFromTitle(const FindWindowEvent& event) noexcept
		{			
		}

		void
		InputWindow::onFindWindowFromClassName(const FindWindowEvent& event) noexcept
		{			
		}

		void
		InputWindow::onGetWindowPos(const PosEvent& event) noexcept
		{			
		}

		void
		InputWindow::onGetWindowSize(const SizeEvent& event) noexcept
		{			
		}

		void 
		InputWindow::onGetWindowTitle(const WindowEvent& event) noexcept
		{
		}

		void 
		InputWindow::onGetWindowClassName(const WindowEvent& event) noexcept
		{
		}

		void
		InputWindow::onMessageBox(const MessageEvent& event) noexcept
		{			
		}

		void
		InputWindow::onSayString(const MessageEvent& event) noexcept
		{			
		}

		void 
		InputWindow::onSleep(const SleepEvent& event) noexcept
		{
		}

		void
		InputWindow::onCommand(const MessageEvent& event) noexcept
		{			
		}
	}
}