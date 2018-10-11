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

		struct SleepEvent
		{
			std::uint64_t timestamp;
			std::uint32_t milliseconds;
		};

		struct MessageEvent
		{
			std::uint64_t timestamp;
			const char* message;
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
				WaitKey,
				GetLastKey,
				SetSimMode,

				MouseMove,
				MouseMoveTo,
				MouseButtonDown,
				MouseButtonUp,
				MouseWheelUp,
				MouseWheelDown,

				LockMouse,
				UnlockMouse,
				WaitMouse,

				GamePadButtonDown,
				GamePadButtonUp,

				TouchMotionMove,
				TouchMotionDown,
				TouchMotionUp,
				TouchMotionCancel,

				Sleep,
				Alert,

				Screenshot,

				SizeChange,
				SizeChangeDPI,

				GetFocus,
				LostFocus,

				Reset
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
				SleepEvent sleep;
				MessageEvent message;
				WindowEvent window;
				ScreenshotEvent shot;
			};

			static InputEvent makeWindowFocus(bool focus) noexcept;
			static InputEvent makeWindowKeyDown(InputKey::Code key, std::uint16_t scancode = 0, std::uint16_t mods = 0) noexcept;
			static InputEvent makeWindowKeyUp(InputKey::Code key, std::uint16_t scancode = 0, std::uint16_t mods = 0) noexcept;
			static InputEvent makeWindowWaitKey(InputKey::Code key) noexcept;
			static InputEvent makeWindowMouseButtonDown(InputButton::Code button, float x, float y) noexcept;
			static InputEvent makeWindowMouseButtonUp(InputButton::Code button, float x, float y) noexcept;
			static InputEvent makeWindowMouseMove(float x, float y) noexcept;
			static InputEvent makeWindowMouseMoveTo(float x, float y) noexcept;
			static InputEvent makeWindowMouseWheelUp() noexcept;
			static InputEvent makeWindowMouseWheelDown() noexcept;
			static InputEvent makeSleep(std::uint32_t milliseconds) noexcept;
			static InputEvent makeMessageBox(const char* message) noexcept;
			static InputEvent makeScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h) noexcept;
		};
	}
}

#endif