/*!
 * @file ceu_fast_macros.h
 * @author YU Zhejian
 * @brief Macro functions and constants defined for convenience.
 * @version 0.1
 * @date 2024-05-02
 */
#ifndef CEU_FAST_MACROS_H
#define CEU_FAST_MACROS_H

/*!
 * @def CEU_MAX
 * @brief Mimics `__max` macro in MSVC <stdlib.h>.
 *
 * @see [MSVC definition]](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/max).
 * @see [GCC definition](https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Min-and-Max.html) for further details.
 *
 * @warning Both arguments and the return value must be of the same data type.
 * @warning GNU C Comiler also defines similiar macros #MIN and #MAX with following warnings:
 * > However, side effects in `X` or `Y` may cause unintended behavior. For example, `MIN (i++, j++)` will fail, incrementing the smaller counter twice.
 */
#define CEU_MAX(a, b) ((a) > (b) ? (a) : (b))
/*!
 * @def CEU_MIN
 * @brief Mimics `__min` macro in MSVC <stdlib.h>.
 *
 * @see [MSVC definition](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/min).
 * @see #CEU_MAX for further documentations.
 */
#define CEU_MIN(a, b) ((a) < (b) ? (a) : (b))

/*!
 * @def CEU_STRING_ENDING
 * @brief Defines NULL for NULL-terminated strings.
 */
#define CEU_STRING_ENDING '\0'

/*!
 * @def EXIT_FAILURE
 * @brief POSIX.1 compiliant exit status indicating program failure. Defined as 1 if not defined.
 *
 * @see [POSIX.1 2008](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html).
 * @see [cppreference](https://en.cppreference.com/w/c/program/EXIT_status).
 */
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/*!
 * @def EXIT_SUCCESS
 * @brief POSIX.1 compiliant exit status indicating program success. Defined as 0 if not defined.
 *
 * @see [POSIX.1 2008](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html).
 * @see [cppreference](https://en.cppreference.com/w/c/program/EXIT_status).
 */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#endif // CEU_FAST_MACROS_H
