/*!
 * @file ceu_ystrlib.h
 * @author YU Zhejian
 * @brief Defined basic yStr type.
 * @version 0.1
 * @date 2024-05-05
 *
 */
#ifndef LIBCEU_CEU_YSTRLIB_H
#define LIBCEU_CEU_YSTRLIB_H

#include <ceu_cstd/ceu_stddef.h> // ceu_size_t
/**
 * @def CEU_YSTR_DEFAULT_SIZE
 * @brief The default string size.
 */
#define CEU_YSTR_DEFAULT_SIZE 16

/*!
 * @brief The yStr type.
 *
 */
typedef struct
{
    /*!
     * @brief Common null-terminated buffer.
     *
     */
    char* buff;
    /*!
     * @brief Length of the buffer **including** CEU_NULL.
     *
     */
    ceu_size_t buff_length;
    /*!
     * @brief Consumed length of the buffer (i.e., ::ceu_strlen) **excluding** CEU_NULL.
     *
     */
    ceu_size_t consumed_length;
} ceu_ystr_t;

#endif // LIBCEU_CEU_YSTRLIB_H
