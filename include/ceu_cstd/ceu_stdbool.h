/*!
 * @file ceu_stdbool.h
 * @author your name (you@domain.com)
 * @brief Compatible file of <stdbool.h>, providing definition of bool, true, false macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 *
 * ## Rule of Thumb
 *
 * - This file ensures the existance of #ceu_bool, #ceu_true and #ceu_false. It ensure that #ceu_true are equal to 1 and #ceu_false are equal to 0.
 * - However, it cannot ensure `sizeof(bool) == 1` or `bool x = 4; x == 1` (Converting any nonzero value to `bool` results in 1.), which should be true in standard C99 `_Bool`.
 * - On any `if` statement, 0 is evaluated to false while any other thing (including NAN) is evaluated to true.
 * - C99 `stdbool.h` defines #ceu_true and #ceu_false as macros that expands to `1` and `0`, which are **integer literals**.
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
 * - `bool`, `true` and `false` were defined as C++98 keywords and kept afterwards. So if `__cplusplus` macro is detected, `ceu_bool`, `ceu_true` and `ceu_false` will be defined as `bool`, `true` and `false`.
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
// TODO: Check bool keyword for C23.

#if defined(CEU_UNDER_DOXYGEN)

/*!
 * @def ceu_bool
 * @brief The boolean type.
 *
 * @warning Only convert 0/1 to boolean values. Result from other values (e.g., 4, -4, 0.5, etc.) are implementation-defined.
 */
#define ceu_bool /* implementation-defined */

/*!
 * @def ceu_true
 * @brief The boolean value `true`.
 *
 * Expand to integer constant 1.
 */
#define ceu_true 1

/*!
 * @def ceu_false
 * @brief The boolean value `false`.
 *
 * Expand to integer constant 0.
 */
#define ceu_false 0

#elif defined(__cplusplus)
// Supress definition of bool under C++.
#define ceu_bool bool
#define ceu_true true
#define ceu_false false

#else
#include <ceu_basic/libceu_stddef_dispatcher.h>

#ifndef CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_STATIC
#define CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_SHARED
#define CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_SHARED 127
#endif

// Define our own stdbool.h
#if (CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_STATIC * CEU_CM_HAVE_WORKING_C_UNDERLINE_BOOL_KEYWORD_RUN_SHARED == 0)
// If _Bool is available.
#define ceu_bool _Bool
// Fallback to int.
#else
#define ceu_bool int
#endif

#define ceu_false ((ceu_bool) 0)
#define ceu_true ((ceu_bool) 1)

#endif /* __cplusplus */
#endif /* CEU_STDBOOL_H */
