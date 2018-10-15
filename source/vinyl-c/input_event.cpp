#include <vinyl/input_event.h>

namespace vinyl
{
	namespace input
	{
		InputEvent
		InputEvent::makeFocus(bool focus) noexcept
		{
			InputEvent event;
			event.event = focus ? InputEvent::ObtainCapture : InputEvent::LostCapture;
			event.window.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeKeyDown(InputKey::Code input_key, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::KeyDown;
			event.key.windowID = 0;
			event.key.state = nullptr;
			event.key.delay = delay;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = 0;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeKeyUp(InputKey::Code input_key, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::KeyUp;
			event.key.windowID = 0;
			event.key.state = nullptr;
			event.key.delay = delay;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = 0;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeIsKeyDown(InputKey::Code input_key, std::uint8_t& state) noexcept
		{
			InputEvent event;
			event.event = InputEvent::IsKeyDown;
			event.key.windowID = 0;
			event.key.state = &state;
			event.key.delay = 0;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = 0;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeIsKeyUp(InputKey::Code input_key, std::uint8_t& state) noexcept
		{
			InputEvent event;
			event.event = InputEvent::IsKeyUp;
			event.key.windowID = 0;
			event.key.state = &state;
			event.key.delay = 0;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = 0;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWaitKey(InputKey::Code& input_key, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::WaitKey;
			event.waitKey.delay = delay;
			event.waitKey.key = &input_key;

			return event;
		}

		InputEvent
		InputEvent::makeMouseButtonDown(InputButton::Code input_button, std::uint32_t x, std::uint32_t y, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseButtonDown;
			event.button.button = input_button;
			event.button.clicks = true;
			event.button.x = x;
			event.button.y = y;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			event.button.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeMouseButtonUp(InputButton::Code input_button, std::uint32_t x, std::uint32_t y, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseButtonUp;
			event.button.button = input_button;
			event.button.clicks = false;
			event.button.x = x;
			event.button.y = y;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			event.button.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeIsMouseButtonDown(InputButton::Code input_button, std::uint8_t& state) noexcept
		{
			InputEvent event;
			event.event = InputEvent::IsMouseButtonDown;
			event.button.button = input_button;
			event.button.clicks = true;
			event.button.state = &state;
			event.button.x = 0;
			event.button.y = 0;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			event.button.delay = 0;
			return event;
		}

		InputEvent
		InputEvent::makeIsMouseButtonUp(InputButton::Code input_button, std::uint8_t& state) noexcept
		{
			InputEvent event;
			event.event = InputEvent::IsMouseButtonUp;
			event.button.button = input_button;
			event.button.clicks = false;
			event.button.state = &state;
			event.button.x = 0;
			event.button.y = 0;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			event.button.delay = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWaitButton(InputButton::Code& input_button, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::WaitButton;
			event.waitButton.delay = delay;
			event.waitButton.button = &input_button;

			return event;
		}

		InputEvent
		InputEvent::makeMouseMove(std::uint32_t x, std::uint32_t y, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseMove;
			event.motion.x = (std::uint32_t)x;
			event.motion.y = (std::uint32_t)y;
			event.motion.state = false;
			event.motion.windowID = 0;
			event.motion.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeMouseMoveTo(std::uint32_t x, std::uint32_t y, std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseMoveTo;
			event.motion.x = (std::uint32_t)x;
			event.motion.y = (std::uint32_t)y;
			event.motion.state = false;
			event.motion.windowID = 0;
			event.motion.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeMouseWheelUp(std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseWheelUp;
			event.wheel.windowID = 0;
			event.wheel.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeMouseWheelDown(std::uint32_t delay) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseWheelDown;
			event.wheel.windowID = 0;
			event.wheel.delay = delay;
			return event;
		}

		InputEvent
		InputEvent::makeGetMousePos(std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::GetMousePos;
			event.pos.windowID = 0;
			event.pos.x = &x;
			event.pos.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeGetWindowPos(std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::GetWindowPos;
			event.pos.windowID = 0;
			event.pos.x = &x;
			event.pos.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeGetWindowSize(std::uint16_t& w, std::uint16_t& h) noexcept
		{
			InputEvent event;
			event.event = InputEvent::GetWindowSize;
			event.size.windowID = 0;
			event.size.w = &w;
			event.size.h = &h;
			return event;
		}

		InputEvent
		InputEvent::makeSleep(std::uint32_t ms) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Sleep;
			event.sleep.milliseconds = ms;
			return event;
		}

		InputEvent
		InputEvent::makeMessageBox(const char* message) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Alert;
			event.message.message = message;
			return event;
		}

		InputEvent
		InputEvent::makeSayString(const char* message) noexcept
		{
			InputEvent event;
			event.event = InputEvent::SayString;
			event.message.message = message;
			return event;
		}

		InputEvent
		InputEvent::makeTracePrint(std::uint8_t enable) noexcept
		{
			InputEvent event;
			event.event = InputEvent::TracePrint;
			event.debug.trace = enable;
			return event;
		}

		InputEvent
		InputEvent::makeCommand(const char* cmd) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Command;
			event.message.message = cmd;
			return event;
		}

		InputEvent
		InputEvent::makeFindColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::FindColor;
			event.color.r = r;
			event.color.g = g;
			event.color.b = b;
			event.color.x = &x;
			event.color.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeFindColorEx(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::FindColorEx;
			event.color.r = r;
			event.color.g = g;
			event.color.b = b;
			event.color.x = &x;
			event.color.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeFindCenterColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::FindCenterColor;
			event.color.r = r;
			event.color.g = g;
			event.color.b = b;
			event.color.x = &x;
			event.color.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeFindImage(std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint16_t& x, std::uint16_t& y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::FindPic;
			event.image.w = w;
			event.image.h = h;
			event.image.pixels = image;
			event.image.x = &x;
			event.image.y = &y;
			return event;
		}

		InputEvent
		InputEvent::makeScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Screenshot;
			event.shot.windowID = 0;
			event.shot.x = x;
			event.shot.y = y;
			event.shot.w = w;
			event.shot.h = h;
			event.shot.pixels = data;
			return event;
		}
	}
}