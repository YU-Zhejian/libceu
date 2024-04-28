//
// Created by yuzj on 24-4-28.
//

#ifndef CEU_YSTRLIB_INT_H
#define CEU_YSTRLIB_INT_H
#include <ceu_w32api/pstdint.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

/**
 * @brief Convert an unsigned integer to yStr. Supplements the basic functionality of printf series.
 *
 * @param raidx 2, 8, 10, or 16.
 * @param src_int The source unsigned integer.
 * @return const ceu_ystr_t* Generated yStr.
 */
ceu_ystr_t* ceu_ystr_from_uint(int raidx, uint64_t src_int);

#endif // CEU_YSTRLIB_INT_H
