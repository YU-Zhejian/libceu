/**
 * @file ceu_ystrlib_create.h
 * @author YU Zhejian
 * @brief Function related to creation and elongation of yStr.
 * @version 0.1
 * @date 2024-05-06
 *
 *
 */
#ifndef CEU_YSTRLIB_CREATE_H
#define CEU_YSTRLIB_CREATE_H
#include <ceu_ystrlib/ceu_ystrlib.h>
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Create an empty string.
 *
 * @return ceu_ystr_t* The created string.
 */
ceu_ystr_t* ceu_ystr_create_empty(void);

/*!
 * @brief Create an empty string with reserved length.
 *
 * @param reserved_length Number of characters tor eserve.
 * @return ceu_ystr_t* The created string.
 */
ceu_ystr_t* ceu_ystr_create_sized(ceu_size_t reserved_length);

/*!
 * @brief Produce a duplication.
 *
 * @param ystr yStr to duplicate.
 * @return ceu_ystr_t* Duplicated string.
 */
ceu_ystr_t* ceu_ystr_copy(const ceu_ystr_t* ystr);

/*!
 * @brief Ensure the buffer length of yStr will be equal or larger than new_buffer_size.
 * If the buffer is not long enough, yStr will be duplicated.
 *
 * @param ystr yStr to examine (and expand).
 * @param new_buffer_size Target buffer size.
 */
void ceu_ystr_guarantee(ceu_ystr_t* ystr, ceu_size_t new_buffer_size);

#ifdef __cplusplus
}
#endif

#endif // CEU_YSTRLIB_CREATE_H
