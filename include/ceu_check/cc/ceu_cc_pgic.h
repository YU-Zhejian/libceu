/*!
 * @file ceu_cc_pgic.h
 * @brief For Portland Group (PGI) C/C++ compilers
 *
 * @warning Include this file after <ceu_cc_nvhpc.h>!
 */
#ifndef CEU_CC_PGIC_H
#define CEU_CC_PGIC_H

/*!
 * @def CEU_COMPILER_IS_PGIC
 * @brief If this macro is defined, the compiler should support PGI features.
 */

#ifndef CEU_CHECK_CC_MACRO_H
#error "Do not include this file, include <ceu_check/ceu_check_cc_macro.h> instead!"
#endif

#if defined(__PGI)
#define CEU_COMPILER_IS_PGIC
#ifndef CEU_COMPILER_NAME
#define CEU_COMPILER_NAME "Portland Group (PGI) C/C++ compilers"
#endif
#endif

#endif
