#ifndef VINYL_INPUT_USER_H_
#define VINYL_INPUT_USER_H_

#include <vinyl/iinput_user.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputUser : public IInputUser
		{
		public:
			InputUser() noexcept;
			virtual ~InputUser() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		private:
			InputUser(const InputUser&) noexcept = delete;
			InputUser& operator=(const InputUser&) noexcept = delete;
		};
	}
}

#endif