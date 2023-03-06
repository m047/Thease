#pragma once

#ifdef THEA_PLATFORM_WINDOWS
	#ifdef THEA_BUILD_DLL
		#define THEASE_API __declspec(dllexport)
	#else
		#define THEASE_API __declspec(dllimport)
	#endif // THEA_BUILD_DLL

#else
	#error Thease only works on windows right now!
#endif

#define BIT(x) (1 << x)
