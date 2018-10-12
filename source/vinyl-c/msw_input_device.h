#ifndef VINYL_INPUT_MSW_DEVICE_H_
#define VINYL_INPUT_MSW_DEVICE_H_

#include <vinyl/input_device.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputDevice final : public InputDevice
		{
		public:
			MSWInputDevice() noexcept;
			~MSWInputDevice() noexcept;

			virtual IInputDevicePtr clone() const noexcept override;

		private:
			MSWInputDevice(const MSWInputDevice&) noexcept = delete;
			MSWInputDevice& operator=(const MSWInputDevice&) noexcept = delete;
		};
	}
}

#endif