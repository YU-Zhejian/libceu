/*!
 * @file ceu_cc_tcc.h
 * @brief Tiny C Compiler.
 */
#ifndef CEU_CC_TCC_H
#define CEU_CC_TCC_H

/*!
 * @def CEU_COMPILER_IS_TCC
 * @brief If this macro is defined, the compiler should support TCC features.
 */

#ifndef CEU_CHECK_CC_MACRO_H
#error "Do not include this file, include <ceu_check/ceu_check_cc_macro.h> instead!"
#endif

#if defined(__TINYC__)
#define CEU_COMPILER_IS_TINYCC
#define CEU_COMPILER_NAME "Tiny C Compiler"
#endif
#endif
