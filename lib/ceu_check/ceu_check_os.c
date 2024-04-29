#include "ceu_check/ceu_check_os.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_check/ceu_check_utils.h"
#include "ceu_cstd/ceu_stdio.h"

#ifdef CEU_ON_CYGWIN_LIKE
#if CEU_HAVE_INCLUDE_CYGWIN_VERSION_H == 1
#include <cygwin/version.h>

char* get_compile_time_cygwin_version(void)
{
    int retv;
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "CYGWIN API ver. %d.%d\n\tCYGWIN DLL (%s) ver. %d.%d", CYGWIN_VERSION_API_MAJOR,
        CYGWIN_VERSION_API_MINOR, CYGWIN_VERSION_DLL_IDENTIFIER, CYGWIN_VERSION_DLL_MAJOR,
        CYGWIN_VERSION_DLL_MINOR);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else
char* get_compile_time_cygwin_version(void)
{
    int retv;
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "CYGWIN API ver. undefined\n\tCYGWIN DLL (undefined) ver. undefined -- We're on MSYS2/MinGW?");
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#endif
#else

char* get_compile_time_cygwin_version(void)
{
    return NULL;
}

#endif


char* get_run_time_haiku_version(void ) {
    // FIXME: Contains bugs.
    /*
#ifdef CEU_ON_HAIKU
    #include <iostream>
#include <os.h>
#include <kernel/image.h>
    image_info_t info;
    status_t status = get_image_info(B_CURRENT_TEAM, &info);
    if (status == B_OK) {
        version_info version;
        if (get_haiku_version(&version, sizeof(version), B_HAIKU_VERSION_KIND) == B_OK) {
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "%s (%d.%d.%d)", B_OS_NAME, version.major, version.middle, version.minor);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
    }}
    return NULL;
#else
    return NULL;
#endif
     */
    return NULL;
}

#ifdef CEU_ON_WINDOWS

#if CEU_HAVE_INCLUDE_VERSIONHELPERS_H == 0
char* get_run_time_windows_version(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    ceu_snprintf(buff, 256,
        "You've been compiled on a Windows platform that does not "
        "support Windows 10 SDK.");
    return buff;
}
#else
#include <VersionHelpers.h>
#include <Windows.h>

char* get_run_time_windows_version(void)
{
    int retv;
    char* version;
    char* distro;
    char* buff;
    if (IsWindows10OrGreater()) {
        version = "Windows 10";
    } else if (IsWindows8Point1OrGreater()) {
        version = "Windows 8.1";
    } else if (IsWindows8OrGreater()) {
        version = "Windows 8";
    } else if (IsWindows7SP1OrGreater()) {
        version = "Windows 7 SP 1";
    } else if (IsWindows7OrGreater()) {
        version = "Windows 7";
    } else if (IsWindowsVistaSP2OrGreater()) {
        version = "Windows Vista SP 2";
    } else if (IsWindowsVistaSP1OrGreater()) {
        version = "Windows Vista SP 1";
    } else if (IsWindowsVistaOrGreater()) {
        version = "Windows Vista";
    } else if (IsWindowsXPSP2OrGreater()) {
        version = "Windows XP SP 2";
    } else if (IsWindowsXPSP1OrGreater()) {
        version = "Windows XP SP 1";
    } else if (IsWindowsXPOrGreater()) {
        version = "Windows XP";
    } else {
        version = " Windows Unknown";
    }

    if (IsWindowsServer()) {
        distro = "Server";
    } else {
        distro = "Desktop";
    }
    buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "%s %s", version, distro);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#endif

#else

char* get_run_time_windows_version(void)
{
    return NULL;
}

#endif

#ifdef CEU_ON_POSIX
#include <unistd.h> // Should NOT be removed

#if CEU_HAVE_INCLUDE_SYS_UTSNAME_H == 1
#include <sys/utsname.h>

