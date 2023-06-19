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
static inline bool check_compiler_version(int major, int minor, int patchlevel);

/*!
 * @brief Get a string describing compiler version.
 *
 * @return Returned buffer, should be freed manually. Would be NULL on error.
 */
static inline char* interpret_compiler_version_number();

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
static inline char* interpret_compilation_date_time()
{
	int retv;
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
#if defined(__DATE__) && defined(__TIME__)
	retv = snprintf(buff, 256, "%s, %s", __DATE__, __TIME__);
#elif defined(__DATE__)
	retv = snprintf(buff, 256, "%s, unknown time", __DATE__);
#else
	retv = snprintf(buff, 256, "unknown date & time");
#endif
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

/*!
 * @brief Get compiler information.
 *
 * @param Returned buffer, should be freed manually.
*/
static inline char* get_compiler_info()
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 1024);
	int retv;
	char* date_time_buff = interpret_compilation_date_time();
	if (date_time_buff == NULL)
	{
		return NULL;
	}
	char* compiler_version_buff = interpret_compiler_version_number();
	if (compiler_version_buff == NULL)
	{
		free(date_time_buff);
		return NULL;
	}

	retv = snprintf(buff, 1024, "Compiled at %s with compiler '%s' ver. '%s'", date_time_buff, CEU_COMPILER_NAME,
			compiler_version_buff);
	free(date_time_buff);
	free(compiler_version_buff);
	if (retv < 0)
	{
		return NULL;
	}
	return buff;
}

#ifdef __cplusplus
}
#endif

#endif // CEU_CHECK_CC_H
