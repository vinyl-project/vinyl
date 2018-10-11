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

		IInputImagePtr
		InputImage::clone() const noexcept
		{
			return std::make_shared<InputImage>();
		}

		void
		InputImage::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::GetFocus:
				this->obtainCaptures();
				break;
			case InputEvent::LostFocus:
				this->releaseCapture();
				break;
			case InputEvent::Reset:
				this->reset();
				break;
			default:
				break;
			}
		}
	}
}