/*!
 * @brief Get compile-time C standard.
 */
#include "ceu_check/ceu_c_utils.h"

#ifndef CEU_CHECK_C_STD_H
#define CEU_CHECK_C_STD_H

#define CEU_C_STD_LATEST 17

#if (!defined __STDC_VERSION__)
#define CEU_C_STD_MACRO 0
#else
#define CEU_C_STD_MACRO __STDC_VERSION__
#endif

#if  CEU_C_STD_MACRO < 199409L
#define CEU_C_STD "pre-94"
#elif CEU_C_STD_MACRO == 199409L
#define CEU_C_STD "94"
#elif CEU_C_STD_MACRO == 199901L
#define CEU_C_STD "99"
#elif CEU_C_STD_MACRO == 201112L
#define CEU_C_STD "11"
#elif CEU_C_STD_MACRO == 201710L
#define CEU_C_STD "17"
#else
#define CEU_C_STD "unknown"
#endif

/**
 * Get compile-time C standard version number.
 */
static inline char* interpret_c_version()
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
	int retv;
	retv = snprintf(buff, 256, "%s (%ld)", CEU_C_STD, CEU_C_STD_MACRO);
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
static inline char* get_c_info()
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 512);
	int retv;
	char* c_std_version_buff = interpret_c_version();
	if (c_std_version_buff == NULL)
	{
		return NULL;
	}

	retv = snprintf(buff, 512, "Compile-time C std.: ver. %s", c_std_version_buff);
	free(c_std_version_buff);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}


#endif //CEU_CHECK_C_STD_H
