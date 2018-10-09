#ifndef VINYL_INPUT_NDK_MOUSE_H_
#define VINYL_INPUT_NDK_MOUSE_H_

#include <vinyl/input_mouse.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT NDKInputTouch : public DefaultInputMouse
		{
		public:
			NDKInputTouch() noexcept;
			virtual ~NDKInputTouch() noexcept;

			virtual void showMouse() noexcept;
			virtual void hideMouse() noexcept;

			virtual void setPosition(int x, int y) noexcept;

			virtual int getPositionX() const noexcept;
			virtual int getPositionY() const noexcept;
		};
	}
}

#endif