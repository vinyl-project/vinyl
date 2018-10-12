#include "msw_input_image.h"
#include <algorithm>

#define _WidthPitch(w) ((w + w + w + 3) & 0xFFFFFFFC)

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
			{
				*event.color.x = std::numeric_limits<std::uint16_t>::max();
				*event.color.y = std::numeric_limits<std::uint16_t>::max();
			}
			break;
			case InputEvent::FindCenterColor:
			{
				*event.image.x = std::numeric_limits<std::uint16_t>::max();
				*event.image.y = std::numeric_limits<std::uint16_t>::max();
			}
			break;
			case InputEvent::FindPic:
			case InputEvent::Screenshot:
			{
				if (event.shot.pixels)
					CaptureScreen(event.shot.x, event.shot.y, event.shot.w, event.shot.h, event.shot.pixels);
			}
			default:
				break;
			}
		}

		void
		MSWInputImage::CaptureScreen(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* pixels) noexcept
		{
			HWND hwnd = ::GetDesktopWindow();
			HDC hdc1 = ::GetWindowDC(hwnd);
			HDC hdc2 = CreateCompatibleDC(hdc1);

			RECT rect;
			GetClientRect(hwnd, &rect);

			rect.left = std::max<LONG>(x, rect.left);
			rect.top = std::max<LONG>(y, rect.top);
			rect.right = std::min<LONG>(x + w, rect.right);
			rect.bottom = std::min<LONG>(y + h, rect.bottom);

			auto width = rect.right - rect.left;
			auto height = rect.bottom - rect.top;

			auto hBitmap = ::CreateCompatibleBitmap(hdc1, width, height);
			auto hbmpTemp = (HBITMAP)SelectObject(hdc2, hBitmap);

			BitBlt(hdc2, rect.left, rect.top, rect.right, rect.bottom, hdc1, 0, 0, SRCCOPY);

			BITMAPINFOHEADER bihInfo;
			bihInfo.biSize = sizeof(BITMAPINFOHEADER);
			bihInfo.biWidth = width;
			bihInfo.biHeight = height;
			bihInfo.biPlanes = 1;
			bihInfo.biBitCount = 24;
			bihInfo.biCompression = BI_RGB;
			bihInfo.biSizeImage = 0;
			bihInfo.biXPelsPerMeter = 0;
			bihInfo.biYPelsPerMeter = 0;
			bihInfo.biClrUsed = 0;
			bihInfo.biClrImportant = 0;

			pixels_.resize(w * h * 3);

			GetDIBits(hdc2, hBitmap, 0, height, pixels_.data(), (LPBITMAPINFO)&bihInfo, DIB_RGB_COLORS);

			std::memcpy(pixels, pixels_.data(), pixels_.size());

			DeleteDC(hdc2);
		}
	}
}