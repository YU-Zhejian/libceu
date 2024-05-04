#include "ceu_check/ceu_check_os.h"
#include "ceu_check/ceu_check_helpers.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"

#ifdef CEU_ON_POSIX
#include <unistd.h> // Should NOT be removed

#if defined(CEU_HAVE_INCLUDE_SYS_UTSNAME_H) && CEU_HAVE_INCLUDE_SYS_UTSNAME_H == 1
#include <sys/utsname.h>
#endif
#endif

#if defined(CEU_HAVE_INCLUDE_CYGWIN_VERSION_H) && CEU_HAVE_INCLUDE_CYGWIN_VERSION_H == 1
#include <cygwin/version.h>
#endif

ceu_ystr_t* get_compile_time_cygwin_version(void)
{
#if defined(CEU_ON_CYGWIN_LIKE)
#if defined(CEU_HAVE_INCLUDE_CYGWIN_VERSION_H) && CEU_HAVE_INCLUDE_CYGWIN_VERSION_H == 1
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr("CYGWIN API ver. undefined\n\tCYGWIN DLL (undefined) ver. undefined");
#else
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("CYGWIN API ver. ", 128);
    ceu_ystr_t* cygwin_api_ver = convert_version_to_ystr2(CYGWIN_VERSION_API_MAJOR, CYGWIN_VERSION_API_MINOR);
    ceu_ystr_t* cygwin_dll_ver = convert_version_to_ystr2(CYGWIN_VERSION_DLL_MAJOR, CYGWIN_VERSION_DLL_MINOR);
    ceu_ystr_concat_inplace(rets, cygwin_api_ver);
    ceu_ystr_cstr_concat_inplace(rets, ", with dll (");
    ceu_ystr_cstr_concat_inplace(rets, CYGWIN_VERSION_DLL_IDENTIFIER);
    ceu_ystr_cstr_concat_inplace(rets, ") ver. ");
    ceu_ystr_concat_inplace(rets, cygwin_dll_ver);
    ceu_ystr_destroy(cygwin_dll_ver);
    ceu_ystr_destroy(cygwin_api_ver);
#endif
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* get_run_time_haiku_version(void)
{
    return CEU_NULL; // TODO
}

ceu_ystr_t* get_run_time_windows_version(void)
{
    return CEU_NULL; // TODO
}

ceu_ystr_t* get_run_time_posix_uts_info(void)
{
#ifdef CEU_ON_POSIX
#if defined(CEU_HAVE_INCLUDE_SYS_UTSNAME_H) && CEU_HAVE_INCLUDE_SYS_UTSNAME_H == 1
    struct utsname ceu_utsname;
    uname(&ceu_utsname);
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("POSIX UTSINFO='", 128);
    ceu_ystr_t* utsname = ceu_ystr_cstr_join(" ", false, 5, ceu_utsname.sysname, ceu_utsname.nodename,
        ceu_utsname.release, ceu_utsname.version, ceu_utsname.machine);
    ceu_ystr_concat_inplace(rets, utsname);
    ceu_ystr_destroy(utsname);
    return rets;
#else
    return ceu_ystr_create_from_cstr("POSIX UTSINFO=undefined");
#endif
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* get_compile_time_posix_standard(void)
{

#ifdef CEU_ON_POSIX
    ceu_ystr_t* posix1_ver = ceu_ystr_create_from_cstr_guarantee("POSIX.1 Version: ", 128);
#ifdef _POSIX_VERSION
    ceu_ystr_t* posix1_ver_s = ceu_ystr_from_uint(10, _POSIX_VERSION);
#else
    ceu_ystr_t* posix1_ver_s = ceu_ystr_create_from_cstr("undefined");
#endif
    ceu_ystr_concat_inplace(posix1_ver, posix1_ver_s);
    ceu_ystr_destroy(posix1_ver_s);

    ceu_ystr_t* posix2_ver = ceu_ystr_create_from_cstr_guarantee("POSIX.2 Version: ", 128);
#ifdef _POSIX2_VERSION
    ceu_ystr_t* posix2_ver_s = ceu_ystr_from_uint(10, _POSIX2_VERSION);
#else
    ceu_ystr_t* posix2_ver_s = ceu_ystr_create_from_cstr("undefined");
#endif
    ceu_ystr_concat_inplace(posix1_ver, posix2_ver_s);
    ceu_ystr_destroy(posix2_ver_s);

    ceu_ystr_t* sus_ver = ceu_ystr_create_from_cstr_guarantee("Single UNIX Specification (SUS) Version: ", 128);
#ifdef _XOPEN_VERSION
    ceu_ystr_t* sus_ver_s = ceu_ystr_from_uint(10, _POSIX2_VERSION);
#elif defined(_XOPEN_UNIX)
    ceu_ystr_t* sus_ver_s = ceu_ystr_create_from_cstr("unknown");
#else
    ceu_ystr_t* sus_ver_s = ceu_ystr_create_from_cstr("undefined");
#endif
    ceu_ystr_concat_inplace(sus_ver, sus_ver_s);
    ceu_ystr_destroy(sus_ver_s);

    ceu_ystr_t* sep = ceu_ystr_create_from_cstr("\n\t");
    ceu_ystr_t* rets = ceu_ystr_join(sep, false, 3, posix1_ver, posix2_ver, sus_ver);
    ceu_ystr_destroy(sep);
    ceu_ystr_destroy(posix1_ver);
    ceu_ystr_destroy(posix2_ver);
    ceu_ystr_destroy(sus_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* ceu_check_get_compile_time_os_info(void)
{
    ceu_ystr_t* haiku_version_buff = get_run_time_haiku_version();
    ceu_ystr_t* cygwin_version_buff = get_compile_time_cygwin_version();
    ceu_ystr_t* posix_version_buff = get_compile_time_posix_standard();
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Compile-time OS info: '", 128);
    ceu_ystr_cstr_concat_inplace(rets, CEU_PRIMARY_OS_TYPE);
    ceu_ystr_cstr_concat_inplace(rets, "'\n\t");
    ceu_ystr_t* sep = ceu_ystr_create_from_cstr("\n\t");
    ceu_ystr_t* info = ceu_ystr_join(sep, true, 3, haiku_version_buff, cygwin_version_buff, posix_version_buff);
    ceu_ystr_concat_inplace(rets, info);
    ceu_ystr_destroy(cygwin_version_buff);
    ceu_ystr_destroy(haiku_version_buff);
    ceu_ystr_destroy(posix_version_buff);
    ceu_ystr_destroy(sep);
    ceu_ystr_destroy(info);
    return rets;
}

ceu_ystr_t* ceu_check_get_run_time_os_info(void)
{
    ceu_ystr_t* posix_uts_buff = get_run_time_posix_uts_info();
    ceu_ystr_t* windows_buff = get_run_time_windows_version();
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Run-time OS info: '", 128);
    ceu_ystr_cstr_concat_inplace(rets, CEU_PRIMARY_OS_TYPE);
    ceu_ystr_cstr_concat_inplace(rets, ")\n\t");
    ceu_ystr_t* sep = ceu_ystr_create_from_cstr("\n\t");
    ceu_ystr_t* info = ceu_ystr_join(sep, true, 2, posix_uts_buff, windows_buff);
    ceu_ystr_concat_inplace(rets, info);
    ceu_ystr_destroy(windows_buff);
    ceu_ystr_destroy(posix_uts_buff);
    ceu_ystr_destroy(sep);
    ceu_ystr_destroy(info);
    return rets;
}
