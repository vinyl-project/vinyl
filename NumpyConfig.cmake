# lib names
set(NUMPY_NAMES "npymath")

# search paths
set(NUMPY_SEARCHES)

# Search NUMPY_ROOT first if it is set.
if(NUMPY_ROOT)
  set(NUMPY_ROOT_SEARCH_ROOT PATH ${NUMPY_ROOT})
  list(APPEND NUMPY_SEARCHES ${NUMPY_ROOT_SEARCH_ROOT})
endif()

# Search path
# Use the executable's path as a hint
if(WIN32)
  execute_process(COMMAND where python OUTPUT_VARIABLE PYTHON_EXECUTABLE)
  get_filename_component(PYTHON_PATH "${PYTHON_EXECUTABLE}" PATH)
  list(APPEND NUMPY_SEARCHES ${PYTHON_PATH}/Lib/site-packages/numpy/core)
else()
  execute_process(COMMAND which python OUTPUT_VARIABLE PYTHON_EXECUTABLE)
  get_filename_component(PYTHON_PATH "${PYTHON_EXECUTABLE}" PATH)
  list(APPEND NUMPY_SEARCHES ${PYTHON_PATH}/Lib/site-packages/numpy/core)
endif()

# message(STATUS ${NUMPY_SEARCHES})

# Normal search.
set(NUMPY_SEARCH_NORMAL
  "/usr/bin/python")
list(APPEND NUMPY_SEARCHES ${NUMPY_SEARCH_NORMAL})

# Try each search configuration.
foreach(search ${NUMPY_SEARCHES})
  find_path(NUMPY_INCLUDE_DIR NAMES numpyconfig.h PATHS ${search} PATH_SUFFIXES include)
endforeach()

set(NUMPY_INCLUDE_DIR ${NUMPY_INCLUDE_DIR}/..)

# Allow NUMPY_LIBRARY to be set manually, as the location of the numpy library
if(NOT NUMPY_LIBRARY)
  foreach(search ${NUMPY_SEARCHES})
    find_library(NUMPY_LIBRARY_RELEASE NAMES ${NUMPY_NAMES} PATHS ${search} PATH_SUFFIXES lib)
  endforeach()
endif()

set(NUMPY_LIBRARY ${NUMPY_LIBRARY_RELEASE})

unset(NUMPY_NAMES)

if(NUMPY_INCLUDE_DIR AND EXISTS "${NUMPY_INCLUDE_DIR}/numpy/numpyconfig.h")

    file(STRINGS "${NUMPY_INCLUDE_DIR}/numpy/numpyconfig.h" NUMPY_H REGEX "^#define NPY_([0-9]+)_([0-9]+)_API_VERSION 0x00000008$")

    list(REVERSE NUMPY_H)
    list(GET NUMPY_H 0 NUMPY_H)

    string(REGEX REPLACE "^#define NPY_([0-9]+)_([0-9]+)_API_VERSION 0x00000008$" "\\1" NUMPY_VERSION_MAJOR "${NUMPY_H}")
    string(REGEX REPLACE "^#define NPY_([0-9]+)_([0-9]+)_API_VERSION 0x00000008$" "\\2" NUMPY_VERSION_MINOR  "${NUMPY_H}")
    set(NUMPY_VERSION_STRING "${NUMPY_VERSION_MAJOR}.${NUMPY_VERSION_MINOR}")

    set(NUMPY_MAJOR_VERSION "${NUMPY_VERSION_MAJOR}")
    set(NUMPY_MINOR_VERSION "${NUMPY_VERSION_MINOR}")
    set(NUMPY_PATCH_VERSION "${NUMPY_VERSION_PATCH}")
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NUMPY REQUIRED_VARS NUMPY_LIBRARY NUMPY_INCLUDE_DIR
                                       VERSION_VAR NUMPY_VERSION_STRING)

if(NUMPY_FOUND)
    set(NUMPY_INCLUDE_DIRS ${NUMPY_INCLUDE_DIR})

    if(NOT NUMPY_LIBRARIES)
      set(NUMPY_LIBRARIES ${NUMPY_LIBRARY})
    endif()
endif()