#ifndef MYMATH_H
#define MYMATH_H

#ifdef MATHLIB_STATIC
	#define MATHLIB_API
#else
	#ifdef _WIN32
	  #ifdef MATHLIB_DLL
		#define MATHLIB_API __declspec(dllexport)
	  #else
		#define MATHLIB_API __declspec(dllimport)
	  #endif
	#else
	  #define MATHLIB_API
	#endif
#endif

MATHLIB_API int multiply_int(int a, int b);

#endif