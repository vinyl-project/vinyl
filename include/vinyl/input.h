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

			virtual void obtainMouseCapture(const IInputMousePtr& mouse) noexcept;
			virtual void obtainMouseCapture(IInputMousePtr&& mouse) noexcept;
			virtual void obtainKeyboardCapture(const IInputKeyboardPtr& key) noexcept;
			virtual void obtainKeyboardCapture(IInputKeyboardPtr&& key) noexcept;
			virtual void obtainUserCapture(const IInputUserPtr& user) noexcept;
			virtual void obtainUserCapture(IInputUserPtr&& user) noexcept;
			virtual void obtainCaptures() noexcept;

			virtual void releaseMouseCapture() noexcept;
			virtual void releaseKeyboardCapture() noexcept;
			virtual void releaseUserCapture() noexcept;
			virtual void releaseCapture() noexcept;

			virtual void reset() noexcept override;

			virtual void addInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void addInputListener(IInputControllerPtr&& listener) noexcept override;
			virtual void removeInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void removeInputListener(IInputControllerPtr&& listener) noexcept override;
			virtual void clearInputListener() noexcept override;

			virtual bool sendInputEvent(const InputEvent& event) noexcept override;

			virtual IInputPtr clone() const noexcept override;

		private:
			Input(const Input&) noexcept = delete;
			Input& operator=(const Input&) noexcept = delete;

		private:
			IInputDevicePtr inputDevice_;
			IInputUserPtr userCaptureDevice_;
			IInputMousePtr mouseCaptureDevice_;
			IInputKeyboardPtr keyboardCaptureDevice_;
		};
	}
}

#endif