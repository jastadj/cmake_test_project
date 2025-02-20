include(CMakeFindDependencyMacro)
find_dependency(mathlib HINTS ${CMAKE_CURRENT_LIST_DIR}/..)
include(${CMAKE_CURRENT_LIST_DIR}/mylib-targets.cmake)