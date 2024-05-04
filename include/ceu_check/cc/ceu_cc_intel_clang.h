/*!
 *@file ceu_cc_intel_clang.h
 * @brief For Intel OneAPI Clang
 */
#ifndef CEU_CC_INTEL_CLANG_H
#define CEU_CC_INTEL_CLANG_H

/**
 *@def CEU_COMPILER_IS_INTEL_CLANG
 *@brief If this macro is defined, the compiler should support Intel Clang features.
 */

#ifndef CEU_CHECK_CC_H
#error "Do not include this file, include <ceu_check/ceu_check_cc.h> instead!"
#endif
#if defined(__INTEL_CLANG_COMPILER) || defined(__INTEL_LLVM_COMPILER)
#define CEU_COMPILER_IS_INTEL_CLANG
#define CEU_COMPILER_NAME "Intel OneAPI Clang"
#endif
#endif
