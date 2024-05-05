/*!
 * @file ceu_cc_icc.h
 * @brief Old Intel C/C++ compiler called ICC/ICPC
 * @warning Include this file before "ceu_cc_clang.h"!
 */

/*!
 *@def CEU_COMPILER_IS_ICC
 *@brief If this macro is defined, the compiler should support ICC features.
 */

#ifndef CEU_CC_ICC_H
#define CEU_CC_ICC_H

#ifndef CEU_CHECK_CC_H
#error "Do not include this file, include <ceu_check/ceu_check_cc.h> instead!"
#endif

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define CEU_COMPILER_IS_ICC
#ifdef __llvm__
#define CEU_COMPILER_NAME "ICC with LLVM features"
#else
#define CEU_COMPILER_NAME "ICC"
#endif
#endif
#endif
