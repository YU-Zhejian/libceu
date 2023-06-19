
#ifdef CEU_ON_CYGWIN_LIKE

#include <cygwin/version.h>

static inline char* get_compile_time_cygwin_version()
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
static inline char* get_compile_time_cygwin_version(){return NULL;}
#endif

#ifdef CEU_ON_WINDOWS

#include <Windows.h>
#include <VersionHelpers.h>

static inline char* get_run_time_windows_version()
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
static inline char* get_run_time_windows_version() { return NULL; };
#endif

#ifdef CEU_ON_POSIX

#include <sys/utsname.h>
#include <unistd.h>

static inline char* get_run_time_posix_uts_info()
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

static inline char* get_compile_time_posix_standard()
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
static inline char* get_compile_time_posix_standard(){return NULL;}
static inline char* get_run_time_posix_uts_info(){return NULL;}
#endif

