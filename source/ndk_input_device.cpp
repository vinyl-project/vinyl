#include "ndk_input_device.h"

namespace vinyl
{
	namespace input
	{
		NDKInputDevice::NDKInputDevice() noexcept
		{
		}

		void
		NDKInputDevice::setCaptureObject(WindHandle window) noexcept
		{
		}

		WindHandle
		NDKInputDevice::getCaptureObject() const noexcept
		{
			return nullptr;
		}

		bool
		NDKInputDevice::peekEvents(InputEvent& event) noexcept
		{
			return false;
		}

		bool
		NDKInputDevice::pollEvents(InputEvent& event) noexcept
		{
			return false;
		}

		bool
		NDKInputDevice::waitEvents(InputEvent& event) noexcept
		{
			return false;
		}

		bool
		NDKInputDevice::waitEvents(InputEvent& event, int timeout) noexcept
		{
			return false;
		}

		void
		NDKInputDevice::flushEvent() noexcept
		{
		}
	}
}