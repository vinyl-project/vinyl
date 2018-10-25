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
			std::uint64_t windowID;
			std::uint8_t* state;
			std::uint32_t delay;
			InputKeysym keysym;
		};

		struct WaitKeyEvent
		{
			std::uint64_t windowID;
			std::uint32_t delay;
			InputKey::Code* key;
		};

		struct WaitButtonEvent
		{
			std::uint64_t windowID;
			std::uint32_t delay;
			InputButton::Code* button;
		};

		struct MouseMotionEvent
		{
			std::uint64_t windowID;
			std::uint8_t state;
			std::int32_t x;
			std::int32_t y;
			std::uint32_t delay;
		};

		struct MouseButtonEvent
		{
			std::uint64_t windowID;
			std::uint32_t which;
			std::uint8_t button;
			std::uint8_t* state;
			std::uint8_t clicks;
			std::uint8_t padding1;
			std::uint32_t delay;
			std::uint32_t x;
			std::uint32_t y;
		};

		struct MouseWheelEvent
		{
			std::uint64_t windowID;
			std::uint32_t delay;
		};

		struct PosEvent
		{
			std::uint64_t windowID;
			std::int16_t* x;
			std::int16_t* y;
		};

		struct SizeEvent
		{
			std::uint64_t windowID;
			std::uint16_t* w;
			std::uint16_t* h;
		};

		struct WindowEvent
		{
			std::uint64_t windowID;
			const char* output;
		};

		struct ColorEvent
		{
			std::uint8_t r;
			std::uint8_t g;
			std::uint8_t b;
			std::uint16_t* x;
			std::uint16_t* y;
			std::uint16_t w;
			std::uint16_t h;
			const std::uint8_t* pixels;
		};

		struct ImageEvent
		{
			std::uint32_t color;
			std::uint32_t w;
			std::uint32_t h;
			std::uint32_t w2;
			std::uint32_t h2;
			std::uint16_t* x;
			std::uint16_t* y;
			const std::uint8_t* pixels;
			const std::uint8_t* pattern;
		};

		struct SleepEvent
		{
			std::uint32_t milliseconds;
		};

		struct MessageEvent
		{
			std::uint64_t windowID;
			const char* message;
		};

		struct DebugEvent
		{
			std::uint8_t trace;
		};

		struct FindWindowEvent
		{
			std::uint32_t x;
			std::uint32_t y;
			const char* str;
			WindHandle* windowID;
		};

		struct RecordEvent
		{
			const char* filepath;
		};

		struct ScreenshotEvent
		{
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

				WaitKey,
				WaitButton,

				FindColor,
				FindColorEx,
				FindCenterColor,
				FindPic,

				NewWindow,

				FindWindowFromPos,
				FindWindowFromTitle,
				FindWindowFromClassName,

				GetMousePos,

				GetWindowPos,
				GetWindowSize,
				GetWindowTitle,
				GetWindowClassName,

				Sleep,
				Alert,
				Command,
				SayString,

				Screenshot,

				StartRecord,
				PauseRecord,
				StopRecord,

				ObtainCapture,
				LostCapture,

				Reset
			};

			Type event;

			union
			{
				KeyboardEvent key;
				MouseMotionEvent motion;
				MouseButtonEvent button;
				MouseWheelEvent wheel;
				WaitKeyEvent waitKey;
				WaitButtonEvent waitButton;
				PosEvent pos;
				SizeEvent size;
				JoyAxisEvent jaxis;
				JoyBallEvent jball;
				JoyHatEvent  jhat;
				JoyButtonEvent jbutton;
				JoyDeviceEvent jdevice;
				ColorEvent color;
				ImageEvent image;
				SleepEvent sleep;
				RecordEvent record;
				MessageEvent message;
				DebugEvent debug;
				WindowEvent window;
				FindWindowEvent handle;
				ScreenshotEvent shot;
			};

			static InputEvent makeNewWindow(const char* path, WindHandle& win) noexcept;

			static InputEvent makeFindWindowFromPos(std::uint32_t x, std::uint32_t y, WindHandle& win) noexcept;
			static InputEvent makeFindWindowFromTitle(const char* tile, WindHandle& win) noexcept;
			static InputEvent makeFindWindowFromClassName(const char* classname, WindHandle& win) noexcept;

			static InputEvent makeKeyDown(WindHandle win, InputKey::Code key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeKeyUp(WindHandle win, InputKey::Code key, std::uint32_t delay = 10) noexcept;

			static InputEvent makeMouseButtonDown(WindHandle win, InputButton::Code button, std::uint32_t x, std::uint32_t y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeMouseButtonUp(WindHandle win, InputButton::Code button, std::uint32_t x, std::uint32_t y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeMouseMove(WindHandle win, std::int32_t x, std::int32_t y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeMouseMoveTo(WindHandle win, std::int32_t x, std::int32_t y, std::uint32_t delay = 10) noexcept;
			static InputEvent makeMouseWheelUp(WindHandle win, std::uint32_t delay = 10) noexcept;
			static InputEvent makeMouseWheelDown(WindHandle win, std::uint32_t delay = 10) noexcept;

			static InputEvent makeWaitKey(WindHandle win, InputKey::Code& key, std::uint32_t delay = 10) noexcept;
			static InputEvent makeWaitButton(WindHandle win, InputButton::Code& key, std::uint32_t delay = 10) noexcept;

			static InputEvent makeIsKeyDown(WindHandle win, InputKey::Code key, std::uint8_t& state) noexcept;
			static InputEvent makeIsKeyUp(WindHandle win, InputKey::Code key, std::uint8_t& state) noexcept;
			static InputEvent makeIsMouseButtonDown(WindHandle win, InputButton::Code key, std::uint8_t& state) noexcept;
			static InputEvent makeIsMouseButtonUp(WindHandle win, InputButton::Code key, std::uint8_t& state) noexcept;

			static InputEvent makeGetMousePos(WindHandle win, std::int16_t& x, std::int16_t& y) noexcept;

			static InputEvent makeGetWindowPos(WindHandle win, std::uint16_t& x, std::uint16_t& y) noexcept;
			static InputEvent makeGetWindowSize(WindHandle win, std::uint16_t& w, std::uint16_t& h) noexcept;
			static InputEvent makeGetWindowTitle(WindHandle win, char* output) noexcept;
			static InputEvent makeGetWindowClassName(WindHandle win, char* output) noexcept;

			static InputEvent makeMessageBox(WindHandle win, const char* message) noexcept;
			static InputEvent makeSayString(WindHandle win, const char* message) noexcept;

			static InputEvent makeScreenshot(WindHandle win, std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* image) noexcept;

			static InputEvent makeFindColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept;
			static InputEvent makeFindColorEx(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept;
			static InputEvent makeFindCenterColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept;
			static InputEvent makeFindImage(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, const std::uint8_t* pattern, std::uint16_t w_, std::uint16_t h_, std::uint16_t& x, std::uint16_t& y) noexcept;

			static InputEvent makeSetCapture(bool enable) noexcept;
			static InputEvent makeCommand(const char* message) noexcept;
			static InputEvent makeSleep(std::uint32_t milliseconds) noexcept;

			static InputEvent makeStartRecord(const char* filepath) noexcept;
			static InputEvent makePauseRecord() noexcept;
			static InputEvent makeStopRecord() noexcept;
		};
	}
}

#endif