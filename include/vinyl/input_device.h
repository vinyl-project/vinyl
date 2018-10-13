#ifndef VINYL_INPUT_DEVICE_H_
#define VINYL_INPUT_DEVICE_H_

#include <vinyl/iinput_device.h>

#include <queue>
#include <thread>
#include <condition_variable>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputDevice : public IInputDevice
		{
		public:
			InputDevice() noexcept;
			virtual ~InputDevice() noexcept;

			virtual void setCaptureObject(WindHandle window) noexcept override;
			virtual WindHandle getCaptureObject() const noexcept override;

			virtual void enableEventPosting(bool enable) noexcept override;
			virtual bool enableEventPosting() const noexcept override;

			virtual void addInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void addInputListener(IInputControllerPtr&& listener) noexcept override;
			virtual void removeInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void removeInputListener(IInputControllerPtr&& listener) noexcept override;
			virtual void clearInputListener() noexcept override;
			virtual const IInputControllers& getInputListeners() const noexcept;

			virtual bool sendEvent(const InputEvent& event) noexcept override;
			virtual bool postEvent(const InputEvent& event) noexcept override;

			virtual bool peekEvents(InputEvent& event) noexcept override;
			virtual bool pollEvents(InputEvent& event) noexcept override;
			virtual bool waitEvents(InputEvent& event) noexcept override;
			virtual bool waitEvents(InputEvent& event, int timeout) noexcept override;
			virtual void flushEvent() noexcept override;

			virtual void reset() noexcept override;

			virtual IInputDevicePtr clone() const noexcept override;

		private:
			InputDevice(const InputDevice&) noexcept = delete;
			InputDevice& operator=(const InputDevice&) noexcept = delete;

		private:
			typedef std::queue<InputEvent>  InputEvents;

			InputEvents events_;
			IInputControllers inputListeners_;

			bool enableEventPosting_;

			std::mutex mutex_;
			std::condition_variable dispose_;
		};
	}
}

#endif