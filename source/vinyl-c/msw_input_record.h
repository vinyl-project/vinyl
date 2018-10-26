#ifndef VINYL_MSW_INPUT_RECORD_H_
#define VINYL_MSW_INPUT_RECORD_H_

#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputRecord final : public InputController
		{
		public:
			MSWInputRecord() noexcept;
			~MSWInputRecord() noexcept;

			virtual IInputControllerPtr clone() const noexcept override;

		private:
			virtual void onActivate() noexcept override;
			virtual void onDeactivate() noexcept override;

			virtual void onInputEvent(const InputEvent& event) noexcept(false) override;

			virtual void onStartRecord(const RecordEvent& event) noexcept(false);
			virtual void onPauseRecord(const RecordEvent& event) noexcept(false);
			virtual void onStopRecord(const RecordEvent& event) noexcept(false);

		private:
			static LRESULT KeybdProc(int code, WPARAM wParam, LPARAM lParam) noexcept;

		private:
			MSWInputRecord(const MSWInputRecord&) noexcept = delete;
			MSWInputRecord& operator=(const MSWInputRecord&) noexcept = delete;

		private:
			static thread_local HHOOK hook_;
		};
	}
}

#endif