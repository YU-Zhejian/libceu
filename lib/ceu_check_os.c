#include <stdio.h>
#include <stdlib.h>

#include "ceu_check/ceu_c_utils.h"
#include "ceu_check/ceu_check_os.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifdef CEU_ON_CYGWIN_LIKE

#include <cygwin/version.h>

char* get_compile_time_cygwin_version(void)
{
	int retv;
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
	retv = snprintf(
		buff,
		256,
		"CYGWIN API ver. %d.%d\n\tCYGWIN DLL (%s) ver. %d.%d",
		CYGWIN_VERSION_API_MAJOR,
		CYGWIN_VERSION_API_MINOR,
		CYGWIN_VERSION_DLL_IDENTIFIER,
		CYGWIN_VERSION_DLL_MAJOR,
		CYGWIN_VERSION_DLL_MINOR
	);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

#else

char* get_compile_time_cygwin_version(void)
{
	return NULL;
}

#endif

#ifdef CEU_ON_WINDOWS

#include <Windows.h>
#include <VersionHelpers.h>

char* get_run_time_windows_version(void)
{
	int retv;
	char* version;
	if (IsWindows10OrGreater())
	{
		version = "Windows 10";
	}
	else if (IsWindows8Point1OrGreater())
	{
		version = "Windows 8.1";
	}
	else if (IsWindows8OrGreater())
	{
		version = "Windows 8";
	}
	else if (IsWindows7SP1OrGreater())
	{
		version = "Windows 7 SP 1";
	}
	else if (IsWindows7OrGreater())
	{
		version = "Windows 7";
	}
	else if (IsWindowsVistaSP2OrGreater())
	{
		version = "Windows Vista SP 2";
	}
	else if (IsWindowsVistaSP1OrGreater())
	{
		version = "Windows Vista SP 1";
	}
	else if (IsWindowsVistaOrGreater())
	{
		version = "Windows Vista";
	}
	else if (IsWindowsXPSP2OrGreater())
	{
		version = "Windows XP SP 2";
	}
	else if (IsWindowsXPSP1OrGreater())
	{
		version = "Windows XP SP 1";
	}
	else if (IsWindowsXPOrGreater())
	{
		version = "Windows XP";
	}
	else
	{
		version = " Windows Unknown";
	}
	char* distro;
	if (IsWindowsServer())
	{
		distro = "Server";
	}
	else
	{
		distro = "Desktop";
	}
	char* buff = (char*)ceu_scalloc(256, sizeof(char));
	retv = snprintf(buff, 256, "%s %s", version, distro);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

#else

char* get_run_time_windows_version(void)
{
	return NULL;
}

#endif

#ifdef CEU_ON_POSIX

#include <unistd.h> // Should NOT be removed
#include <sys/utsname.h>

char* get_run_time_posix_uts_info(void)
{
	int retv;
	struct utsname ceu_utsname;
	uname(&ceu_utsname);
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
	retv = snprintf(
			buff,
			256,
			"POSIX UTSINFO=\'%s %s %s %s %s\'",
			ceu_utsname.sysname,
			ceu_utsname.nodename,
			ceu_utsname.release,
			ceu_utsname.version,
			ceu_utsname.machine
	);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

char* get_compile_time_posix_standard(void)
{
	char* ct_posix1_buff = (char*)ceu_scalloc(sizeof(char), 256);
#ifdef _POSIX_VERSION
	snprintf(ct_posix1_buff, 256, "POSIX.1 Version: %ld", _POSIX_VERSION);
#else
	snprintf(ct_posix1_buff, 256, "POSIX.1 Version: undefined");
#endif
	char* ct_posix2_buff = (char*)ceu_scalloc(sizeof(char), 256);
#ifdef _POSIX2_VERSION
	snprintf(ct_posix2_buff, 256, "POSIX.2 Version: %ld", _POSIX2_VERSION);
#else
	snprintf(ct_posix2_buff, 256, "POSIX.2 Version: undefined");
#endif
	char* ct_sus_buff = (char*)ceu_scalloc(sizeof(char), 256);
#ifdef _XOPEN_UNIX
#ifdef _XOPEN_VERSION
	snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: %d", _XOPEN_VERSION);
#else
	snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: unknown");
#endif
#else
	snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: undefined");
#endif
	char* retbuff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, ct_posix1_buff, ct_posix2_buff, ct_sus_buff);
	return retbuff;
}

#else
char* get_compile_time_posix_standard(void) { return NULL; }
char* get_run_time_posix_uts_info(void) { return NULL; }
#endif

char* get_compile_time_os_info(void)
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
	char* final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, cygwin_version_buff,
			posix_version_buff);
	ceu_free_non_null(cygwin_version_buff);
	ceu_free_non_null(os_name_buff);
	ceu_free_non_null(posix_version_buff);
	return final_buff;
}

char* get_run_time_os_info(void)
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
	char* final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, windows_version_buff,
			posix_uts_buff);
	ceu_free_non_null(windows_version_buff);
	ceu_free_non_null(os_name_buff);
	ceu_free_non_null(posix_uts_buff);
	return final_buff;
}

#ifdef __cplusplus
}
#endif
