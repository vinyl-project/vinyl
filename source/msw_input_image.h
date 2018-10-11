#ifndef VINYL_MSW_INPUT_IMAGE_H_
#define VINYL_MSW_INPUT_IMAGE_H_

#include <vinyl/input_image.h>
#include <vector>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT MSWInputImage final : public InputImage
		{
		public:
			MSWInputImage() noexcept;
			virtual ~MSWInputImage() noexcept;

			virtual IInputImagePtr clone() const noexcept;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

		private:
			void CaptureScreen() noexcept;

		private:
			MSWInputImage(const MSWInputImage&) noexcept = delete;
			MSWInputImage& operator=(const MSWInputImage&) noexcept = delete;

		private:
			std::uint32_t width_;
			std::uint32_t height_;
			std::vector<std::uint8_t> pixels_;
		};
	}
}

#endif