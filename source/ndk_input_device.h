#ifndef VINYL_INPUT_NDK_DEVICE_H_
#define VINYL_INPUT_NDK_DEVICE_H_

#include <vinyl/input_device.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT NDKInputDevice : public DefaultInputDevice
		{
		public:
			NDKInputDevice() noexcept;

			virtual void setCaptureObject(WindHandle window) noexcept;
			virtual WindHandle getCaptureObject() const noexcept;

			virtual bool peekEvents(InputEvent& event) noexcept;
			virtual bool pollEvents(InputEvent& event) noexcept;
			virtual bool waitEvents(InputEvent& event) noexcept;
			virtual bool waitEvents(InputEvent& event, int timeout) noexcept;
			virtual void flushEvent() noexcept;

		private:
			NDKInputDevice(const NDKInputDevice&) noexcept = delete;
			NDKInputDevice& operator=(const NDKInputDevice&) noexcept = delete;

		private:

			bool _isButtonPress;

			int _button[InputButton::Code::NumButtonCodes];

			int _mouseX[InputButton::Code::NumButtonCodes];
			int _mouseY[InputButton::Code::NumButtonCodes];
		};
	}
}

#endif