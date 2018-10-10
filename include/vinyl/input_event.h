#ifndef VINYL_INPUT_EVENT_H_
#define VINYL_INPUT_EVENT_H_

#include <vinyl/input_key.h>
#include <vinyl/input_button.h>

namespace vinyl
{
	namespace input
	{
		struct InputKeysym
		{
			std::uint16_t sym;
			std::uint16_t raw;
			std::uint16_t mod;
			std::uint16_t unicode;
		};

		struct KeyboardEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint8_t state;
			std::uint8_t repeat;
			std::uint8_t padding2;
			std::uint8_t padding3;
			InputKeysym keysym;
		};

		struct MouseMotionEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint8_t state;
			float x;
			float y;
			std::uint32_t xrel;
			std::uint32_t yrel;
		};

		struct MouseButtonEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t which;
			std::uint8_t button;
			std::uint8_t state;
			std::uint8_t clicks;
			std::uint8_t padding1;
			float x;
			float y;
		};

		struct MouseWheelEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
		};

		struct SizeChangeEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t w;
			std::uint32_t h;
		};

		struct WindowEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
		};

		struct ScreenshotEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t x;
			std::uint32_t y;
			std::uint32_t w;
			std::uint32_t h;
		};

		struct DropEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t count;
			const char** files;
		};

		struct JoyAxisEvent {};
		struct JoyBallEvent {};
		struct JoyHatEvent {};
		struct JoyButtonEvent {};
		struct JoyDeviceEvent {};

		class VINYL_EXPORT InputEvent final
		{
		public:
			enum Type
			{
				KeyDown,
				KeyUp,
				Character,

				MouseMove,
				MouseMoveTo,
				MouseButtonDown,
				MouseButtonUp,
				MouseWheelUp,
				MouseWheelDown,

				GamePadButtonDown,
				GamePadButtonUp,

				TouchMotionMove,
				TouchMotionDown,
				TouchMotionUp,
				TouchMotionCancel,

				Screenshot,

				SizeChange,
				SizeChangeDPI,

				GetFocus,
				LostFocus,

				Drop,

				Reset,

				AppQuit
			};

			Type event;

			union
			{
				KeyboardEvent key;
				MouseMotionEvent motion;
				MouseButtonEvent button;
				MouseWheelEvent wheel;
				JoyAxisEvent jaxis;
				JoyBallEvent jball;
				JoyHatEvent  jhat;
				JoyButtonEvent jbutton;
				JoyDeviceEvent jdevice;
				SizeChangeEvent change;
				WindowEvent window;
				DropEvent drop;
				ScreenshotEvent shot;
			};

			static InputEvent makeWindowResize(std::uint32_t w, std::uint32_t h) noexcept;
			static InputEvent makeWindowFramebufferResize(std::uint32_t w, std::uint32_t h) noexcept;
			static InputEvent makeWindowClose() noexcept;
			static InputEvent makeWindowFocus(bool focus) noexcept;
			static InputEvent makeWindowKeyDown(InputKey::Code key, std::uint16_t scancode = 0, std::uint16_t mods = 0) noexcept;
			static InputEvent makeWindowKeyUp(InputKey::Code key, std::uint16_t scancode = 0, std::uint16_t mods = 0) noexcept;
			static InputEvent makeWindowKeyPress(InputKey::Code key, std::uint16_t scancode = 0, std::uint16_t mods = 0) noexcept;
			static InputEvent makeWindowKeyChar(std::uint16_t unicode, std::uint16_t mods) noexcept;
			static InputEvent makeWindowMouseButtonDown(InputButton::Code button, float x, float y) noexcept;
			static InputEvent makeWindowMouseButtonUp(InputButton::Code button, float x, float y) noexcept;
			static InputEvent makeWindowMouseMove(float x, float y) noexcept;
			static InputEvent makeWindowMouseMoveTo(float x, float y) noexcept;
			static InputEvent makeWindowScrool(float x, float y) noexcept;
			static InputEvent makeWindowDrop(std::uint32_t count, const char** file_utf8) noexcept;
			static InputEvent makeScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h) noexcept;
		};
	}
}

#endif