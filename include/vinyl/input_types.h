#ifndef VINYL_INPUT_TYPES_H_
#define VINYL_INPUT_TYPES_H_

#include <memory> // std::shared_ptr
#include <assert.h> // assert

#if defined(_MSC_VER) || defined (_WIN32) || defined(_WIN64)
#	include <windows.h>

#	ifndef __WINDOWS__
#		define __WINDOWS__ 1
#	endif

#	if defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64)
#		define __WIN64__ 1
#	elif defined(_WIN32) || defined(_M_IX86)
#		define __WIN32__ 1
#	endif

#	undef EXPORT
#	undef CALL

#	undef min
#	undef max

#	undef RGB
#	undef RGBA

#	undef DELETE

#	if defined(VINYL_BUILD_DLL_EXPORT)
#		define VINYL_EXPORT __declspec(dllexport)
#		define VINYL_EXPORT_WINONLY __declspec(dllexport)
#	else
#		if defined(VINYL_STATIC)
#			define VINYL_EXPORT
#			define VINYL_EXPORT_WINONLY
#		else
#			define VINYL_EXPORT __declspec(dllimport)
#			define VINYL_EXPORT_WINONLY __declspec(dllimport)
#		endif
#	endif

#	define VINYL_CALL __stdcall
#	define VINYL_INLINE __forceinline
#	define VINYL_WONT_RETURN __declspec(noreturn)
#else
#	define VINYL_EXPORT __attribute__ ((visibility("default")))
#	define VINYL_EXPORT_WINONLY
#
#	define VINYL_CALL
#	define VINYL_INLINE inline
#	define VINYL_WONT_RETURN
#endif

namespace vinyl
{
	namespace input
	{
		typedef std::shared_ptr<class IInputController> IInputControllerPtr;
		typedef std::shared_ptr<class IInputKeyboard> IInputKeyboardPtr;
		typedef std::shared_ptr<class IInputMouse> IInputMousePtr;
		typedef std::shared_ptr<class IInputUser> IInputUserPtr;
		typedef std::shared_ptr<class IInputDebug> IInputDebugPtr;
		typedef std::shared_ptr<class IInputImage> IInputImagePtr;
		typedef std::shared_ptr<class IInputDevice> IInputDevicePtr;
		typedef std::shared_ptr<class IInput> IInputPtr;

		typedef void* WindHandle;
	}
}

#endif