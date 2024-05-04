#ifndef CEU_CHECK_OS_H
#define CEU_CHECK_OS_H

#undef CEU_PRIMARY_OS_TYPE

// Inclusion order of following lines should be preserved
// clang-format off
#include "os/ceu_os_mainframe_unix.h" // NOLINT
#include "os/ceu_os_bsd.h" // NOLINT
#include "os/ceu_os_windows.h" // NOLINT
// clang-format on

/**
 *@def CEU_ON_HAIKU
 *@brief Indicating CEU is compiled on Haiku.
 */
#if defined(__HAIKU__)
#define CEU_ON_HAIKU
#define CEU_PRIMARY_OS_TYPE "Haiku"
#endif

/**
 *@def __ANDROID__
 *@brief Indicating CEU is compiled on Android.
 */
#if defined(__ANDROID__)
#define CEU_ON_ANDROID
#define CEU_PRIMARY_OS_TYPE "Android"
#endif

/**
 *@def CEU_PRIMARY_OS_TYPE
 *@brief A human-readable operating system name.
 */

/**
 *@def CEU_ON_MACH
 *@brief Indicating CEU is compiled on MACH macro kernel.
 */
/**
 *@def CEU_ON_APPLE
 *@brief Indicating CEU is compiled on Apple.
 */
/**
 *@def CEU_ON_GNU_HURD
 *@brief Indicating CEU is compiled on GNU Hurd.
 */

#if defined(__MACH__)
#define CEU_ON_MACH
#if defined(__APPLE__)
#define CEU_ON_APPLE
#elif defined(__gnu_hurd__)
#define CEU_ON_GNU_HURD
#define CEU_PRIMARY_OS_TYPE "GNU Hurd"
#else
#define CEU_PRIMARY_OS_TYPE "MACH UNKNOWN"
#endif
#endif

/**
 *@def CEU_ON_GNU_LINUX
 *@brief Indicating CEU is compiled on GNU/Linux.
 */

#if defined(__linux) || defined(__linux__) || defined(linux) || defined(__gnu_linux__)
#define CEU_ON_GNU_LINUX
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "GNU/Linux"
#endif
#endif

#if defined(__unix__) || defined(__unix) || defined(unix) || defined(_unix) || defined(_unix_) || defined(CEU_ON_MACH) || defined(CEU_ON_GNU_LINUX) || defined(CEU_ON_BSD) || defined(CEU_ON_SOLARIS) || defined(CEU_ON_HP_UX) || defined(CEU_ON_AIX)
#define CEU_ON_UNIX
#endif

#if defined(CEU_ON_UNIX) || defined(CEU_ON_CYGWIN_LIKE)
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

#ifdef __cplusplus
extern "C" {
#endif
#include "ceu_ystrlib/ceu_ystrlib.h"
/*!
 * Get a nicely-formatted compile-time operating system information.
 */
ceu_ystr_t* ceu_check_get_compile_time_os_info(void);

/*!
 * Get a nicely-formatted run-time operating system information.
 */

ceu_ystr_t* ceu_check_get_run_time_os_info(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_OS_H
