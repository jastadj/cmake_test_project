CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(mathlib LANGUAGES C CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/buildoutput")

add_compile_definitions(MATHLIB_EXPORT)

file(GLOB PROJECT_SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
	)

file(GLOB PROJECT_HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
	)
	
file(GLOB PUBLIC_HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

add_library(mathlib ${PROJECT_SOURCES} ${PROJECT_HEADERS})
add_library(mathlib::mathlib ALIAS mathlib)

set_target_properties(mathlib PROPERTIES
	PUBLIC_HEADER ${PUBLIC_HEADERS}
	)

target_include_directories(mathlib
	PUBLIC		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

#install(
#	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
#	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#)

install(
	TARGETS mathlib
	EXPORT mathlibpackage
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	)

export(
	EXPORT mathlibpackage
	NAMESPACE mathlib::
	FILE mathlib-targets.cmake
)

install(
	EXPORT mathlibpackage
	NAMESPACE mathlib::
	FILE mathlib-targets.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mathlib
)

install(
	FILES
		${CMAKE_CURRENT_LIST_DIR}/cmake/mathlib-config.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mathlib
)