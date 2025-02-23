set(MODULE_NAME "mylib")
set(MODULE_NAMESPACE "mylib::")
set(MODULE_ALIAS "${MODULE_NAMESPACE}${MODULE_NAME}")
set(MODULE_EXPORT "${MODULE_NAME}export")

CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(${MODULE_NAME} LANGUAGES C CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/buildoutput")

if(BUILD_SHARED_LIBS)
	add_compile_definitions(MYLIB_STATIC)
else()
	add_compile_definitions(MYLIB_DLL)
endif()

add_compile_definitions(MATHLIB_STATIC)

# FIND MATHLIB PACKAGE
find_package(mathlib REQUIRED)

file(GLOB PROJECT_SOURCES
	"${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
	)

file(GLOB PROJECT_HEADERS
	"${CMAKE_CURRENT_LIST_DIR}/src/*.h"
	)
	
file(GLOB PUBLIC_HEADERS
	"${CMAKE_CURRENT_LIST_DIR}/include/*.h"
)

add_subdirectory(modules)

add_library(${MODULE_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PUBLIC_HEADERS}
	$<TARGET_OBJECTS:modulea>
)
add_library(${MODULE_ALIAS} ALIAS ${MODULE_NAME})

set_target_properties(${MODULE_NAME} PROPERTIES
	PUBLIC_HEADER ${PUBLIC_HEADERS}
	)

target_link_libraries(${MODULE_NAME}
	PRIVATE
		mathlib::mathlib		
)

target_include_directories(${MODULE_NAME}
	PUBLIC		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
		${mathlib_INCLUDE_DIRS}
	PRIVATE
		$<TARGET_PROPERTY:modulea,INTERFACE_INCLUDE_DIRECTORIES>
)

####################
# INSTALL AND EXPORT

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

install(
	TARGETS ${MODULE_NAME}
	EXPORT ${MODULE_EXPORT}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	)

export(
	EXPORT ${MODULE_EXPORT}
	NAMESPACE ${MODULE_NAMESPACE}
	FILE ${MODULE_NAME}-targets.cmake
)

install(
	EXPORT ${MODULE_EXPORT}
	NAMESPACE ${MODULE_NAMESPACE}
	FILE ${MODULE_NAME}-targets.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${MODULE_NAME}
)

install(
	FILES
		${CMAKE_CURRENT_LIST_DIR}/cmake/${MODULE_NAME}-config.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${MODULE_NAME}
)