/*!
 * @file ceu_cc_nvhpc.h
 * @brief For NVidia HPC (NVHPC) Toolkit NVC++
 */
#ifndef CEU_CC_NVHPC_H
#define CEU_CC_NVHPC_H

/*!
 * @def CEU_COMPILER_IS_NVHPC
 * @brief If this macro is defined, the compiler should support NVHPC features.
 */

#ifndef CEU_CHECK_CC_MACRO_H
#error "Do not include this file, include <ceu_check/ceu_check_cc_macro.h> instead!"
#endif

#if defined(__NVCOMPILER_MAJOR__)
#define CEU_COMPILER_IS_NVHPC
#define CEU_COMPILER_NAME "NVidia High Performance Computing (NVHPC) Toolkit NVC++"
#endif

#endif
