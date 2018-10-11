#ifndef VINYL_MSW_INPUT_USER_H_
#define VINYL_MSW_INPUT_USER_H_

#include <vinyl/input_user.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputUser final : public InputUser
		{
		public:
			MSWInputUser() noexcept;
			virtual ~MSWInputUser() noexcept;

			virtual IInputUserPtr clone() const noexcept;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

		private:
			MSWInputUser(const MSWInputUser&) noexcept = delete;
			MSWInputUser& operator=(const MSWInputUser&) noexcept = delete;
		};
	}
}

#endif