#ifndef VINYL_IINPUT_IMAGE_H_
#define VINYL_IINPUT_IMAGE_H_

#include <vinyl/input_controller.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT IInputImage : public InputController
		{
		public:
			IInputImage() noexcept = default;
			virtual ~IInputImage() = default;

		private:
			IInputImage(const IInputImage&) noexcept = delete;
			IInputImage& operator=(const IInputImage&) noexcept = delete;
		};
	}
}

#endif