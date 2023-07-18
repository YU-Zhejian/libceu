/**
 * @brief Header to get compiler information at compile time
 *
 * @details This header may detect information of C or C++ compilers.
 *
 * Usepackage https://sourceforge.net/p/predef/wiki/Architectures/
 * @def
 */

#ifndef CEU_CHECK_CC_H
#define CEU_CHECK_CC_H

// Undefine conflicting macros
#ifdef CEU_COMPILER_NAME
#undef CEU_COMPILER_NAME
#endif

// Undefine conflicting macros
#ifdef CEU_COMPILER_VERSION
#undef CEU_COMPILER_VERSION
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_cstd/ceu_stdbool.h"
// Inclusion order of following lines should be preserved
// clang-format off
#include "cc/ceu_cc_turboc.h" // NOLINT
#include "cc/ceu_cc_icc.h" // NOLINT
#include "cc/ceu_cc_msvc.h" // NOLINT
#include "cc/ceu_cc_nvhpc.h" // NOLINT
#include "cc/ceu_cc_tcc.h" // NOLINT
#include "cc/ceu_cc_clang.h" // NOLINT
#include "cc/ceu_cc_gcc.h" // NOLINT
#include "cc/ceu_cc_unknown.h" // NOLINT
// clang-format on

/*!
 * @brief Get a string describing compiler version.
 *
 * @return Returned buffer, should be freed manually. Would be NULL on error.
 */
char* interpret_compiler_version_number(void);

/*!
 * @brief Get compiling date & time, and write them to buffer.
 *
 * @return Returned buffer, should be freed manually. Would be NULL on error.
 */
char* ceu_check_interpret_compilation_date_time(void);

/*!
 * @brief Get compiler information.
 *
 * @param Returned buffer, should be freed manually.
 */
char* ceu_check_get_compiler_info(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_CC_H
