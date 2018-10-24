#include "msw_input_image.h"
#include <algorithm>

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

		IInputControllerPtr
		MSWInputImage::clone() const noexcept
		{
			return std::make_shared<MSWInputImage>();
		}

		void 
		MSWInputImage::onFindColor(const ColorEvent& event) noexcept
		{
			if (event.x && event.y)
			{
				*event.x = std::numeric_limits<std::uint16_t>::max();
				*event.y = std::numeric_limits<std::uint16_t>::max();

				auto w = event.w;
				auto h = event.h;
				auto pixels = event.pixels;

				for (std::uint16_t x = 0; x < w; x++)
				{
					for (std::uint16_t y = 0; y < h; y++)
					{
						auto b = pixels[(y * w + x) * 3];
						auto g = pixels[(y * w + x) * 3 + 1];
						auto r = pixels[(y * w + x) * 3 + 2];

						if (r == event.r && g == event.g && b == event.b)
						{
							*event.x = x;
							*event.y = y;

							return;
						}
					}
				}
			}
		}

		void 
		MSWInputImage::onFindColorEx(const ColorEvent& event) noexcept
		{
			this->onFindColor(event);
		}

		void 
		MSWInputImage::onFindCenterColor(const ColorEvent& event) noexcept
		{
			this->onFindColor(event);
		}

		void 
		MSWInputImage::onFindImage(const ImageEvent& event) noexcept
		{
			if (event.x && event.y)
			{
				*event.x = std::numeric_limits<std::uint16_t>::max();
				*event.y = std::numeric_limits<std::uint16_t>::max();

				if (!(event.pixels && event.pattern))
					return;

				std::uint32_t dstGray = 0;

				for (std::uint16_t x = 0; x < event.w2; x++)
				{
					for (std::uint16_t y = 0; y < event.h2; y++)
					{
						auto b = event.pattern[(y * event.w2 + x) * 3];
						auto g = event.pattern[(y * event.w2 + x) * 3 + 1];
						auto r = event.pattern[(y * event.w2 + x) * 3 + 2];

						dstGray += (r * 299 + g * 587 + b * 114 + 500) / 1000;
					}
				}

				for (std::uint16_t x = 0; x < event.w - event.w2; x++)
				{
					for (std::uint16_t y = 0; y < event.h - event.h2; y++)
					{
						std::uint32_t srcGray = 0;

						for (std::uint16_t xx = 0; xx < event.w2; xx++)
						{
							for (std::uint16_t yy = 0; yy < event.h2; yy++)
							{
								auto b = event.pixels[((y + yy) * event.w + (x + xx)) * 3];
								auto g = event.pixels[((y + yy) * event.w + (x + xx)) * 3 + 1];
								auto r = event.pixels[((y + yy) * event.w + (x + xx)) * 3 + 2];

								srcGray += (r * 299 + g * 587 + b * 114 + 500) / 1000;
							}
						}

						if (dstGray == srcGray)
						{
							*event.x = x;
							*event.y = y;

							return;
						}
					}
				}
				
			}
		}

		void 
		MSWInputImage::onScreenshot(const ScreenshotEvent& event) noexcept
		{
			if (!event.pixels)
				return;

			HWND hwnd = event.windowID ? (HWND)event.windowID : GetDesktopWindow();
			HDC hdc1 = ::GetWindowDC(hwnd);
			HDC hdc2 = CreateCompatibleDC(hdc1);

			RECT rect;
			GetClientRect(hwnd, &rect);

			rect.left = std::max<LONG>(event.x, rect.left);
			rect.top = std::max<LONG>(event.y, rect.top);
			rect.right = std::min<LONG>(event.x + event.w, rect.right);
			rect.bottom = std::min<LONG>(event.y + event.h, rect.bottom);

			auto width = rect.right - rect.left;
			auto height = rect.bottom - rect.top;

			auto hBitmap = ::CreateCompatibleBitmap(hdc1, width, height);
			SelectObject(hdc2, hBitmap);

			BitBlt(hdc2, 0, 0, width, height, hdc1, rect.left, rect.top, SRCCOPY);

			BITMAPINFOHEADER bihInfo;
			bihInfo.biSize = sizeof(BITMAPINFOHEADER);
			bihInfo.biWidth = width;
			bihInfo.biHeight = -height;
			bihInfo.biPlanes = 1;
			bihInfo.biBitCount = 24;
			bihInfo.biCompression = BI_RGB;
			bihInfo.biSizeImage = 0;
			bihInfo.biXPelsPerMeter = 0;
			bihInfo.biYPelsPerMeter = 0;
			bihInfo.biClrUsed = 0;
			bihInfo.biClrImportant = 0;

			GetDIBits(hdc2, hBitmap, 0, height, event.pixels, (LPBITMAPINFO)&bihInfo, DIB_RGB_COLORS);

			DeleteDC(hdc2);
		}
	}
}