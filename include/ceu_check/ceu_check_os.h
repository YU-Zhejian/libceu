#ifndef CEU_CHECK_OS_H
#define CEU_CHECK_OS_H
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__MSYS__)
#define CEU_PRIMARY_OS_TYPE "MSYS"
#define CEU_ON_MSYS
#endif

#if defined(__CYGWIN__)
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "CYGWIN"
#endif
#define CEU_ON_CYGWIN
#endif

#if defined(__MINGW32__) || defined(__WINNT__) || defined(__WINNT)
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "MINGW32"
#endif
#define CEU_ON_MINGW32
#endif

#if defined(CEU_ON_CYGWIN) || defined(CEU_ON_MINGW32) || defined(CEU_ON_MSYS)
#define CEU_ON_CYGWIN_LIKE
#endif

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
#define CEU_ON_WINDOWS_64
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 64"
#endif
#elif (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)) && !defined(CEU_PRIMARY_OS_TYPE)
#define CEU_ON_WINDOWS_32
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 32"
#endif
#endif

#if defined(CEU_ON_WINDOWS_32) || defined(CEU_ON_WINDOWS_64)
#define CEU_ON_WINDOWS
#endif

#if defined(__MACH__)
#define CEU_ON_MACH
#if defined(__APPLE__)
#define CEU_ON_APPLE
#include <TargetConditionals.h> // FIXME: Whether this file exists is unsure.
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
#elif defined(__gnu_hurd__)
#define CEU_ON_GNU_HURD
#define CEU_PRIMARY_OS_TYPE "GNU Hurd"
#else
#define CEU_PRIMARY_OS_TYPE "MACH UNKNOWN"
#endif
#endif

#if defined(__linux) || defined(__linux__) || defined(linux) || defined(__gnu_linux__)
#define CEU_ON_GNU_LINUX
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "GNU/Linux"
#endif
#endif

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
#elif defined(BSD)
#define CEU_ON_BSD
#define CEU_PRIMARY_OS_TYPE "Other BSD"
#endif

#if defined(__sun) && defined(__SVR4)
#define CEU_ON_SOLARIS
#define CEU_PRIMARY_OS_TYPE "Solaris"
#endif

#if defined(__HAIKU__)
#define CEU_ON_HAIKU
#define CEU_PRIMARY_OS_TYPE "HAIKU"
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

#if defined(__unix__) || defined(__unix) || defined(unix) || defined(_unix) || defined(_unix_) || defined(__APPLE__) || defined(__MACH__)
#define CEU_ON_UNIX
#endif

#ifdef CEU_ON_UNIX
#if defined(CEU_ON_APPLE) || defined(CEU_ON_GNU_LINUX) || defined(CEU_ON_BSD) || defined(CEU_ON_ANDROID) || defined(CEU_ON_AIX) || defined(CEU_ON_SOLARIS) || defined(CEU_ON_HP_UX)
#else
#define CEU_ON_OTHER_UNIX
#endif
#define CEU_ON_UNIX_LIKE
#endif

#if defined(CEU_ON_UNIX_LIKE) || defined(CEU_ON_CYGWIN_LIKE)
#define CEU_ON_POSIX
#endif

#if defined(__WINE__)
#define CEU_ON_WINE
#endif

#ifndef CEU_PRIMARY_OS_TYPE
#ifdef CEU_ON_UNIX
#define CEU_PRIMARY_OS_TYPE "Other UNIX"
#else
#define CEU_PRIMARY_OS_TYPE "UNKNOWN"
#endif
#endif

/**
 * Get a nicely-formatted compile-time operating system information.
 */
char* ceu_check_get_compile_time_os_info(void);

/**
 * Get a nicely-formatted run-time operating system information.
 */
char* ceu_check_get_run_time_os_info(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_OS_H
