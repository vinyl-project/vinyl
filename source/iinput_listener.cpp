#include <vinyl/iinput_listener.h>

namespace vinyl
{
	namespace input
	{
		IInputListener::IInputListener() noexcept
		{
		}

		IInputListener::~IInputListener()
		{
		}

		void
		IInputListener::onAttach() noexcept
		{
		}

		void
		IInputListener::onDetach() noexcept
		{
		}
	}
}