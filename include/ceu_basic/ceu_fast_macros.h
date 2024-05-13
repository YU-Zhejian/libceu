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
 * @brief Get the larger value of two integers, either signed or unsigned, of the same type.
 *
 * @see `MAX` macro in [GCC](https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Min-and-Max.html).
 * @see `__max` macro in [MSVC <stdlib.h>](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/max).
 *
 * @warning Both arguments and the return value must be of the same data type. Other wise its correctness cannot be guaranteed.
 * @warning GNU C Comiler also defines similiar macros `MIN` and `MAX` with following warnings:
 * > However, side effects in `X` or `Y` may cause unintended behavior. For example, `MIN (i++, j++)` will fail, incrementing the smaller counter twice.
 */
#define CEU_MAX(a, b) ((a) > (b) ? (a) : (b))

/*!
 * @def CEU_ABS
 * @brief Get absolute value for a signed integer.
 */
#define CEU_ABS(x) ((x) < 0 ? -(x) : (x))

/*!
 * @def CEU_MIN
 * @brief Get the smaller value of two integers, either signed or unsigned, of the same type. See #CEU_MAX for further documentations.
 */
#define CEU_MIN(a, b) ((a) < (b) ? (a) : (b))

/*!
 * @def CEU_STRING_ENDING
 * @brief Defines `NULL` for `NULL`-terminated strings.
 */
#define CEU_STRING_ENDING '\0'

/*!
 * @def EXIT_FAILURE
 * @brief POSIX.1 compiliant exit status indicating program failure. Defined as 1 if not defined.
 *
 * You may pre-define this macro if you know your compiler well.
 *
 * @see The exit status described in [POSIX.1 2018](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html) and [cppreference](https://en.cppreference.com/w/c/program/EXIT_status).
 */
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/*!
 * @def EXIT_SUCCESS
 * @brief POSIX.1 compiliant exit status indicating program success. Defined as 0 if not defined. See #EXIT_FAILURE for more details.
 */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifdef CEU_UNDER_DOXYGEN
/*!
 * @def CEU_BEGIN_C_DECLS
 * @brief This macro should be used at the beginning of your declarations,
   so that C++ compilers don't mangle their names.
 *
 * You may pre-define this macro if you know your compiler well.
 * Otherwise its definition will be based on testing of compiler-specific pre-defined macros.
 *
 * Without libCEU, you may:
 *
 * ```c
 * // Inclusion guards, macros, etc.
 *
 * #ifdef __cplusplus
 * extern "C" {
 * #endif
 *
 * // Function prototypes
 *
 * #ifdef __cplusplus
 * }
 * #endif
 * ```
 *
 * With libCEU, it can be simplified to:
 *
 * ```c
 * // Inclusion guards, macros, etc.
 *
 * #include <ceu_basic/ceu_fast_macros.h>
 *
 * CEU_BEGIN_C_DECLS
 *
 * // Function prototypes
 *
 * CEU_END_C_DECLS
 * ```
 *
 * which is much tidier.
 *
 * @see https://www.gnu.org/software/libtool/manual/html_node/C-header-files.html for original description.
 */
#define CEU_BEGIN_C_DECLS /* implementation-defined */

/*!
 * @def CEU_END_C_DECLS
 * @brief This macro should be used at the end of your declarations,
 * so that C++ compilers don't mangle their names. See #CEU_BEGIN_C_DECLS for more details.
 */
#define CEU_END_C_DECLS /* implementation-defined */
#else

#ifndef CEU_BEGIN_C_DECLS
#ifdef __cplusplus
#define CEU_BEGIN_C_DECLS extern "C" {
#else
#define CEU_BEGIN_C_DECLS /* empty */
#endif /* __cplusplus */
#endif /* CEU_BEGIN_C_DECLS */

#ifndef CEU_END_C_DECLS
#ifdef __cplusplus
#define CEU_END_C_DECLS }
#else
#define CEU_END_C_DECLS /* empty */
#endif /* __cplusplus */
#endif /* CEU_END_C_DECLS */
#endif /* CEU_UNDER_DOXYGEN */

/*!
 * @def CEU_UNDER_DOXYGEN
 * @brief Doxygen indicator defined by external Doxyfile.ini.
 * @warning You should NOT define/undefine this macro in your source file! If this macro is detected defined in a compiling environment, it will cause compilation error.
 */
#ifdef CEU_UNDER_DOXYGEN
#error "Refuse to compile under Doxygen" // Which will be ignored by Doxygen but recognized by compilers.
// Re-define this macro to amke it visible under Doxygen
#undef CEU_UNDER_DOXYGEN
#define CEU_UNDER_DOXYGEN 1
#endif

#ifdef CEU_UNDER_DOXYGEN
/*!
 * @def CEU_PARAMS
 * @brief A macro used to wrap function prototypes for compatibility isues of non-ANSI compiler.
 *
 * This macro would let the compilers that don't understand ANSI C prototypes still work,
 * while ANSI C compilers can issue warnings about type mismatches.
 *
 * You may pre-define this macro if you know your compiler well.
 * Otherwise its definition will be based on testing of compiler-specific pre-defined macros.
 *
 * @see https://www.gnu.org/software/libtool/manual/html_node/C-header-files.html
 */
#define CEU_PARAMS(protos) protos
#endif
#ifndef CEU_PARAMS
#if defined __STDC__ || defined _AIX             \
    || (defined __mips && defined _SYSTYPE_SVR4) \
    || defined WIN32 || defined __cplusplus
#define CEU_PARAMS(protos) protos
#else
#define CEU_PARAMS(protos) ()
#endif
#endif

#define CEU_STR(x) CEU_VAL(x)
#define CEU_VAL(x) #x

#endif // CEU_FAST_MACROS_H
