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
#ifdef TH_ENABLE_ASSERTS
#define TH_ASSERT(x, ...) { if(!(x)) { TH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define TH_CORE_ASSERT(x, ...) { if(!(x)) { TH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define TH_ASSERT(x, ...)
#define TH_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
