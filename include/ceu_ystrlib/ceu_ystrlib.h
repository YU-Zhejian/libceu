#ifndef LIBCEU_CEU_YSTRLIB_H
#define LIBCEU_CEU_YSTRLIB_H

#include <ceu_cstd/ceu_stddef.h> // ceu_size_t
#define DEFAULT_CEU_YSTR_SIZE 16

#ifdef __cplusplus
extern "C" {
#endif
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
     * @brief Length of the buffer including CEU_NULL.
     *
     */
    ceu_size_t buff_length;
    /*!
     * @brief Consumed length of the buffer (i.e., strlen()) excluding CEU_NULL.
     *
     */
    ceu_size_t consumed_length;
} ceu_ystr_t;

#ifdef __cplusplus
}
#endif

#endif // LIBCEU_CEU_YSTRLIB_H