char* get_run_time_posix_uts_info(void)
{
    int retv;
    struct utsname ceu_utsname;
    uname(&ceu_utsname);
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "POSIX UTSINFO=\'%s %s %s %s %s\'", ceu_utsname.sysname, ceu_utsname.nodename,
        ceu_utsname.release, ceu_utsname.version, ceu_utsname.machine);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else
char* get_run_time_posix_uts_info(void)
{
    int retv;
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    retv = ceu_snprintf(buff, 256, "POSIX UTSINFO=undefined");
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#endif

char* get_compile_time_posix_standard(void)
{
    char* ct_posix1_buff = (char*)ceu_scalloc(256, sizeof(char));
#ifdef _POSIX_VERSION
    ceu_snprintf(ct_posix1_buff, 256, "POSIX.1 Version: %ld", _POSIX_VERSION);
#else
    ceu_snprintf(ct_posix1_buff, 256, "POSIX.1 Version: undefined");
#endif
    char* ct_posix2_buff = (char*)ceu_scalloc(256, sizeof(char));
#ifdef _POSIX2_VERSION
    ceu_snprintf(ct_posix2_buff, 256, "POSIX.2 Version: %ld", _POSIX2_VERSION);
#else
    ceu_snprintf(ct_posix2_buff, 256, "POSIX.2 Version: undefined");
#endif
    char* ct_sus_buff = (char*)ceu_scalloc(256, sizeof(char));
#ifdef _XOPEN_UNIX
#ifdef _XOPEN_VERSION
    ceu_snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: %d", _XOPEN_VERSION);
#else
    ceu_snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: unknown");
#endif
#else
    ceu_snprintf(ct_sus_buff, 256, "Single UNIX Specification (SUS) version: undefined");
#endif
    char* retbuff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, ct_posix1_buff, ct_posix2_buff, ct_sus_buff);
    ceu_free_non_null(ct_posix1_buff);
    ceu_free_non_null(ct_posix2_buff);
    ceu_free_non_null(ct_sus_buff);
    return retbuff;
}

#else

char* get_compile_time_posix_standard(void)
{
    return NULL;
}

char* get_run_time_posix_uts_info(void)
{
    return NULL;
}

#endif

char* ceu_check_get_compile_time_os_info(void)
{
    int retv;
    char* os_name_buff = (char*)ceu_scalloc(256, sizeof(char));
    char* haiku_version_buff = get_run_time_haiku_version();
    char* cygwin_version_buff = get_compile_time_cygwin_version();
    char* posix_version_buff = get_compile_time_posix_standard();
    char* final_buff;

    retv = ceu_snprintf(os_name_buff, 256, "Compile-time OS info: '%s'", CEU_PRIMARY_OS_TYPE);

    if (retv < 0) {
        ceu_free_non_null(os_name_buff);
        return NULL;
    }
    final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, cygwin_version_buff, posix_version_buff, haiku_version_buff);
    ceu_free_non_null(cygwin_version_buff);
    ceu_free_non_null(haiku_version_buff);
    ceu_free_non_null(os_name_buff);
    ceu_free_non_null(posix_version_buff);
    return final_buff;
}

char* ceu_check_get_run_time_os_info(void)
{
    int retv;
    char* os_name_buff = (char*)ceu_scalloc(256, sizeof(char));
    char* windows_version_buff = get_run_time_windows_version();
    char* posix_uts_buff = get_run_time_posix_uts_info();
    char* final_buff;

    retv = ceu_snprintf(os_name_buff, 256, "Run-time OS info: '%s'", CEU_PRIMARY_OS_TYPE);

    if (retv < 0) {
        ceu_free_non_null(os_name_buff);
        return NULL;
    }
    final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 3, os_name_buff, windows_version_buff, posix_uts_buff);
    ceu_free_non_null(windows_version_buff);
    ceu_free_non_null(os_name_buff);
    ceu_free_non_null(posix_uts_buff);
    return final_buff;
}
