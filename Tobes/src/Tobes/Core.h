#pragma once

#ifdef TB_PLATFORM_WINDOWS
	#ifdef TB_BUILD_DLL
		#define TOBES_API __declspec(dllexport)
	#else
		#define TOBES_API __declspec(dllimport)
	#endif
#else
	#error Tobes only supports Windows
#endif
