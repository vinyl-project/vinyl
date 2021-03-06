SET(LIB_NAME vinyl-c)

# vinyl folder
INCLUDE_DIRECTORIES(${VINYL_PATH_INCLUDE})

SET(HEADER_PATH ${VINYL_PATH_HEADER})
SET(SOURCE_PATH ${VINYL_PATH_SOURCE}/vinyl-c)

SET(INPUT_CORE_LIST
	${HEADER_PATH}/input_button.h
	${HEADER_PATH}/input_event.h
	${SOURCE_PATH}/input_event.cpp
	${HEADER_PATH}/input_key.h
	${HEADER_PATH}/input_types.h
	${HEADER_PATH}/input_ps3.h
	${HEADER_PATH}/input_xbox.h
)
SOURCE_GROUP("input\\core" FILES ${INPUT_CORE_LIST})

SET(INPUT_INTERFACE_LIST
	${HEADER_PATH}/iinput_controller.h
	${HEADER_PATH}/iinput_device.h
	${HEADER_PATH}/iinput_debug.h
	${HEADER_PATH}/iinput_keyboard.h
	${HEADER_PATH}/iinput_mouse.h
	${HEADER_PATH}/iinput_window.h
	${HEADER_PATH}/iinput_image.h
	${HEADER_PATH}/iinput.h
)
SOURCE_GROUP("input\\interface" FILES ${INPUT_INTERFACE_LIST})

SET(INPUT_DEFAULT_LIST
	${SOURCE_PATH}/input_controller.cpp
	${HEADER_PATH}/input_controller.h
	${HEADER_PATH}/input_device.h
	${SOURCE_PATH}/input_device.cpp
	${HEADER_PATH}/input_debug.h
	${SOURCE_PATH}/input_debug.cpp
	${HEADER_PATH}/input_keyboard.h
	${SOURCE_PATH}/input_keyboard.cpp
	${HEADER_PATH}/input_mouse.h
	${SOURCE_PATH}/input_mouse.cpp
	${HEADER_PATH}/input_window.h
	${SOURCE_PATH}/input_window.cpp
	${HEADER_PATH}/input_image.h
	${SOURCE_PATH}/input_image.cpp
	${HEADER_PATH}/input.h
	${SOURCE_PATH}/input.cpp
)
SOURCE_GROUP("input\\default" FILES ${INPUT_DEFAULT_LIST})

SET(INPUT_MSW_LIST
	${SOURCE_PATH}/msw_input_record.h
	${SOURCE_PATH}/msw_input_record.cpp
	${SOURCE_PATH}/msw_input_keyboard.h
	${SOURCE_PATH}/msw_input_keyboard.cpp
	${SOURCE_PATH}/msw_input_mouse.h
	${SOURCE_PATH}/msw_input_mouse.cpp
	${SOURCE_PATH}/msw_input_window.h
	${SOURCE_PATH}/msw_input_window.cpp
	${SOURCE_PATH}/msw_input_image.h
	${SOURCE_PATH}/msw_input_image.cpp
	${SOURCE_PATH}/msw_input_hook.h
	${SOURCE_PATH}/msw_input_hook.cpp
)
SOURCE_GROUP("input\\msw" FILES ${INPUT_MSW_LIST})

SET(INPUT_NDK_LIST
	${SOURCE_PATH}/ndk_input_device.h
	${SOURCE_PATH}/ndk_input_device.cpp
	${SOURCE_PATH}/ndk_input_keyboard.h
	${SOURCE_PATH}/ndk_input_keyboard.cpp
	${SOURCE_PATH}/ndk_input_touch.h
	${SOURCE_PATH}/ndk_input_touch.cpp
)
SOURCE_GROUP("input\\ndk" FILES ${INPUT_NDK_LIST})

SET(INPUT_LIST
	${HEADER_PATH}/vinyl-c.h
	${SOURCE_PATH}/vinyl-c.cpp
)
SOURCE_GROUP("input" FILES ${INPUT_LIST})

IF(VINYL_BUILD_SHARED_DLL)
	ADD_DEFINITIONS(-DVINYL_BUILD_DLL_EXPORT)

	IF(VINYL_FEATURE_INPUT_API_WINDOWS)
		ADD_LIBRARY(${LIB_NAME} SHARED ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST} ${INPUT_MSW_LIST})
	ELSEIF(VINYL_FEATURE_INPUT_API_ANDROID)
		ADD_LIBRARY(${LIB_NAME} SHARED ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST} ${INPUT_NDK_LIST})
	ELSEIF(VINYL_FEATURE_INPUT_API_NULL)
		ADD_LIBRARY(${LIB_NAME} SHARED ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST})
	ELSE()
		MESSAGE("Not supported yet")
	ENDIF()
ELSE()
	ADD_DEFINITIONS(-DVINYL_STATIC)
	
	IF(VINYL_FEATURE_INPUT_API_WINDOWS)
		ADD_LIBRARY(${LIB_NAME} ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST} ${INPUT_MSW_LIST})
	ELSEIF(VINYL_FEATURE_INPUT_API_ANDROID)
		ADD_LIBRARY(${LIB_NAME} ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST} ${INPUT_NDK_LIST})
	ELSEIF(VINYL_FEATURE_INPUT_API_NULL)
		ADD_LIBRARY(${LIB_NAME} ${INPUT_LIST} ${INPUT_CORE_LIST} ${INPUT_INTERFACE_LIST} ${INPUT_DEFAULT_LIST})
	ELSE()
		MESSAGE("Not supported yet")
	ENDIF()
ENDIF()

IF(VINYL_FEATURE_INPUT_API_WINDOWS)
	TARGET_LINK_LIBRARIES(${LIB_NAME} PRIVATE winmm)
	TARGET_LINK_LIBRARIES(${LIB_NAME} PRIVATE imm32)
ENDIF()

SET_TARGET_ATTRIBUTE(${LIB_NAME} "core")