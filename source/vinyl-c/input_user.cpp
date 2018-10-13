#include <vinyl/input_user.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputUser::InputUser() noexcept
		{
		}

		InputUser::~InputUser() noexcept
		{
		}

		IInputControllerPtr
		InputUser::clone() const noexcept
		{
			return std::make_shared<InputUser>();
		}
	}
}