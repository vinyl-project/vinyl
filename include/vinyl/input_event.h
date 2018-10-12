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
			std::uint8_t* state;
			std::uint8_t repeat;
			std::uint8_t padding2;
			std::uint8_t padding3;
			std::uint32_t delay;
			InputKeysym keysym;
		};

		struct MouseMotionEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint8_t state;
			std::uint32_t x;
			std::uint32_t y;
			std::uint32_t delay;
		};

		struct MouseButtonEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t which;
			std::uint8_t button;
			std::uint8_t* state;
			std::uint8_t clicks;
			std::uint8_t padding1;
			std::uint32_t delay;
			float x;
			float y;
		};

		struct MouseWheelEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t delay;
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

		struct ColorEvent
		{
			std::uint64_t timestamp;
			std::uint32_t color;
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

		struct DebugEvent
		{
			std::uint64_t timestamp;
			std::uint8_t trace;
		};

		struct ScreenshotEvent
		{
			std::uint64_t timestamp;
			std::uint64_t windowID;
			std::uint32_t x;
			std::uint32_t y;
			std::uint32_t w;
			std::uint32_t h;
			std::uint8_t* pixels;
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

				IsKeyDown,
				IsKeyUp,
				IsMouseButtonDown,
				IsMouseButtonUp,

				LockMouse,
				UnlockMouse,
				WaitMouse,

				FindColor,
				FindColorEx,
				FindCenterColor,
				FinxPic,

				GamePadButtonDown,
				GamePadButtonUp,

				TouchMotionMove,
				TouchMotionDown,
				TouchMotionUp,
				TouchMotionCancel,

				Sleep,
				Alert,
				TracePrint,
				Command,

				Screenshot,

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
				ColorEvent color;
				SleepEvent sleep;
				MessageEvent message;
				DebugEvent debug;
				WindowEvent window;
				ScreenshotEvent shot;
			};

			static InputEvent makeWindowFocus(bool focus) noexcept;
			static InputEvent makeWindowKeyDown(InputKey::Code key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowKeyUp(InputKey::Code key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowIsKeyDown(InputKey::Code key, std::uint8_t* state) noexcept;
			static InputEvent makeWindowIsKeyUp(InputKey::Code key, std::uint8_t* state) noexcept;
			static InputEvent makeWindowWaitKey(InputKey::Code key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseButtonDown(InputButton::Code button, float x, float y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseButtonUp(InputButton::Code button, float x, float y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowIsMouseButtonDown(InputButton::Code key, std::uint8_t* state) noexcept;
			static InputEvent makeWindowIsMouseButtonUp(InputButton::Code key, std::uint8_t* state) noexcept;
			static InputEvent makeWindowWaitButton(InputButton::Code key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseMove(float x, float y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseMoveTo(float x, float y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseWheelUp(std::uint32_t delay = 10) noexcept;
			static InputEvent makeWindowMouseWheelDown(std::uint32_t delay = 10) noexcept;
			static InputEvent makeSleep(std::uint32_t milliseconds) noexcept;
			static InputEvent makeMessageBox(const char* message) noexcept;
			static InputEvent makeTracePrint(std::uint8_t enable) noexcept;
			static InputEvent makeCommand(const char* message) noexcept;
			static InputEvent makeScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept;
		};
	}
}

#endif