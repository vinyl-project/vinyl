#include "msw_input_record.h"

namespace vinyl
{
	namespace input
	{
		thread_local HHOOK MSWInputRecord::hook_ = nullptr;

		MSWInputRecord::MSWInputRecord() noexcept
		{
		}

		MSWInputRecord::~MSWInputRecord() noexcept
		{
		}

		IInputControllerPtr
		MSWInputRecord::clone() const noexcept
		{
			return std::make_shared<MSWInputRecord>();
		}

		void 
		MSWInputRecord::onInputEvent(const InputEvent& event) noexcept(false)
		{
			switch (event.event)
			{
			case InputEvent::StartRecord:
				this->onStartRecord(event.record);
				break;
			case InputEvent::PauseRecord:
				this->onPauseRecord(event.record);
				break;
			case InputEvent::StopRecord:
				this->onStopRecord(event.record);
				break;
			}
		}

		void 
		MSWInputRecord::onStartRecord(const RecordEvent& event) noexcept(false)
		{
			if (!hook_)
				hook_ = SetWindowsHookEx(WH_GETMESSAGE, MSWInputRecord::WindowProc, GetModuleHandle("user32"), 0);
		}

		void 
		MSWInputRecord::onPauseRecord(const RecordEvent& event) noexcept(false)
		{
		}

		void 
		MSWInputRecord::onStopRecord(const RecordEvent& event) noexcept(false)
		{
			if (hook_)
			{
				UnhookWindowsHookEx(hook_);
				hook_ = nullptr;
			}
		}

		LRESULT
		MSWInputRecord::WindowProc(int code, WPARAM wParam, LPARAM lParam) noexcept
		{
			if (code < 0 || code == HC_NOREMOVE)
				return ::CallNextHookEx(hook_, code, wParam, lParam);

			switch (code)
			{
			case WM_KEYDOWN:
			{
			}
			break;
			case WM_KEYUP:
			{
			}
			break;
			}

			return ::CallNextHookEx(hook_, code, wParam, lParam);
		}
	}
}