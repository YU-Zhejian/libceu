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

#include <stdbool.h>
#include "ceu_check/ceu_c_utils.h"

// Undefine conflicting macros
#ifdef CEU_COMPILER_NAME
#undef CEU_COMPILER_NAME
#endif

// Undefine conflicting macros
#ifdef CEU_COMPILER_VERSION
#undef CEU_COMPILER_VERSION
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * @brief whether compiler have version greater or equal than given version.
 *
 * @details Would check compiler version with target ones.
 *
 * @param major The first digit of corresponding version number.
 * Not used when CEU_COMPILER_IS_UNKNOWN.
 * @param minor The second digit of corresponding version number.
 * 	Not used when CEU_COMPILER_IS_TINYCC and CEU_COMPILER_IS_UNKNOWN
 * @param patchlevel The third digit of corresponding version number.
 * Not used when CEU_COMPILER_IS_MSVC, CEU_COMPILER_IS_BORLAND, CEU_COMPILER_IS_TINYCC, CEU_COMPILER_IS_ICC and CEU_COMPILER_IS_UNKNOWN.
 */
bool check_compiler_version(int major, int minor, int patchlevel);

/*!
 * @brief Get a string describing compiler version.
 *
 * @return Returned buffer, should be freed manually. Would be NULL on error.
 */
char* interpret_compiler_version_number(void);

// TODO: __PGIC__
#include "cc/ceu_cc_nvhpc.h"
#include "cc/ceu_cc_tcc.h"
#include "cc/ceu_cc_turboc.h"
#include "cc/ceu_cc_icc.h"
#include "cc/ceu_cc_msvc.h"
#include "cc/ceu_cc_clang.h"
#include "cc/ceu_cc_gcc.h"
#include "cc/ceu_cc_unknown.h"

/*!
 * @brief Get compiling date & time, and write them to buffer.
 *
 * @return Returned buffer, should be freed manually. Would be NULL on error.
 */
char* interpret_compilation_date_time(void);

/*!
 * @brief Get compiler information.
 *
 * @param Returned buffer, should be freed manually.
*/
char* get_compiler_info(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_CC_H
