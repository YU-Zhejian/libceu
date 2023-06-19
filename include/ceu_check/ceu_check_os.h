#include "ceu_check/ceu_c_utils.h"

#ifndef CEU_CHECK_OS_H
#define CEU_CHECK_OS_H

#include "os/ceu_os_defs.h"
#include "os/ceu_os_helpers.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* Get a nicely-formatted compile-time operating system information.
*/
static inline char* get_compile_time_os_info()
{
	int retv;
	char* os_name_buff = (char*)ceu_scalloc(sizeof(char), 256);
	retv = snprintf(os_name_buff, 256, "Compile-time OS info: '%s'", CEU_PRIMARY_OS_TYPE);

	if (retv < 0)
	{
		free(os_name_buff);
		return NULL;
	}
	char* cygwin_version_buff = get_compile_time_cygwin_version();
	char* posix_version_buff = get_compile_time_posix_standard();
	char* final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, cygwin_version_buff, posix_version_buff);
	ceu_free_non_null(cygwin_version_buff);
	ceu_free_non_null(os_name_buff);
	ceu_free_non_null(posix_version_buff);
	return final_buff;
}

/**
* Get a nicely-formatted run-time operating system information.
*/
static inline char* get_run_time_os_info()
{
	int retv;
	char* os_name_buff = (char*)ceu_scalloc(sizeof(char), 256);
	retv = snprintf(os_name_buff, 256, "Run-time OS info: '%s'", CEU_PRIMARY_OS_TYPE);

	if (retv < 0)
	{
		free(os_name_buff);
		return NULL;
	}
	char* windows_version_buff = get_run_time_windows_version();
	char* posix_uts_buff = get_run_time_posix_uts_info();
	char* final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, windows_version_buff, posix_uts_buff);
	ceu_free_non_null(windows_version_buff);
	ceu_free_non_null(os_name_buff);
	ceu_free_non_null(posix_uts_buff);
	return final_buff;
}

#ifdef __cplusplus
}
#endif

#endif //CEU_CHECK_OS_H
