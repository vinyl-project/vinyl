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

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylNewWindow(const char* path, vinyl::input::WindHandle& win) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindWindowFromPos(std::uint16_t x, std::uint16_t y, vinyl::input::WindHandle& win) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindWindowFromTile(const char* tile, vinyl::input::WindHandle& win) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindWindowFromClassName(const char* tile, vinyl::input::WindHandle& win) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyDown(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyUp(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyClick(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylKeyDoubleClick(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseMove(vinyl::input::WindHandle win, std::uint32_t x, std::uint32_t y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseMoveTo(vinyl::input::WindHandle win, std::uint32_t x, std::uint32_t y) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMouseButtonDoubleClick(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsKeyDown(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsKeyUp(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsMouseButtonDown(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylIsMouseButtonUp(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWaitKey(vinyl::input::WindHandle win, vinyl::input::InputKey::Code& key) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWaitMouseButton(vinyl::input::WindHandle win, vinyl::input::InputButton::Code& button) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWheelUp(vinyl::input::WindHandle win) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWheelDown(vinyl::input::WindHandle win) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylGetMousePos(vinyl::input::WindHandle win, std::uint16_t& x, std::uint16_t& y) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylGetWindowPos(vinyl::input::WindHandle win, std::uint16_t& w, std::uint16_t& h) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylGetWindowSize(vinyl::input::WindHandle win, std::uint16_t& w, std::uint16_t& h) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylMessageBox(vinyl::input::WindHandle win, const char* message) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylSayString(vinyl::input::WindHandle win, const char* string) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylSleep(std::uint32_t milliseconds) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylCommand(const char* cmd) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindColorEx(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindCenterColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylFindImage(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, const std::uint8_t* pattern, std::uint16_t w_, std::uint16_t h_, std::uint16_t& x, std::uint16_t& y) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylScreenshot(vinyl::input::WindHandle win, std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept(false);

VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylStartRecord(const char* filepath) noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylPauseRecord() noexcept(false);
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylStopRecord() noexcept(false);

#endif