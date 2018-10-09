#ifndef VINYL_INPUT_H_
#define VINYL_INPUT_H_

#include <vinyl/iinput.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT DefaultInput : public IInput
		{
		public:
			DefaultInput() noexcept;
			virtual ~DefaultInput() noexcept;

			virtual void open() noexcept(false);
			virtual void close() noexcept;

			virtual void setCaptureObject(WindHandle window) noexcept;
			virtual WindHandle getCaptureObject() const noexcept;

			virtual float getAxis(InputAxis::Code axis) const noexcept override;

			virtual void setMousePos(InputButton::Type x, InputButton::Type y) noexcept override;
			virtual void getMousePos(InputButton::Type& x, InputButton::Type& y) const noexcept override;

			virtual bool isKeyDown(InputKey::Code key) const noexcept override;
			virtual bool isKeyUp(InputKey::Code key) const noexcept override;
			virtual bool isKeyPressed(InputKey::Code key) const noexcept override;

			virtual bool isButtonDown(InputButton::Code key) const noexcept override;
			virtual bool isButtonUp(InputButton::Code key) const noexcept override;
			virtual bool isButtonPressed(InputButton::Code key) const noexcept override;

			virtual void showCursor(bool show) noexcept override;
			virtual bool isShowCursor() const noexcept override;

			virtual void lockCursor(bool lock) noexcept override;
			virtual bool isLockedCursor() const noexcept override;

			virtual void obtainMouseCapture() noexcept override;
			virtual void obtainKeyboardCapture() noexcept override;

			virtual void obtainMouseCapture(const IInputMousePtr& mouse) noexcept override;
			virtual void obtainMouseCapture(IInputMousePtr&& mouse) noexcept override;
			virtual void obtainKeyboardCapture(const IInputKeyboardPtr& key) noexcept override;
			virtual void obtainKeyboardCapture(IInputKeyboardPtr&& key) noexcept override;
			virtual void obtainCapture() noexcept override;

			virtual void releaseMouseCapture() noexcept override;
			virtual void releaseKeyboardCapture() noexcept override;
			virtual void releaseCapture() noexcept override;

			virtual void reset() noexcept override;

			virtual void addInputListener(const IInputListenerPtr& listener) noexcept override;
			virtual void addInputListener(IInputListenerPtr&& listener) noexcept override;
			virtual void removeInputListener(const IInputListenerPtr& listener) noexcept override;
			virtual void removeInputListener(IInputListenerPtr&& listener) noexcept override;
			virtual void clearInputListener() noexcept override;

			virtual bool sendInputEvent(const InputEvent& event) noexcept override;
			virtual bool postInputEvent(const InputEvent& event) noexcept override;

			virtual void updateBegin() noexcept override;
			virtual void update() noexcept override;
			virtual void updateEnd() noexcept override;

			virtual IInputPtr clone() const noexcept override;

		private:
			DefaultInput(const DefaultInput&) noexcept = delete;
			DefaultInput& operator=(const DefaultInput&) noexcept = delete;

		private:
			IInputDevicePtr inputDevice_;
			IInputMousePtr mouseCaptureDevice_;
			IInputKeyboardPtr keyboardCaptureDevice_;
		};
	}
}

#endif