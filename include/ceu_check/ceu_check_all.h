#ifndef CEU_CHECK_ALL_H
#define CEU_CHECK_ALL_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

CEU_BEGIN_C_DECLS
/*!
 *
 * @brief Get all environment information.
 */
ceu_ystr_t* ceu_check_get_full_info CEU_PARAMS((void));

CEU_END_C_DECLS
#endif // CEU_CHECK_ALL_H
