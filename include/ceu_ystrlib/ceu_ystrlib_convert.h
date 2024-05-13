/**
 * @file ceu_ystrlib_convert.h
 * @author YU Zhejian
 * @brief Convert yStr to C string and in reverse.
 * @version 0.1
 * @date 2024-05-06
 *
 */
#ifndef CEU_YSTRLIB_CONVERT_H
#define CEU_YSTRLIB_CONVERT_H
#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

CEU_BEGIN_C_DECLS

/*!
 * @brief Convert yStr to C string.
 * @warning Performs memory allocation inside. Use ceu_ystr_to_cstr_ncpy() if you want to avoid memory allocation.
 *
 * @param ystr yStr to convert.
 * @return char* Resulting C String.
 */
char* ceu_ystr_to_cstr CEU_PARAMS((const ceu_ystr_t* ystr));

/*!
 * @brief Convert yStr to C string in a way that mimics strcpy.
 * @warning Make sure that dest has enough space.
 *
 * @param ystr yStr to convert.
 * @param dest Destination buffer. The resulting buffer will be CEU_NULL-terminated.
 */
void ceu_ystr_to_cstr_cpy CEU_PARAMS((const ceu_ystr_t* ystr, char* dest));

/*!
 * @brief Convert yStr to C string in a way that mimics strncpy.
 * @warning Make sure that dest has enough space.
 * @warning The resulting buffer may NOT be CEU_NULL-terminated.
 *
 * @param ystr yStr to convert.
 * @param dest Destination buffer.
 * @param n Number of `char`s to copy.
 */
void ceu_ystr_to_cstr_ncpy CEU_PARAMS((const ceu_ystr_t* ystr, char* dest, ceu_size_t n));

/*!
 * @brief Convert a C string to a yStr.
 *
 * @param cstr The source CEU_NULL-terminated cStr.
 * @return ceu_ystr_t* The converted string.
 */
ceu_ystr_t* ceu_ystr_create_from_cstr CEU_PARAMS((const char* cstr));

/*!
 * @brief Convert a C string to a yStr.
 *
 * @param cstr The source CEU_NULL-terminated cStr.
 * @param reserved_length Number of characters to reserve.
 * @return ceu_ystr_t* The converted string. The final buffer length will be string length + reserved length.
 */
ceu_ystr_t* ceu_ystr_create_from_cstr_reserve CEU_PARAMS((const char* cstr, ceu_size_t reserved_length));

/*!
 * @brief Convert a C string to a yStr.
 *
 * @param cstr The source CEU_NULL-terminated cStr.
 * @param guarantee_buffer_length The buffer length should be at least this long.
 * @return ceu_ystr_t* The converted string.
 */
ceu_ystr_t* ceu_ystr_create_from_cstr_guarantee CEU_PARAMS((const char* cstr, ceu_size_t guarantee_buffer_length));

CEU_END_C_DECLS

#endif // CEU_YSTRLIB_CONVERT_H
