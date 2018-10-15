#ifndef VINYL_INPUT_WINDOW_H_
#define VINYL_INPUT_WINDOW_H_

#include <vinyl/iinput_window.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputWindow : public IInputWindow
		{
		public:
			InputWindow() noexcept;
			virtual ~InputWindow() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		private:
			InputWindow(const InputWindow&) noexcept = delete;
			InputWindow& operator=(const InputWindow&) noexcept = delete;
		};
	}
}

#endif