/*****************************************************************//**
 * @file   check_os.h
 * @brief  Functions to detect run-time and compile-time operating system
 * 
 * @author yuzj
 * @date   April 2022
 * 
 * We would made following hypothesis:
 * 1. Run-time operating system is similiar to compile-time operating system.
 * They should be in a operating system family but can be in different distribution.
 *********************************************************************/

#include "ceu_check/ceu_append_sprintf.h"

#ifndef CEU_CHECK_OS_H
#define CEU_CHECK_OS_H


#if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
#define CEU_ON_WINDOWS_64
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 64"
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#define CEU_ON_WINDOWS_32
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 32"
#endif

#if defined(CEU_ON_WINDOWS_32) || defined(CEU_ON_WINDOWS_64)
#define CEU_ON_WINDOWS
#endif


#if defined(__unix__) || defined(__unix) || defined(unix) || defined(_unix) || defined(_unix_) || defined(__APPLE__) || defined(__MACH__)
#define CEU_ON_UNIX
#include <sys/param.h>
#endif

#if defined(__APPLE__) || defined(__MACH__)
#define CEU_ON_APPLE
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
#define CEU_ON_APPLE_IOS
#define CEU_PRIMARY_OS_TYPE "Apple IOS"
#elif TARGET_OS_MAC == 1
#define CEU_ON_APPLE_MACOSX
#define CEU_PRIMARY_OS_TYPE "Apple MacOSX"
#else
#define CEU_ON_APPLE_UNKNOWN
#define CEU_PRIMARY_OS_TYPE "Apple UNKNOWN"
#endif
#endif

#if defined(__linux) || defined(__linux__) || defined(linux) || defined(__gnu_linux__)
#define CEU_ON_GNU_LINUX
#define CEU_PRIMARY_OS_TYPE "GNU/Linux"
#endif

#if defined(BSD)
#define CEU_ON_BSD
#if defined(__FreeBSD__)
#define CEU_ON_FreeBSD
#define CEU_PRIMARY_OS_TYPE "Free BSD"
#elif defined(__DragonFly__)
#define CEU_ON_DragonFlyBSD
#define CEU_PRIMARY_OS_TYPE "DragonFly BSD"
#elif defined(__NetBSD__)
#define CEU_ON_NetBSD
#define CEU_PRIMARY_OS_TYPE "NetBSD"
#elif defined(__OpenBSD__)
#define CEU_ON_OpenBSD
#define CEU_PRIMARY_OS_TYPE "OpenBSD"
#endif
#endif


#if defined(__sun) && defined(__SVR4)
#define CEU_ON_SOLARIS
#define CEU_PRIMARY_OS_TYPE "Solaris"
#endif


#if defined(__ANDROID__)
#define CEU_ON_ANDROID
#define CEU_PRIMARY_OS_TYPE "Android"
#endif

#if defined(__hpux)
#define CEU_ON_HP_UX
#define CEU_PRIMARY_OS_TYPE "HP-UX"
#endif

#if defined(_AIX)
#define CEU_ON_AIX
#define CEU_PRIMARY_OS_TYPE "IBM AIX"
#endif

#ifdef CEU_ON_UNIX
#if defined(CEU_ON_APPLE) || \
defined(CEU_ON_GNU_LINUX) || \
defined(CEU_ON_BSD) || \
defined(CEU_ON_ANDROID) || \
defined(CEU_ON_AIX) || \
defined(CEU_ON_SOLARIS) || \
defined(CEU_ON_HP_UX)
#else
#define CEU_ON_OTHER_UNIX
#endif
#define CEU_ON_UNIX_LIKE
#endif

#if defined(__CYGWIN__)
#define CEU_PRIMARY_OS_TYPE "CYGWIN"
#define CEU_ON_CYGWIN
#endif

#if defined(__MINGW32__) || defined(__WINNT__) || defined(__WINNT)
#define CEU_PRIMARY_OS_TYPE "MINGW32"
#define CEU_ON_MINGW32
#endif

#if defined(CEU_ON_CYGWIN) || defined(CEU_ON_MINGW32)
#define CEU_ON_CYGWIN_LIKE
#endif

#if defined(CEU_ON_UNIX_LIKE) || defined(CEU_ON_CYGWIN_LIKE)
#define CEU_ON_POSIX
#endif

#if defined(__WINE__)
#define CEU_ON_WINE
#endif


#ifndef CEU_PRIMARY_OS_TYPE
#ifdef CEU_ON_UNIX
#define CEU_PRIMARY_OS_TYPE "UNKNWON_UNIX"
#else
#define CEU_PRIMARY_OS_TYPE "UNKNOWN"
#endif
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
* Get a nicely-formatted compile-time operating system information.
*/
static inline void get_os_info(char *buff)
{
    append_sprintf(buff, "%sCompile-time info: On operating system %s", buff, CEU_PRIMARY_OS_TYPE);
    append_sprintf(buff, "%s\n", buff);
}


#ifdef CEU_ON_POSIX
#include <sys/utsname.h>
#endif

#ifdef CEU_ON_WINDOWS
// #include <VersionHelpers.h> // TODO: Have bugs?
/**
 * Get windows version information.
 * 
 * TODO: Maybe deprecated.
 */
static inline void inteprete_windows_version_info(char* buff) {
    char* version_str = "Currently unsupported";
    append_sprintf(buff, "%sWindows ver. %s", buff, version_str);
}


#endif


/**
* Get a nicely-formatted run-time operating system information.
*/
static inline void get_runtime_os_info(char *buff)
{
    append_sprintf(buff, "%sRun-time info: ", buff);
#if defined(CEU_ON_POSIX)
    struct utsname ceu_utsname;
    uname(&ceu_utsname);
    append_sprintf(
        buff,
        "%sPOSIX UTSINFO=\'%s %s %s %s %s\'",
        buff,
        ceu_utsname.sysname,
        ceu_utsname.nodename,
        ceu_utsname.release,
        ceu_utsname.version,
        ceu_utsname.machine
    );
#elif defined (CEU_ON_WINDOWS)
    inteprete_windows_version_info(buff);
#else
    append_sprintf(buff, "%sunsupported onerting system", buff);
#endif
    append_sprintf(buff, "%s\n", buff);
}

#ifdef __cplusplus
}
#endif

#endif //CEU_CHECK_OS_H
