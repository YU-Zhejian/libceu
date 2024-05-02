#ifndef CEU_YSTRLIB_GC_H
#define CEU_YSTRLIB_GC_H
#include <ceu_ystrlib/ceu_ystrlib.h>
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Destroy the string.
 *
 * @param ystr yStr to destroy.
 */
void ceu_ystr_destroy(ceu_ystr_t* ystr);

/*!
 * @brief Clear the content of the string without shrinking the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clear(ceu_ystr_t* ystr);

/*!
 * @brief Clear the content of the string and re-allocate the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clean(ceu_ystr_t* ystr);

/*!
 * @brief Shrink the buffer to desired size. The buffer will be copied.
 *
 * @param ystr yStr to shrink.
 */
void ceu_ystr_shrink(ceu_ystr_t* ystr, ceu_size_t new_buffer_size);

#ifdef __cplusplus
}
#endif
#endif // CEU_YSTRLIB_GC_H
