#pragma once

#if (defined _WIN32 || defined __CYGWIN__) && defined(__GNUC__)
#	define GLSLCOM_IMPORT_API __declspec(dllimport)
#	define GLSLCOM_EXPORT_API __declspec(dllexport)
#else
#	define GLSLCOM_IMPORT_API __attribute__((visibility("default")))
#	define GLSLCOM_EXPORT_API __attribute__((visibility("default")))
#endif

#ifdef GLSLCOM_BUILD_STATIC_LIBRARY
#	define GLSLCOM_API
#elif defined(GLSLCOM_BUILD_DYNAMIC_LIBRARY)
#	define GLSLCOM_API GLSLCOM_EXPORT_API
#elif defined(GLSLCOM_USE_DYNAMIC_LIBRARY)
#	define GLSLCOM_API GLSLCOM_IMPORT_API
#elif defined(GLSLCOM_USE_STATIC_LIBRARY)
#	define GLSLCOM_API
#else
#	define GLSLCOM_API
#endif
