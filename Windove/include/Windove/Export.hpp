#pragma once

#if defined(_WIN32)
	#if defined(WINDOVE_STATIC)
		#define WINDOVE_API
	#elif defined(WINDOVE_BUILD)
		#define WINDOVE_API __declspec(dllexport)
	#else
		#define WINDOVE_API __declspec(dllimport)
	#endif
#else
	#define WINDOVE_API __attribute__((visibility("default")))
#endif