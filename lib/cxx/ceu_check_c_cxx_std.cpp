#include "ceu_check/ceu_check_c_cxx_std.h"
#include "ceu_check/ceu_c_utils.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

char* ceu_interpret_c_std_version(void)
{
	char* buff = (char*) ceu_scalloc(256, sizeof(char));
	int retv = snprintf(buff, 256, "%s (%ld)", CEU_C_STD, (long) CEU_C_STD_MACRO);
	if (retv < 0)
	{
		ceu_free_non_null(buff);
		return NULL;
	}
	return buff;
}

char* ceu_check_get_c_std_info(void)
{
	char* buff = (char*) ceu_scalloc(512, sizeof(char));
	int retv;
	char* c_std_version_buff = ceu_interpret_c_std_version();
	if (c_std_version_buff == NULL)
	{
		return NULL;
	}

	retv = snprintf(buff, 512, "Compile-time C std.: ver. %s", c_std_version_buff);
	ceu_free_non_null(c_std_version_buff);
	if (retv < 0)
	{
		ceu_free_non_null(buff);
		return NULL;
	}
	return buff;
}


/*!
 * @fn interpret_cxx_version
 * @brief Get compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 256 bytes long.
 */
char* ceu_interpret_cxx_std_version(void)
{
	char* buff = (char*) ceu_scalloc(256, sizeof(char));
	int retv;
	if (CEU_CXX_STD == 0)
	{
		retv = snprintf(buff, 256, "before 98 (%ld)", (unsigned long)CEU_CXX_STD_VERSION_MACRO);
	}
	else if (CEU_CXX_STD == -2)
	{
		retv = snprintf(buff, 256, "unknown (_MSVC_LANG and __cplusplus undefined)");
	}
	else
	{
		retv = snprintf(buff, 256, "%d (%ld)", CEU_CXX_STD, (unsigned long)CEU_CXX_STD_VERSION_MACRO);
	}
	if (retv < 0)
	{
		ceu_free_non_null(buff);
		return NULL;
	}
	return buff;
}

/*!
 * @brief Get a nicely formatted compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 1024 bytes long.
 */
char* ceu_check_get_cxx_std_info(void)
{
	char* buff = (char*) ceu_scalloc(512, sizeof(char));
	int retv;
	char* cxx_std_version_buff = ceu_interpret_cxx_std_version();
	if (cxx_std_version_buff == NULL)
	{
		return NULL;
	}

	retv = snprintf(buff, 512, "Compile-time C++ std.: ver. %s", cxx_std_version_buff);
	ceu_free_non_null(cxx_std_version_buff);
	if (retv < 0)
	{
		ceu_free_non_null(buff);
		return NULL;
	}
	return buff;
}

#ifdef __cplusplus
}
#endif
