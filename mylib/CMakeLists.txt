CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(mylib LANGUAGES C CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/buildoutput")

option(BUILD_STATIC OFF)
if(BUILD_STATIC)
	add_compile_definitions(MYLIB_STATIC)
else()
	add_compile_definitions(MYLIB_DLL)
endif()

add_compile_definitions(MATHLIB_STATIC)

# modules
add_subdirectory(modules)

# main lib
add_subdirectory(mylib)