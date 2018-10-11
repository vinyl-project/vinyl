#ifndef VINYL_IINPUT_DEBUG_H_
#define VINYL_IINPUT_DEBUG_H_

#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputDebug : public InputController
		{
		public:
			IInputDebug() noexcept = default;
			virtual ~IInputDebug() = default;

			virtual IInputDebugPtr clone() const noexcept = 0;

		private:
			IInputDebug(const IInputDebug&) noexcept = delete;
			IInputDebug& operator=(const IInputDebug&) noexcept = delete;
		};
	}
}

#endif