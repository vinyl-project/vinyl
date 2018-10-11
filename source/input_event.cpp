#include <vinyl/input_event.h>

namespace vinyl
{
	namespace input
	{
		InputEvent
		InputEvent::makeWindowFocus(bool focus) noexcept
		{
			InputEvent event;
			event.event = focus ? InputEvent::GetFocus : InputEvent::LostFocus;
			event.window.windowID = 0;
			event.window.timestamp = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowKeyDown(InputKey::Code input_key, std::uint16_t scancode, std::uint16_t mods) noexcept
		{
			InputEvent event;
			event.event = InputEvent::KeyDown;
			event.key.windowID = 0;
			event.key.timestamp = 0;
			event.key.padding2 = 0;
			event.key.padding3 = 0;
			event.key.repeat = false;
			event.key.state = true;
			event.key.keysym.raw = scancode;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = mods;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowKeyUp(InputKey::Code input_key, std::uint16_t scancode, std::uint16_t mods) noexcept
		{
			InputEvent event;
			event.event = InputEvent::KeyUp;
			event.key.windowID = 0;
			event.key.timestamp = 0;
			event.key.padding2 = 0;
			event.key.padding3 = 0;
			event.key.repeat = false;
			event.key.state = false;
			event.key.keysym.raw = scancode;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = mods;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowWaitKey(InputKey::Code input_key) noexcept
		{
			InputEvent event;
			event.event = InputEvent::WaitKey;
			event.key.windowID = 0;
			event.key.timestamp = 0;
			event.key.padding2 = 0;
			event.key.padding3 = 0;
			event.key.repeat = 0;
			event.key.state = true;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = input_key;

			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseButtonDown(InputButton::Code input_button, float x, float y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseButtonDown;
			event.button.button = input_button;
			event.button.clicks = true;
			event.button.x = x;
			event.button.y = y;
			event.button.timestamp = 0;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseButtonUp(InputButton::Code input_button, float x, float y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseButtonUp;
			event.button.button = input_button;
			event.button.clicks = false;
			event.button.x = x;
			event.button.y = y;
			event.button.timestamp = 0;
			event.button.windowID = 0;
			event.button.padding1 = 0;
			event.button.which = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseMove(float x, float y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseMove;
			event.motion.x = x;
			event.motion.y = y;
			event.motion.xrel = (std::uint32_t)x;
			event.motion.yrel = (std::uint32_t)y;
			event.motion.timestamp = 0;
			event.motion.state = false;
			event.motion.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseMoveTo(float x, float y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseMoveTo;
			event.motion.x = x;
			event.motion.y = y;
			event.motion.xrel = (std::uint32_t)x;
			event.motion.yrel = (std::uint32_t)y;
			event.motion.timestamp = 0;
			event.motion.state = false;
			event.motion.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseWheelUp() noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseWheelUp;
			event.wheel.timestamp = 0;
			event.wheel.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowMouseWheelDown() noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseWheelDown;
			event.wheel.timestamp = 0;
			event.wheel.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeSleep(std::uint32_t ms) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Sleep;
			event.sleep.timestamp = 0;
			event.sleep.milliseconds = ms;
			return event;
		}

		InputEvent
		InputEvent::makeMessageBox(const char* message) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Alert;
			event.message.timestamp = 0;
			event.message.message = message;
			return event;
		}

		InputEvent
		InputEvent::makeTracePrint(std::uint8_t enable) noexcept
		{
			InputEvent event;
			event.event = InputEvent::TracePrint;
			event.debug.timestamp = 0;
			event.debug.trace = enable;
			return event;
		}

		InputEvent
		InputEvent::makeScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Screenshot;
			event.shot.windowID = 0;
			event.shot.timestamp = 0;
			event.shot.x = x;
			event.shot.y = y;
			event.shot.w = w;
			event.shot.h = h;
			return event;
		}
	}
}