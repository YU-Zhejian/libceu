/*!
@file check_cxx_std.hpp
@brief Check Compile-Time C++ standard.
*/

/*!
@def CEU_CXX_STD
@brief The C++ Standard in a human-readable way.
*/

/*!
@def CEU_CXX_STD_VERSION_MACRO
@brief The C++ Standard version.
*/

#include "ceu_check/ceu_append_sprintf.h"

#ifndef CEU_CHECK_CXX_STD_H
#define CEU_CHECK_CXX_STD_H

#if defined(_MSVC_LANG)
#define CEU_CXX_STD_VERSION_MACRO _MSVC_LANG
#elif defined(__cplusplus)
#define CEU_CXX_STD_VERSION_MACRO __cplusplus
#else
#define CEU_CXX_STD_VERSION_MACRO -2
#endif

/*!
Latest supported C++ Standard Verison.
*/
#define CEU_CXX_STD_LATEST 23

#if CEU_CXX_STD_VERSION_MACRO == -2
#define CEU_CXX_STD -2
#elif CEU_CXX_STD_VERSION_MACRO < 199711L
#define CEU_CXX_STD 0
#elif CEU_CXX_STD_VERSION_MACRO >= 202100L
#define CEU_CXX_STD 23
#elif CEU_CXX_STD_VERSION_MACRO >= 202002L
#define CEU_CXX_STD 20
#elif CEU_CXX_STD_VERSION_MACRO >= 201703L
#define CEU_CXX_STD 17
#elif CEU_CXX_STD_VERSION_MACRO >= 201402L
#define CEU_CXX_STD 14
#elif CEU_CXX_STD_VERSION_MACRO >= 201103L
#define CEU_CXX_STD 11
#elif CEU_CXX_STD_VERSION_MACRO >= 199711L
#define CEU_CXX_STD 98
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * @fn interpret_cxx_version
 * @brief Get compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 256 bytes long.
 */
static inline char* interpret_cxx_version()
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
	int retv;
	if (CEU_CXX_STD == 0)
	{
		retv = snprintf(buff, 256, "before 98 (%ld)", CEU_CXX_STD_VERSION_MACRO);
	}
	else if (CEU_CXX_STD == -2)
	{
		retv = snprintf(buff, 256, "unknown (_MSVC_LANG and __cplusplus undefined)");
	}
	else
	{
		retv = snprintf(buff, 256, "%d (%ld)", CEU_CXX_STD, CEU_CXX_STD_VERSION_MACRO);
	}
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

/*!
 * @brief Get a nicely formatted compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 1024 bytes long.
 */
static inline char* get_cxx_info()
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 512);
	int retv;
	char* cxx_std_version_buff = interpret_cxx_version();
	if (cxx_std_version_buff == NULL)
	{
		return NULL;
	}

	retv = snprintf(buff, 512, "Compile-time C++ std.: ver. %s", cxx_std_version_buff);
	free(cxx_std_version_buff);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

#ifdef __cplusplus
}
#endif
#endif // CEU_CHECK_CXX_STD_H
