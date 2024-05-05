/*!
 * @file ceu_ystrlib_int.h
 * @author YU Zhejian
 * @brief Integer-related functions. Providing implementations similiar to #strtol or #snprintf.
 * @version 0.1
 * @date 2024-05-06
 *
 * @todo A function that converts yStr to unsigned int.
 */
#ifndef CEU_YSTRLIB_INT_H
#define CEU_YSTRLIB_INT_H
#include <ceu_cstd/ceu_stdint.h>
#include <ceu_ystrlib/ceu_ystrlib.h>
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Convert an unsigned integer to yStr. Supplements the basic functionality of #printf series.
 *
 * @param raidx 2, 8, 10, or 16.
 * @param src_int The source unsigned integer.
 * @return const ceu_ystr_t* Generated yStr.
 *
 * @note This function will **NOT** add prefixes like `0x`/`0o`/`0b` for generated strings to allow further padding.
 */
ceu_ystr_t* ceu_ystr_from_uint(int raidx, ceu_uint64_t src_int);

#ifdef __cplusplus
}
#endif
#endif // CEU_YSTRLIB_INT_H
