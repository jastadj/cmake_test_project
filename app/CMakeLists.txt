CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(app C CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(mathlib CONFIG REQUIRED
	HINTS
		${CMAKE_CURRENT_LIST_DIR}/../mathlib/build/buildoutput/lib/cmake
)

file(GLOB PROJECT_SOURCES
	"${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
	)

file(GLOB PROJECT_HEADERS
	"${CMAKE_CURRENT_LIST_DIR}/include/*.h"
	)

add_executable(app ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(app
	mathlib::mathlib
)
