#pragma once
#ifdef TB_BUILD_DLL
#define TOBES_API __declspec(dllexport)
#else
#define TOBES_API __declspec(dllimport)
#endif
