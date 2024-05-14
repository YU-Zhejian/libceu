/*!
 * @file ceu_stdbool.h
 * @author your name (you@domain.com)
 * @brief Compatible file of <stdbool.h>, providing definition of bool, true, false macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 *
 * ## Rule of Thumb
 *
 * - This file ensures the existance of #bool, #true and #false. It ensure that #true are equal to 1 and #false are equal to 0.
 * - However, it cannot ensure `sizeof(bool) == 1` or `bool x = 4; x == 1` (Converting any nonzero value to `bool` results in 1.), which should be true in standard C99 `_Bool`.
 * - On any `if` statement, 0 is evaluated to false while any other thing (including NAN) is evaluated to true.
 * - C99 `stdbool.h` defines #true and #false as macros that expands to `1` and `0`, which are **integer literals**.
 * - Some people implement boolean type using `char`, either signed or unsigned. We will use signed integer as fallback for fastest speed.
 *
 * ## The Evolution of Boolean
 *
 * - Keyword `_Bool` were defined in C99 and retired on C23. [cppreference](https://en.cppreference.com/w/c/keyword/_Bool)
 * - Macro `bool` were defined as convenience macro that expands to `_Bool` in C99. It is also retired in C23.
 * - `bool` becomes a keyword in C23.
 * - [POSIX.1 2018](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdbool.h.html) follows ANSI C standard.
 *
 * ## How this File Works
 *
 * - `bool`, `true` and `false` were defined as C++98 keywords and kept afterwards. So if `__cplusplus` macro is detected, will supress the entire file.
 * - Will check whether `stdbool.h` present and work as expected.
 * - Will check whether `_Bool` whatever present and work as expected.
 * - Fallback to `int`, which is signed integer.
 *
 * By saying `work as expected`, we require `sizeof(bool) == 1` and `bool x = 4; x == 1`
 *
 * ## Appendix
 *
 * @see [cppreference definition of C++ types](https://en.cppreference.com/w/cpp/language/types).
 * @see [cppreference description of `cstdbool` header](https://en.cppreference.com/w/cpp/header/cstdbool).
 * @see [cppreference description of C types](https://en.cppreference.com/w/c/types).
 * @see [cppreference description of C arithmetic types](https://en.cppreference.com/w/c/language/arithmetic_types).
 * @see [`bool` type in _GNU C Language Manual_](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Boolean-Type.html).
 */

#ifndef CEU_STDBOOL_H
#define CEU_STDBOOL_H

#if defined(CEU_UNDER_DOXYGEN)

/*!
 * @def bool
 * @brief The boolean type.
 *
 * @warning Only convert 0/1 to boolean values. Result from other values (e.g., 4, -4, 0.5, etc.) are implementation-defined.
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
