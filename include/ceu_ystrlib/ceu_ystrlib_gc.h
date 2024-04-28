#ifndef CEU_YSTRLIB_GC_H
#define CEU_YSTRLIB_GC_H
#include <ceu_ystrlib/ceu_ystrlib.h>

/**
 * @brief Destroy the string.
 *
 * @param ystr yStr to destroy.
 */
void ceu_ystr_destroy(ceu_ystr_t* ystr);

/**
 * @brief Clear the content of the string.
 * @warning Will NOT free the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clear(ceu_ystr_t* ystr);

/**
 * @brief Clear the content of the string and re-allocate the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clean(ceu_ystr_t* ystr);

/**
 * @brief Shrink the buffer to desired size. The buffer will be copied.
 *
 * @param ystr yStr to shrink.
 */
void ceu_ystr_shrink(ceu_ystr_t* ystr, size_t new_buffer_size);

#endif // CEU_YSTRLIB_GC_H
