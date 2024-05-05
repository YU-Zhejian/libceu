/*!
 * @file ceu_cc_gcc.h
 * @brief Detect whether the compiler is GNU GCC and G++
 */

/*!
 * @def CEU_COMPILER_IS_GCC
 * @brief If this macro is defined, the compiler should support GCC/G++ features.
 */
#ifndef CEU_CC_GCC_H
#define CEU_CC_GCC_H

#ifndef CEU_CHECK_CC_H
#error "Do not include this file, include <ceu_check/ceu_check_cc.h> instead!"
#endif

#if defined(__GNUC__)
#define CEU_COMPILER_IS_GCC
#if !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_NAME "GCC"
#endif
#endif
#endif
