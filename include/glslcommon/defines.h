
#pragma once

#include <common/defines.h>

#ifdef GLSL_COMSTATIC_LIBRARY
#	define GLSL_COM_API
#elif GLSL_COMDYNAMIC_LIBRARY
#	define GLSL_COM_API __declspec(dllimport)
#elif BUILD_DYNAMIC_LIBRARY
#	define GLSL_COM_API __declspec(dllexport)
#else
#	define GLSL_COM_API
#endif
