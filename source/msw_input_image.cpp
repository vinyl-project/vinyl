#include "msw_input_image.h"

namespace vinyl
{
	namespace input
	{
		MSWInputImage::MSWInputImage() noexcept
		{
		}

		MSWInputImage::~MSWInputImage() noexcept
		{
		}

		IInputImagePtr
		MSWInputImage::clone() const noexcept
		{
			return std::make_shared<MSWInputImage>();
		}

		void
		MSWInputImage::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::FindColor:
			case InputEvent::FindColorEx:
			case InputEvent::FindCenterColor:
			case InputEvent::FinxPic:
			default:
				break;
			}
		}
	}
}