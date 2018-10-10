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

VINYL_C_LINKAGE VINYL_C_EXPORT bool VINYL_C_CALL VinylInit(const char* profile) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowKeyDown(vinyl::input::InputKey::Code key) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowKeyDown(vinyl::input::InputKey::Code key) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowKeyUp(vinyl::input::InputKey::Code key) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowKeyPress(vinyl::input::InputKey::Code key) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowKeyChar(std::uint16_t unicode, std::uint16_t mods) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowMouseButtonDoubleClick(vinyl::input::InputButton::Code button, float x, float y) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylWindowMouseMotion(float x, float y) noexcept;
VINYL_C_LINKAGE VINYL_C_EXPORT void VINYL_C_CALL VinylScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h) noexcept;

#endif