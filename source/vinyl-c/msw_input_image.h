#ifndef VINYL_MSW_INPUT_IMAGE_H_
#define VINYL_MSW_INPUT_IMAGE_H_

#include <vinyl/input_image.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputImage final : public InputImage
		{
		public:
			MSWInputImage() noexcept;
			virtual ~MSWInputImage() noexcept;

			virtual IInputControllerPtr clone() const noexcept;

		protected:
			virtual void onFindColor(const ColorEvent& event) noexcept override;
			virtual void onFindColorEx(const ColorEvent& event) noexcept override;
			virtual void onFindCenterColor(const ColorEvent& event) noexcept override;
			virtual void onFindImage(const ImageEvent& event) noexcept override;

			virtual void onScreenshot(const ScreenshotEvent& event) noexcept override;

		private:
			MSWInputImage(const MSWInputImage&) noexcept = delete;
			MSWInputImage& operator=(const MSWInputImage&) noexcept = delete;
		};
	}
}

#endif