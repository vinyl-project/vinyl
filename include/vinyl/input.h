#ifndef VINYL_INPUT_H_
#define VINYL_INPUT_H_

#include <vinyl/iinput.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT Input : public IInput
		{
		public:
			Input() noexcept;
			virtual ~Input() noexcept;

			virtual void open() noexcept(false);
			virtual void close() noexcept;

			virtual void setCaptureObject(WindHandle window) noexcept;
			virtual WindHandle getCaptureObject() const noexcept;

			virtual void obtainMouseCapture() noexcept;
			virtual void obtainKeyboardCapture() noexcept;
			virtual void obtainUserCapture() noexcept;
			virtual void obtainDebugCapture() noexcept;
			virtual void obtainImageCapture() noexcept;

			virtual void obtainMouseCapture(const IInputMousePtr& mouse) noexcept;
			virtual void obtainKeyboardCapture(const IInputKeyboardPtr& key) noexcept;
			virtual void obtainUserCapture(const IInputUserPtr& user) noexcept;
			virtual void obtainDebugCapture(const IInputDebugPtr& user) noexcept;
			virtual void obtainImageCapture(const IInputImagePtr& image) noexcept;
			virtual void obtainCaptures() noexcept;

			virtual void releaseMouseCapture() noexcept;
			virtual void releaseKeyboardCapture() noexcept;
			virtual void releaseUserCapture() noexcept;
			virtual void releaseDebugCapture() noexcept;
			virtual void releaseImageCapture() noexcept;
			virtual void releaseCaptures() noexcept;

			virtual void addInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void removeInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void clearInputListener() noexcept override;

			virtual bool sendInputEvent(const InputEvent& event) noexcept override;

			virtual void reset() noexcept override;

			virtual IInputPtr clone() const noexcept override;

		private:
			Input(const Input&) noexcept = delete;
			Input& operator=(const Input&) noexcept = delete;

		private:
			IInputDevicePtr inputDevice_;
			IInputImagePtr imageCaptureDevice_;
			IInputUserPtr userCaptureDevice_;
			IInputDebugPtr debugCaptureDevice_;
			IInputMousePtr mouseCaptureDevice_;
			IInputKeyboardPtr keyboardCaptureDevice_;
		};
	}
}

#endif