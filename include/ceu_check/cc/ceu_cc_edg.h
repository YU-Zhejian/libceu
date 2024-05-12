/*!
 * @file ceu_cc_edg.h
 * @brief Compiler frontend by Edison Design Group (EDG).
 */
#ifndef CEU_CC_EDG_H
#define CEU_CC_EDG_H

/*!
 * @def CEU_COMPILER_IS_EDG
 * @brief If this macro is defined, the compiler should support EDG features.
 */

#ifndef CEU_CHECK_CC_MACRO_H
#error "Do not include this file, include <ceu_check/ceu_check_cc_macro.h> instead!"
#endif

#if defined(__EDG__)
#define CEU_COMPILER_IS_EDG
// Do not define compiler name since there are multiple compilers that uses EDG frontend.
#endif
#endif
