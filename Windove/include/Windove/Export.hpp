#pragma once

#ifdef _WIN32
	#ifdef WINDOVE_STATIC
		#define WINDOVE_API
	#else
		#ifdef WINDOVE_EXPORT
			#define WINDOVE_API __declspec(dllexport)
		#else
			#define WINDOVE_API __declspec(dllimport)
		#endif
	#endif
#elif __linux__
	#define WINDOVE_API
#endif