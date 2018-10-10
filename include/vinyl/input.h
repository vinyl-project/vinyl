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

			virtual void obtainMouseCapture() noexcept override;
			virtual void obtainKeyboardCapture() noexcept override;

			virtual void obtainMouseCapture(const IInputMousePtr& mouse) noexcept override;
			virtual void obtainMouseCapture(IInputMousePtr&& mouse) noexcept override;
			virtual void obtainKeyboardCapture(const IInputKeyboardPtr& key) noexcept override;
			virtual void obtainKeyboardCapture(IInputKeyboardPtr&& key) noexcept override;
			virtual void obtainCaptures() noexcept override;

			virtual void releaseMouseCapture() noexcept override;
			virtual void releaseKeyboardCapture() noexcept override;
			virtual void releaseCapture() noexcept override;

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
			IInputMousePtr mouseCaptureDevice_;
			IInputKeyboardPtr keyboardCaptureDevice_;
		};
	}
}

#endif