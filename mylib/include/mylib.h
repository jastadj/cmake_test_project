#ifndef MYLIB_H
#define MYLIB_H

#ifdef MYLIB_STATIC
    #define MYLIB_API
#else
    #ifdef _WIN32
      #ifdef MYLIB_DLL
        #define MYLIB_API __declspec(dllexport)
      #else
        #define MYLIB_API __declspec(dllimport)
      #endif
    #else
      #define MYLIB_API
    #endif
#endif

namespace MyLib
{
	MYLIB_API const char* getVersion();
    MYLIB_API int getMagic();
	
	MYLIB_API int getTotalAccounts();
};

#endif