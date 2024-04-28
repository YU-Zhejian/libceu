//
// Created by yuzj on 24-4-28.
//

#ifndef CEU_YSTRLIB_CREATE_H
#define CEU_YSTRLIB_CREATE_H
#include <ceu_ystrlib/ceu_ystrlib.h>

/**
 * @brief Create an empty string.
 *
 * @return ceu_ystr_t* The created string.
 */
ceu_ystr_t* ceu_ystr_create_empty(void);

/**
 * @brief Create an empty string with reserved length.
 *
 * @param reserved_length Number of characters tor eserve.
 * @return ceu_ystr_t* The created string.
 */
ceu_ystr_t* ceu_ystr_create_sized(size_t reserved_length);

/**
 * @brief Convert a C string to a yStr.
 *
 * @param cstr The source NULL-terminated cStr.
 * @param reserved_length Number of characters tor eserve.
 * @return ceu_ystr_t* The converted string. The final buffer length will be string length + reserved length.
 */
ceu_ystr_t* ceu_ystr_create_from_cstr(const char* cstr, size_t reserved_length);

/**
 * @brief Produce a duplication.
 *
 * @param ystr yStr to duplicate.
 * @return ceu_ystr_t* Duplicated string.
 */
ceu_ystr_t* ceu_ystr_copy(const ceu_ystr_t* ystr);

/**
 * @brief Ensure the buffer length of yStr will be equal or larger than new_buffer_size.
 * If the buffer is not long enough, yStr will be duplicated.
 *
 * @param ystr yStr to examine (and expand).
 * @param new_buffer_size Target buffer size.
 */
void ceu_ystr_guarantee(ceu_ystr_t* ystr, size_t new_buffer_size);

#endif // CEU_YSTRLIB_CREATE_H
