#pragma once


#ifdef LUMIN_PLATFORM_WINDOWS
	#ifdef LUMIN_BUILD_DLL
		#define LUMIN_API __declspec(dllexport)
	#else
		#define LUMIN_API __declspec(dllimport)
	#endif
#else
	#error Only windows supported!
#endif