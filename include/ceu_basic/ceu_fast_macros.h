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

#undef CEU_BEGIN_C_DECLS
#undef CEU_END_C_DECLS

/*!
 * @def CEU_BEGIN_C_DECLS
 * @brief This macro should be used at the beginning of your declarations,
   so that C++ compilers don't mangle their names.
 */
/*!
 * @def CEU_END_C_DECLS
 * @brief This macro should be used at the end of your declarations,
 * so that C++ compilers don't mangle their names.
 */

#ifdef __cplusplus
#define CEU_BEGIN_C_DECLS extern "C" {
#define CEU_END_C_DECLS }
#else
#define CEU_BEGIN_C_DECLS /* empty */
#define CEU_END_C_DECLS /* empty */
#endif

/*!
 * @def CEU_PARAMS
 * @brief A macro used to wrap function prototypes.
 * So that compilers that don't understand ANSI C prototypes still work,
 * and ANSI C compilers can issue warnings about type mismatches.
 */
#undef CEU_PARAMS
#if defined __STDC__ || defined _AIX             \
    || (defined __mips && defined _SYSTYPE_SVR4) \
    || defined WIN32 || defined __cplusplus
#define CEU_PARAMS(protos) protos
#else
#define CEU_PARAMS(protos) ()
#endif

#endif // CEU_FAST_MACROS_H
