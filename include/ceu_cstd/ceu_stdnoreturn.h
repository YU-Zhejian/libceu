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

#ifndef CEU_STDNORETURN_H
#define CEU_STDNORETURN_H

#ifdef noreturn
#else
#include "ceu_check/ceu_check_c_cxx_std_macro.h"
#include "ceu_check/ceu_check_cc_macro.h"
#include "ceu_cstd/ceu_cdefs.h"

#ifdef CEU_UNDER_DOXYGEN

/*!
 * @def noreturn
 * @brief A macro that indicates that the function never returns.
 *
 * Would be expanded to:
 *
 * - `_Noreturn`, if exists.
 * - `__attribute__((noreturn))`, if supports.
 */
#define noreturn /* implementation-defined */
#else

#if defined(__cplusplus)
// FIXME: Temporary solution for C++ 11.
// This won't work on Microsoft Visual Studio 2010 which does not support C++ 11.
#define noreturn // [[noreturn]]
#elif defined(CEU_COMPILER_IS_INTEL_CLANG) && defined(CEU_COMPILER_IS_MSVC)
// FIXME: Error on Windows Intel Clang-based compilers.
#define noreturn // NOLINT
#elif !defined(CEU_C_STD_VERSION_MACRO) || CEU_C_STD_VERSION_MACRO < 201112L
#define noreturn __attribute__((noreturn))
#else

#include <ceu_basic/libceu_stddef_dispatcher.h>

#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C_NORETURN_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C__NORETURN_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C__NORETURN_RUN_SHARED 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED 127
#endif

#if (defined(CEU_HAVE_INCLUDE_STDNORETURN_H) && CEU_HAVE_INCLUDE_STDNORETURN_H == 1 && CEU_CM_HAVE_WORKING_C_NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED == 0)
#include <stdnoreturn.h> // This file should define noreturn
#elif (CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_STATIC * CEU_CM_HAVE_WORKING_C_NORETURN_ATTRIBUTE_RUN_SHARED == 0)
// C23 standard where [[noreturn]] is supported.
// No idea whether this works.
#define noreturn [[noreturn]]
#elif (CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC == 0)
// Normal condition where _Noreturn is supported
#define noreturn _Noreturn
##else
// Have nothing!
// __attribute__ should have been defined in <ceu_cstd/ceu_cdefs.h> or supported by the compiler.
#define noreturn __attribute__((noreturn))

#endif /* CEU_HAVE_INCLUDE_STDNORETURN_H */
#endif /* noreturn */
#endif /* __cplusplus */
#endif /* CEU_UNDER_DOXYGEN */
#endif /* CEU_STDNORETURN_H */
