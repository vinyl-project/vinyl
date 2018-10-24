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

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

			virtual void onFindColor(const ColorEvent& event) noexcept;
			virtual void onFindColorEx(const ColorEvent& event) noexcept;
			virtual void onFindCenterColor(const ColorEvent& event) noexcept;
			virtual void onFindImage(const ImageEvent& event) noexcept;

			virtual void onScreenshot(const ScreenshotEvent& event) noexcept;

		private:
			InputImage(const InputImage&) noexcept = delete;
			InputImage& operator=(const InputImage&) noexcept = delete;
		};
	}
}

#endif