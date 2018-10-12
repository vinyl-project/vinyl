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
			{
				if (event.color.x && event.color.y)
				{
					this->CaptureScreen(0, 0, std::numeric_limits<std::uint16_t>::max(), std::numeric_limits<std::uint16_t>::max(), nullptr);

					*event.color.x = std::numeric_limits<std::uint16_t>::max();
					*event.color.y = std::numeric_limits<std::uint16_t>::max();

					for (std::uint16_t x = 0; x < width_; x++)
					{
						for (std::uint16_t y = 0; y < height_; y++)
						{
							auto r = pixels_[(y * width_ + x) * 3];
							auto g = pixels_[(y * width_ + x) * 3 + 1];
							auto b = pixels_[(y * width_ + x) * 3 + 2];

							if (r == event.color.r && r == event.color.g && r == event.color.b)
							{
								*event.color.x = x;
								*event.color.y = y;
							}
						}
					}
				}
			}
			break;
			case InputEvent::FindColorEx:
			{
				if (event.color.x && event.color.y)
				{
					this->CaptureScreen(0, 0, std::numeric_limits<std::uint16_t>::max(), std::numeric_limits<std::uint16_t>::max(), nullptr);

					*event.color.x = std::numeric_limits<std::uint16_t>::max();
					*event.color.y = std::numeric_limits<std::uint16_t>::max();

					for (std::uint16_t x = width_ - 1; x > 0; x++)
					{
						for (std::uint16_t y = height_ - 1; y > 0; y++)
						{
							auto r = pixels_[(y * width_ + x) * 3];
							auto g = pixels_[(y * width_ + x) * 3 + 1];
							auto b = pixels_[(y * width_ + x) * 3 + 2];

							if (r == event.color.r && r == event.color.g && r == event.color.b)
							{
								*event.color.x = x;
								*event.color.y = y;
							}
						}
					}
				}
			}
			break;
			case InputEvent::FindCenterColor:
			{
				if (event.color.x && event.color.y)
				{
					this->CaptureScreen(0, 0, std::numeric_limits<std::uint16_t>::max(), std::numeric_limits<std::uint16_t>::max(), nullptr);

					*event.color.x = std::numeric_limits<std::uint16_t>::max();
					*event.color.y = std::numeric_limits<std::uint16_t>::max();

					std::uint32_t row = width_ * 3;

					for (std::uint16_t x = 0; x < width_; x++)
					{
						for (std::uint16_t y = 0; y < height_; y++)
						{
							auto r = pixels_[(y * width_ + x) * 3];
							auto g = pixels_[(y * width_ + x) * 3 + 1];
							auto b = pixels_[(y * width_ + x) * 3 + 2];

							if (r == event.color.r && r == event.color.g && r == event.color.b)
							{
								*event.color.x = x;
								*event.color.y = y;
							}
						}
					}
				}
			}
			break;
			case InputEvent::FindPic:
			{
				if (event.image.x && event.image.y)
				{
					*event.image.x = std::numeric_limits<std::uint16_t>::max();
					*event.image.y = std::numeric_limits<std::uint16_t>::max();

					if (event.image.pixels)
					{
						this->CaptureScreen(0, 0, std::numeric_limits<std::uint16_t>::max(), std::numeric_limits<std::uint16_t>::max(), nullptr);

						std::uint32_t dstGray = 0;

						for (std::uint16_t x = 0; x < event.image.w; x++)
						{
							for (std::uint16_t y = 0; y < event.image.h; y++)
							{
								auto r = event.image.pixels[(y * event.image.w + x) * 3];
								auto g = event.image.pixels[(y * event.image.w + x) * 3 + 1];
								auto b = event.image.pixels[(y * event.image.w + x) * 3 + 2];

								dstGray += (r * 299 + g * 587 + b * 114 + 500) / 1000;
							}
						}

						for (std::uint16_t x = 0; x < width_ - event.image.w; x++)
						{
							for (std::uint16_t y = 0; y < height_ - event.image.h; y++)
							{
								std::uint32_t srcGray = 0;

								for (std::uint16_t xx = 0; xx < event.image.w; xx++)
								{
									for (std::uint16_t yy = 0; yy < event.image.h; yy++)
									{
										auto r = pixels_[((y + yy) * width_ + (x + xx)) * 3];
										auto g = pixels_[((y + yy) * width_ + (x + xx)) * 3 + 1];
										auto b = pixels_[((y + yy) * width_ + (x + xx)) * 3 + 2];

										srcGray += (r * 299 + g * 587 + b * 114 + 500) / 1000;
									}
								}

								if (dstGray == srcGray)
								{
									*event.color.x = x;
									*event.color.y = y;
								}
							}
						}
					}

				}
			}
			break;
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

			auto width = width_ = rect.right - rect.left;
			auto height = height_ = rect.bottom - rect.top;

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

			if (pixels)
				std::memcpy(pixels, pixels_.data(), pixels_.size());

			DeleteDC(hdc2);
		}
	}
}