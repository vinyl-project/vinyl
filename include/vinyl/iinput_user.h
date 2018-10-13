#ifndef VINYL_IINPUT_USER_H_
#define VINYL_IINPUT_USER_H_

#include <vinyl/input_controller.h>
#include <vinyl/input_button.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputUser : public InputController
		{
		public:
			IInputUser() noexcept = default;
			virtual ~IInputUser() = default;

		private:
			IInputUser(const IInputUser&) noexcept = delete;
			IInputUser& operator=(const IInputUser&) noexcept = delete;
		};
	}
}

#endif