#include <vinyl/input_debug.h>
#include <iostream>

namespace vinyl
{
	namespace input
	{
		InputDebug::InputDebug() noexcept
			: tracePrint_(false)
		{
		}

		InputDebug::~InputDebug() noexcept
		{
		}

		IInputControllerPtr
		InputDebug::clone() const noexcept
		{
			return std::make_shared<InputDebug>();
		}

		void
		InputDebug::onInputEvent(const InputEvent& event) noexcept
		{
		}
	}
}