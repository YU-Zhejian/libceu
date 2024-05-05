/*!
 * @file ceu_cc_clang.h
 * @brief Original LLVM Clang
 */

/*!
 * @def CEU_COMPILER_IS_CLANG
 * @brief If this macro is defined, the compiler should support Clang features.
 */

#ifndef CEU_CC_CLANG_H
#define CEU_CC_CLANG_H

#ifndef CEU_CHECK_CC_H
#error "Do not include this file, include <ceu_check/ceu_check_cc.h> instead!"
#endif
#undef CEU_COMPILER_IS_CLANG
#if (defined(__clang__))
#define CEU_COMPILER_IS_CLANG
#endif

#if (defined(__clang__) || defined(__llvm__))
#if !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_NAME "Clang"
#endif
#endif
#endif // CEU_CC_CLANG_H
