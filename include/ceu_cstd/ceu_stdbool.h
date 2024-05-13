/*!
 * @file ceu_stdbool.h
 * @author your name (you@domain.com)
 * @brief Compatible file of <stdbool.h>, providing definition of bool, true, false macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 *
 * @warning This file will be supressed under C++ since in C++ #bool, #true and #false are supported by builtin types.
 * @see [cppreference definition of C++ types](https://en.cppreference.com/w/cpp/language/types).
 * @see [cppreference description of `cstdbool` header](https://en.cppreference.com/w/cpp/header/cstdbool).
 * @see [cppreference description of C types](https://en.cppreference.com/w/c/types).
 * @see [cppreference description of C arithmetic types](https://en.cppreference.com/w/c/language/arithmetic_types).
 * @see [POSIX.1 2018 definition of `stdbool.h` header](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdbool.h.html).
 * @see [`bool` type in _GNU C Language Manual_](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Boolean-Type.html).
 */

#ifndef CEU_STDBOOL_H
#define CEU_STDBOOL_H

#if defined(CEU_UNDER_DOXYGEN)

/*!
 * @def bool
 * @brief The boolean type.
 *
 * - If `_Bool` is defined, will expand to `_Bool`.
 * - Otherwise, will fall back to `int`.
 *
 * @warning Only convert 0/1 to boolean values. Result from other integers (e.g., 4, -4, etc.) are unknown.
 */
#define bool /* implementation-defined */

/*!
 * @def true
 * @brief The boolean value `true`.
 *
 * Expand to integer constant 1.
 */
#define true 1

/*!
 * @def false
 * @brief The boolean value `false`.
 *
 * Expand to integer constant 0.
 */
#define false 0

/*!
 * @def __bool_true_false_are_defined
 * @brief To keep it POSIX-compiliant.
 */
#define __bool_true_false_are_defined 1

/*!
 * @def _STDBOOL
 * @brief To keep it POSIX-compiliant.
 */
#define _STDBOOL
#elif defined(__cplusplus)
// Supress definition of bool under C++.
#else

#include <ceu_basic/libceu_stddef_dispatcher.h>

#ifndef CEU_CM_HAVE_WORKING_C__BOOL_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C__BOOL_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C__BOOL_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C__BOOL_RUN_SHARED 127
#endif

#ifndef CEU_CM_HAVE_WORKING_C_BOOL_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C_BOOL_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_BOOL_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_BOOL_RUN_SHARED 127
#endif

#if (defined(CEU_HAVE_INCLUDE_STDBOOL_H) && CEU_HAVE_INCLUDE_STDBOOL_H == 1 && CEU_CM_HAVE_WORKING_C_BOOL_RUN_STATIC * CEU_CM_HAVE_WORKING_C_BOOL_RUN_SHARED == 0)
// Normal condition where stdbool.h is available and compatible
#include <stdbool.h>

#else
// Define our own stdbool.h
#ifndef _STDBOOL
#define _STDBOOL

#ifndef __bool_true_false_are_defined

#define __bool_true_false_are_defined 1
#if (CEU_CM_HAVE_WORKING_C__BOOL_RUN_STATIC * CEU_CM_HAVE_WORKING_C__BOOL_RUN_SHARED == 0)
// If _Bool is available.
#define bool _Bool
// Fallback to int.
#else
#define bool int
#endif

#define false 0
#define true 1
#endif // !__bool_true_false_are_defined

#endif /* _STDBOOL */
#endif /* have working stdbool.h */
#endif /* CEU_UNDER_DOXYGEN */
#endif /* CEU_STDBOOL_H */
