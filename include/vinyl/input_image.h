#ifndef VINYL_INPUT_IMAGE_H_
#define VINYL_INPUT_IMAGE_H_

#include <vinyl/iinput_image.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputImage : public IInputImage
		{
		public:
			InputImage() noexcept;
			virtual ~InputImage() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		private:
			InputImage(const InputImage&) noexcept = delete;
			InputImage& operator=(const InputImage&) noexcept = delete;
		};
	}
}

#endif