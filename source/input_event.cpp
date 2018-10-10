#include <vinyl/input_event.h>

namespace vinyl
{
	namespace input
	{
		InputEvent
		InputEvent::makeWindowResize(std::uint32_t w, std::uint32_t h) noexcept
		{
			InputEvent event;
			event.event = InputEvent::SizeChange;
			event.change.w = w;
			event.change.h = h;
			event.change.windowID = 0;
			event.change.timestamp = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowFramebufferResize(std::uint32_t w, std::uint32_t h) noexcept
		{
			InputEvent event;
			event.event = InputEvent::SizeChangeDPI;
			event.change.w = w;
			event.change.h = h;
			event.change.windowID = 0;
			event.change.timestamp = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowClose() noexcept
		{
			InputEvent event;
			event.event = InputEvent::AppQuit;
			event.window.windowID = 0;
			event.window.timestamp = 0;
			return event;
		}

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
		InputEvent::makeWindowKeyPress(InputKey::Code input_key, std::uint16_t scancode, std::uint16_t mods) noexcept
		{
			InputEvent event;
			event.event = InputEvent::KeyDown;
			event.key.windowID = 0;
			event.key.timestamp = 0;
			event.key.padding2 = 0;
			event.key.padding3 = 0;
			event.key.repeat = true;
			event.key.state = false;
			event.key.keysym.raw = scancode;
			event.key.keysym.sym = input_key;
			event.key.keysym.mod = mods;
			event.key.keysym.unicode = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowKeyChar(std::uint16_t unicode, std::uint16_t mods) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Character;
			event.key.windowID = 0;
			event.key.timestamp = 0;
			event.key.padding2 = 0;
			event.key.padding3 = 0;
			event.key.repeat = 0;
			event.key.state = true;
			event.key.keysym.raw = 0;
			event.key.keysym.sym = 0;
			event.key.keysym.mod = mods;
			event.key.keysym.unicode = unicode;
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
		InputEvent::makeWindowMouseMotion(float x, float y) noexcept
		{
			InputEvent event;
			event.event = InputEvent::MouseMotion;
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
		InputEvent::makeWindowScrool(float x, float y) noexcept
		{
			InputEvent event;
			event.event = y > 0 ? InputEvent::MouseWheelUp : InputEvent::MouseWheelDown;
			event.wheel.timestamp = 0;
			event.wheel.windowID = 0;
			return event;
		}

		InputEvent
		InputEvent::makeWindowDrop(std::uint32_t count, const char** file_utf8) noexcept
		{
			InputEvent event;
			event.event = InputEvent::Drop;
			event.drop.timestamp = 0;
			event.drop.count = count;
			event.drop.files = file_utf8;
			event.drop.windowID = 0;
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