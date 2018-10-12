#ifndef VINYL_INPUT_NDK_KEYBOARD_H_
#define VINYL_INPUT_NDK_KEYBOARD_H_

#include <vinyl/input_key.h>
#include <vinyl/input_keyboard.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT NDKInputKeyboard : public InputKeyboard
		{
		public:
			NDKInputKeyboard() noexcept;
			virtual ~NDKInputKeyboard() noexcept;

			virtual bool getKeyState(InputKey::Code key) const noexcept;

		private:
			NDKInputKeyboard(const NDKInputKeyboard&) noexcept = delete;
			NDKInputKeyboard& operator=(const NDKInputKeyboard&) noexcept = delete;
		};
	}
}

#endif