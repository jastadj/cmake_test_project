CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(app C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

set(PROJECT_SOURCES
	${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/tools.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/tools.h
	${CMAKE_CURRENT_LIST_DIR}/src/dirent.h
)

set(PROJECT_HEADERS
)

find_package(mylib REQUIRED HINTS ${CMAKE_SOURCE_DIR}/../mylib/build/buildoutput/lib/cmake)
find_package(mathlib REQUIRED HINTS ${CMAKE_SOURCE_DIR}/../mathlib/build/buildoutput/lib/cmake)

add_executable(app ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(app
	mylib::mylib
)

install(
	TARGETS app
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)

install(FILES $<TARGET_RUNTIME_DLLS:app> TYPE BIN)