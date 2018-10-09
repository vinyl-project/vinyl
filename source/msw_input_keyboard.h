#ifndef VINYL_INPUT_MSW_KEYBOARD_H_
#define VINYL_INPUT_MSW_KEYBOARD_H_

#include <vinyl/input_key.h>
#include <vinyl/input_keyboard.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputKeyboard final : public DefaultInputKeyboard
		{
		public:
			MSWInputKeyboard() noexcept;
			virtual ~MSWInputKeyboard() noexcept;

			virtual bool isKeyDown(InputKey::Code key) const noexcept override;
			virtual bool isKeyUp(InputKey::Code key) const noexcept override;
			virtual bool isKeyPressed(InputKey::Code key) const noexcept override;

			virtual IInputKeyboardPtr clone() const noexcept override;

		private:
			MSWInputKeyboard(const MSWInputKeyboard&) noexcept = delete;
			MSWInputKeyboard& operator=(const MSWInputKeyboard&) noexcept = delete;
		};
	}
}

#endif