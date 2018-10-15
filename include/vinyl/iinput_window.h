#ifndef VINYL_IINPUT_WINDOW_H_
#define VINYL_IINPUT_WINDOW_H_

#include <vinyl/input_controller.h>
#include <vinyl/input_button.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputWindow : public InputController
		{
		public:
			IInputWindow() noexcept = default;
			virtual ~IInputWindow() = default;

		private:
			IInputWindow(const IInputWindow&) noexcept = delete;
			IInputWindow& operator=(const IInputWindow&) noexcept = delete;
		};
	}
}

#endif