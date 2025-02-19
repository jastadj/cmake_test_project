#ifndef MYMATH_H
#define MYMATH_H

#ifdef _WIN32
  #ifdef MATHLIB_EXPORT
    #define MATHLIB_API __declspec(dllexport)
  #else
    #define MATHLIB_API __declspec(dllimport)
  #endif
#else
  #define MATHLIB_API
#endif

MATHLIB_API int multiply_int(int a, int b);

#endif