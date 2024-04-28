#ifndef LIBCEU_CEU_YSTRLIB_H
#define LIBCEU_CEU_YSTRLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#define DEFAULT_CEU_YSTR_SIZE 16
/**
 * @brief The yStr type.
 *
 */
typedef struct
{
    /**
     * @brief Common null-terminated buffer.
     *
     */
    char* buff;
    /**
     * @brief Length of the buffer including NULL.
     *
     */
    size_t buff_length;
    /**
     * @brief Consumed length of the buffer (i.e., strlen()) excluding NULL.
     *
     */
    size_t consumed_length;
} ceu_ystr_t;

#ifdef __cplusplus
}
#endif

#endif // LIBCEU_CEU_YSTRLIB_H
