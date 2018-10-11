#include "msw_input_image.h"

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
			case InputEvent::FindCenterColor:
			case InputEvent::FinxPic:
			default:
				break;
			}
		}

		void
		MSWInputImage::CaptureScreen() noexcept
		{
			RECT rect;
			GetClientRect(GetDesktopWindow(), &rect);

			auto hdcSrc = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
			auto hdc = CreateCompatibleDC(hdcSrc);
			auto hBitmap = CreateCompatibleBitmap(hdcSrc, rect.right, rect.bottom);
			auto hbmpTemp = (HBITMAP)SelectObject(hdc, hBitmap);

			BitBlt(hdc, 0, 0, rect.right, rect.bottom, hdcSrc, 0, 0, SRCCOPY);
			SelectObject(hdc, hbmpTemp);

			BITMAP bmBitmap;
			GetObject(hBitmap, sizeof(BITMAP), &bmBitmap);

			BITMAPINFOHEADER bihInfo;
			bihInfo.biSize = sizeof(BITMAPINFOHEADER);
			bihInfo.biWidth = bmBitmap.bmWidth;
			bihInfo.biHeight = bmBitmap.bmHeight;
			bihInfo.biPlanes = 1;
			bihInfo.biBitCount = 24;
			bihInfo.biCompression = BI_RGB;
			bihInfo.biSizeImage = _WidthPitch(bmBitmap.bmWidth) * bmBitmap.bmHeight;
			bihInfo.biXPelsPerMeter = 0;
			bihInfo.biYPelsPerMeter = 0;
			bihInfo.biClrUsed = 0;
			bihInfo.biClrImportant = 0;

			GetDIBits(hdcSrc, hBitmap, 0, rect.bottom - rect.top, pixels_.data(), (LPBITMAPINFO)&bihInfo, DIB_RGB_COLORS);
		}
	}
}