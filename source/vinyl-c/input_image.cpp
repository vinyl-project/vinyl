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
	}
}