#ifndef VINYL_IINPUT_DEVICE_H_
#define VINYL_IINPUT_DEVICE_H_

#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputDevice
		{
		public:
			IInputDevice() noexcept = default;
			virtual ~IInputDevice() = default;

			virtual void setCaptureObject(WindHandle window) noexcept = 0;
			virtual WindHandle getCaptureObject() const noexcept = 0;

			virtual void addInputListener(const IInputListenerPtr& listener) noexcept = 0;
			virtual void addInputListener(IInputListenerPtr&& listener) noexcept = 0;
			virtual void removeInputListener(const IInputListenerPtr& listener) noexcept = 0;
			virtual void removeInputListener(IInputListenerPtr&& listener) noexcept = 0;
			virtual void clearInputListener() noexcept = 0;

			virtual void enableEventPosting(bool enable) noexcept = 0;
			virtual bool enableEventPosting() const noexcept = 0;

			virtual bool sendEvent(const InputEvent& event) noexcept = 0;
			virtual bool postEvent(const InputEvent& event) noexcept = 0;

			virtual bool peekEvents(InputEvent& event) noexcept = 0;
			virtual bool pollEvents(InputEvent& event) noexcept = 0;
			virtual bool waitEvents(InputEvent& event) noexcept = 0;
			virtual bool waitEvents(InputEvent& event, int timeout) noexcept = 0;
			virtual void flushEvent() noexcept = 0;

			virtual IInputDevicePtr clone() const noexcept = 0;

		private:
			IInputDevice(const IInputDevice&) noexcept = delete;
			IInputDevice& operator=(const IInputDevice&) noexcept = delete;
		};
	}
}

#endif