#ifndef CEU_C_BASIC_SIZES_H
#define CEU_C_BASIC_SIZES_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif
/*!
 * @def CEU_INT8_SIZE
 * @brief Size of `int8_t` or `uint8_t`.
 */
#define CEU_INT8_SIZE 1
/*!
 * @def CEU_INT8_SIZE
 * @brief Size of `int16_t` or `uint16_t`.
 */
#define CEU_INT16_SIZE 2
/*!
 * @def CEU_INT32_SIZE
 * @brief Size of `int32_t` or `uint32_t`..
 */
#define CEU_INT32_SIZE 4
/*!
 * @def CEU_INT64_SIZE
 * @brief Size of `int64_t` or `uint64_t`.
 */
#define CEU_INT64_SIZE 8

#endif //CEU_C_BASIC_SIZES_H
