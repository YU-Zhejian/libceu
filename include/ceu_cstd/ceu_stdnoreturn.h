/*!
 * @file ceu_stdnoreturn.h
 * @author YU Zhejian
 * @brief Compatible file of <stdnoreturn.h>, providing definition of noreturn macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 *
 * This file is expected to mimic the behaviour of noreturn ketyword in ISO C11.
 * And it should correctly handle scenarios like being included in a C++ compilation unit.
 */

/*!
 * @def noreturn
 * @brief A macro that indicates that the function never returns.
 *
 * @todo Deal with noreturn in C++.
 * @todo Check for `[[noreturn]]` in C++ 23.
 *
 * Would be expanded to:
 *
 * - `_Noreturn`, if exists.
 * - `__attribute__((noreturn))`, if supports.
 * - Nothing as fallback.
 */

#ifndef CEU_STDNORETURN_H
#define CEU_STDNORETURN_H
#include "ceu_check/ceu_check_cc_macro.h"

#ifdef __cplusplus
// FIXME: Temporary solution for C++ 11.
// FIXME: Error of previous FIXME: This won't work on Microsoft Visual Studio 2010 which does not support C++ 11.
#define noreturn // [[noreturn]]
#elif defined(CEU_COMPILER_IS_INTEL_CLANG) && defined(CEU_COMPILER_IS_MSVC)
// FIXME: Error on Windows Intel Clang-based compilers.
#define noreturn // NOLINT
#else

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED
#define CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC
#define CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC 127
#endif

#if (defined(CEU_HAVE_INCLUDE_STDNORETURN_H) && CEU_HAVE_INCLUDE_STDNORETURN_H == 1 && CEU_CM_HAVE_WORKING_C_NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED == 0)
#include <stdnoreturn.h> // This file should define noreturn
#elif (CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC * CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED == 0)
// FIXME: No idea whether this works.
#define noreturn [[noreturn]]
#elif (CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC == 0)
// Normal condition where _Noreturn is supported
#define noreturn _Noreturn
#elif (CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC * CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED == 0)
// Normal condition where __attribute__((noreturn)) is supported
#define noreturn __attribute__((noreturn))
#else
// Have nothing!
#define noreturn // NOLINT
// FIXME: Visual Studio 2010 does not support this preprocessor derivitive.
// #warning "Noreturn not supported by the compiler."
#endif
#endif
#endif
