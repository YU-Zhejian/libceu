#ifndef CEU_YSTRLIB_GC_H
#define CEU_YSTRLIB_GC_H
#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_ystrlib/ceu_ystrlib.h>

CEU_BEGIN_C_DECLS

/*!
 * @brief Destroy the string.
 *
 * @param ystr yStr to destroy.
 */
void ceu_ystr_destroy CEU_PARAMS((ceu_ystr_t * ystr));

/*!
 * @brief Clear the content of the string without shrinking the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clear CEU_PARAMS((ceu_ystr_t * ystr));

/*!
 * @brief Clear the content of the string and re-allocate the buffer.
 *
 * @param ystr yStr to clear.
 */
void ceu_ystr_clean CEU_PARAMS((ceu_ystr_t * ystr));

/*!
 * @brief Shrink the buffer to desired size. The buffer will be copied.
 *
 * @param ystr yStr to shrink.
 */
void ceu_ystr_shrink CEU_PARAMS((ceu_ystr_t * ystr, ceu_size_t new_buffer_size));

CEU_END_C_DECLS
#endif // CEU_YSTRLIB_GC_H
