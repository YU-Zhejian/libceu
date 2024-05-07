#ifndef CEU_CHECK_OS_H
#define CEU_CHECK_OS_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_check/ceu_check_os_macro.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

CEU_BEGIN_C_DECLS
/*!
 * Get a nicely-formatted compile-time operating system information.
 */
ceu_ystr_t* ceu_check_get_compile_time_os_info CEU_PARAMS((void));

/*!
 * Get a nicely-formatted run-time operating system information.
 */

ceu_ystr_t* ceu_check_get_run_time_os_info CEU_PARAMS((void));

CEU_END_C_DECLS

#endif // CEU_CHECK_OS_H
