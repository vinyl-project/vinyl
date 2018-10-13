#include "msw_input_device.h"

namespace vinyl
{
	namespace input
	{
		MSWInputDevice::MSWInputDevice() noexcept
		{
		}

		MSWInputDevice::~MSWInputDevice() noexcept
		{
		}

		IInputDevicePtr
		MSWInputDevice::clone() const noexcept
		{
			auto device = std::make_shared<MSWInputDevice>();
			for (auto& listener : this->getInputListeners())
				device->addInputListener(listener->clone());

			return device;
		}
	}
}