#pragma once

#ifdef VT_PLATFORM_WINDOWS
#ifdef VT_BUILD_DLL
		#define VRITRA_API __declspec(dllexport)
	#else
		#define VRITRA_API __declspec(dllimport)
	#endif
#else
	#error Vritra only supports Windows!
#endif