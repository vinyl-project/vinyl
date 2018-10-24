#include <vinyl/input_image.h>
#include <cstring> // std::memset

namespace vinyl
{
	namespace input
	{
		InputImage::InputImage() noexcept
		{
		}

		InputImage::~InputImage() noexcept
		{
		}

		IInputControllerPtr
		InputImage::clone() const noexcept
		{
			return std::make_shared<InputImage>();
		}

		void
		InputImage::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::FindColor:
				this->onFindColor(event.color);
				break;
			case InputEvent::FindColorEx:
				this->onFindColorEx(event.color);
				break;
			case InputEvent::FindCenterColor:
				this->onFindCenterColor(event.color);
				break;
			case InputEvent::FindPic:
				this->onFindImage(event.image);
				break;
			case InputEvent::Screenshot:
				this->onScreenshot(event.shot);
				break;
			default:
				break;
			}

			return;
		}

		void
		InputImage::onFindColor(const ColorEvent& event) noexcept
		{			
		}

		void
		InputImage::onFindColorEx(const ColorEvent& event) noexcept
		{			
		}

		void
		InputImage::onFindCenterColor(const ColorEvent& event) noexcept
		{			
		}

		void
		InputImage::onFindImage(const ImageEvent& event) noexcept
		{			
		}

		void
		InputImage::onScreenshot(const ScreenshotEvent& event) noexcept
		{			
		}

	}
}