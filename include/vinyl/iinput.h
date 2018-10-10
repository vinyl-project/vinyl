#ifndef VINYL_IINPUT_H_
#define VINYL_IINPUT_H_

#include <vinyl/iinput_device.h>
#include <vinyl/iinput_keyboard.h>
#include <vinyl/iinput_mouse.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInput
		{
		public:
			IInput() = default;
			virtual ~IInput() = default;

			virtual void obtainMouseCapture() noexcept = 0;
			virtual void obtainKeyboardCapture() noexcept = 0;

			virtual void obtainMouseCapture(const IInputMousePtr& mouse) noexcept = 0;
			virtual void obtainMouseCapture(IInputMousePtr&& mouse) noexcept = 0;
			virtual void obtainKeyboardCapture(const IInputKeyboardPtr& key) noexcept = 0;
			virtual void obtainKeyboardCapture(IInputKeyboardPtr&& key) noexcept = 0;
			virtual void obtainCaptures() noexcept = 0;

			virtual void releaseMouseCapture() noexcept = 0;
			virtual void releaseKeyboardCapture() noexcept = 0;
			virtual void releaseCapture() noexcept = 0;

			virtual void reset() noexcept = 0;

			virtual void addInputListener(const IInputControllerPtr& listener) noexcept = 0;
			virtual void addInputListener(IInputControllerPtr&& listener) noexcept = 0;
			virtual void removeInputListener(const IInputControllerPtr& listener) noexcept = 0;
			virtual void removeInputListener(IInputControllerPtr&& listener) noexcept = 0;
			virtual void clearInputListener() noexcept = 0;

			virtual bool sendInputEvent(const InputEvent& event) noexcept = 0;

			virtual IInputPtr clone() const noexcept = 0;

		private:
			IInput(const IInput&) noexcept = delete;
			IInput& operator=(const IInput&) noexcept = delete;
		};
	}
}

#endif