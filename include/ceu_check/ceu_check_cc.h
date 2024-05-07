/*!
 * @file ceu_check_cc.h
 * @brief Header to get compiler information at compile time
 *
 * @see https://sourceforge.net/p/predef/wiki/Architectures/
 */

#ifndef CEU_CHECK_CC_H
#define CEU_CHECK_CC_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_check/ceu_check_cc_macro.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

CEU_BEGIN_C_DECLS

/*!
 * @brief Get a string describing compiler version.
 *
 * @return Returned buffer, should be freed manually. Would be CEU_NULL on error.
 */
ceu_ystr_t* ceu_check_interpret_compiler_version_number CEU_PARAMS((void));

/*!
 * @brief Get compiling date & time, and write them to buffer.
 *
 * @return Returned buffer, should be freed manually. Would be CEU_NULL on error.
 */
ceu_ystr_t* ceu_check_interpret_compilation_date_time CEU_PARAMS((void));

/*!
 * @brief Get compiler information.
 *
 * @param Returned buffer, should be freed manually.
 */
ceu_ystr_t* ceu_check_get_compiler_info CEU_PARAMS((void));

CEU_END_C_DECLS

#endif // CEU_CHECK_CC_H
