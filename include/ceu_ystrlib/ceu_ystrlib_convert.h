//
// Created by yuzj on 24-4-28.
//

#ifndef CEU_YSTRLIB_CONVERT_H
#define CEU_YSTRLIB_CONVERT_H
#include <ceu_ystrlib/ceu_ystrlib.h>
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Convert yStr to C string.
 * @warning Performs memory allocation inside. Use ceu_ystr_to_cstr_ncpy() if you want to avoid memory allocation.
 *
 * @param ystr yStr to convert.
 * @return char* Resulting C String.
 */
char* ceu_ystr_to_cstr(const ceu_ystr_t* ystr);

/**
 * @brief Convert yStr to C string in a way that mimics strcpy.
 * @warning Make sure that dest has enough space.
 *
 * @param ystr yStr to convert.
 * @param dest Destination buffer. The resulting buffer will be NULL-terminated.
 */
void ceu_ystr_to_cstr_cpy(const ceu_ystr_t* ystr, char* dest);

/**
 * @brief Convert yStr to C string in a way that mimics strncpy.
 * @warning Make sure that dest has enough space.
 * @warning The resulting buffer may NOT be NULL-terminated.
 *
 * @param ystr yStr to convert.
 * @param dest Destination buffer.
 */
void ceu_ystr_to_cstr_ncpy(const ceu_ystr_t* ystr, char* dest, size_t n);

#ifdef __cplusplus
}
#endif

#endif // CEU_YSTRLIB_CONVERT_H
