/*!
 * @file ceu_check_cc.h
 * @brief Header to get compiler information at compile time
 *
 * @see https://sourceforge.net/p/predef/wiki/Architectures/
 */

#ifndef CEU_CHECK_CC_H
#define CEU_CHECK_CC_H

/*!
 * @def CEU_COMPILER_NAME
 * @brief Human-readable compiler name.
 */

// Undefine conflicting macros
#ifdef CEU_COMPILER_NAME
#undef CEU_COMPILER_NAME
#endif

// Inclusion order of following lines should be preserved
// clang-format off
#include "cc/ceu_cc_turboc.h" // NOLINT
#include "cc/ceu_cc_icc.h" // NOLINT
#include "cc/ceu_cc_intel_clang.h" // NOLINT
#include "cc/ceu_cc_msvc.h" // NOLINT
#include "cc/ceu_cc_nvhpc.h" // NOLINT
#include "cc/ceu_cc_tcc.h" // NOLINT
#include "cc/ceu_cc_clang.h" // NOLINT
#include "cc/ceu_cc_gcc.h" // NOLINT
#include "cc/ceu_cc_unknown.h" // NOLINT
// clang-format on

#include "ceu_ystrlib/ceu_ystrlib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Get a string describing compiler version.
 *
 * @return Returned buffer, should be freed manually. Would be CEU_NULL on error.
 */
ceu_ystr_t* ceu_check_interpret_compiler_version_number(void);

/*!
 * @brief Get compiling date & time, and write them to buffer.
 *
 * @return Returned buffer, should be freed manually. Would be CEU_NULL on error.
 */
ceu_ystr_t* ceu_check_interpret_compilation_date_time(void);

/*!
 * @brief Get compiler information.
 *
 * @param Returned buffer, should be freed manually.
 */
ceu_ystr_t* ceu_check_get_compiler_info(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_CC_H
