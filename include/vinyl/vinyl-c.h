#ifndef VINYL_C_H_
#define VINYL_C_H_

#include <vinyl/input_key.h>
#include <vinyl/input_button.h>

#ifndef VINYL_C_LINKAGE
#	ifdef __cplusplus
#		define VINYL_C_LINKAGE extern "C"
#	else
#		define VINYL_C_LINKAGE extern
#	endif
#endif

#if defined(VINYL_BUILD_PLATFORM_WINDOWS)
#	if defined(VINYL_BUILD_DLL_EXPORT)
#		define VINYL_C_EXPORT __declspec(dllexport)
#	else
#		if defined(VINYL_STATIC)
#			define VINYL_C_EXPORT
#		else
#			define VINYL_C_EXPORT __declspec(dllimport)
#		endif
#	endif

#	define VINYL_C_CALL __stdcall
#else
#	define VINYL_C_CALL
#endif

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylInit(const char* profile) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyDown(vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyUp(vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyClick(vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyDoubleClick(vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWaitKey(vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsKeyDown(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsKeyUp(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept;

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseMove(float x, float y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseMoveTo(float x, float y) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::InputButton::Code button, float x, float y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonDoubleClick(vinyl::input::InputButton::Code button, float x, float y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsMouseButtonDown(vinyl::input::InputButton::Code key, std::uint8_t& state) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsMouseButtonUp(vinyl::input::InputButton::Code key, std::uint8_t& state) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWaitMouseButton(vinyl::input::InputButton::Code key) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWheelUp() noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWheelDown() noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylSleep(std::uint32_t milliseconds) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMessageBox(const char* message) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylTracePrint(std::uint8_t enable) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylCommand(const char* cmd) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept(false);

#endif