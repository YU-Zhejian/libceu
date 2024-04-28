#ifndef CEU_STRING_H
#define CEU_STRING_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_basic/libceu_stddef.h"

#include <stddef.h>

/*!
 * The `strncpy` definition provided by GNU.
 *
 * ceu_strncpy would copy characters from `src` to `dst` until
 * (1) encountered `\0` or reached `n`.
 *
 * If `\0` encountered without reaching `n`, additional `\0` would be padded
 * to the end of `dst` until reached `n`.
 *
 * @warning This function does not guarantee that destination string is ended with `\0`!
 *
 * @param dest Destination buffer.
 * @param src Source buffer.
 * @param n Number of character to copy.
 * @return Destination buffer.
 */
char* ceu_strncpy(char* dest, const char* src, size_t n);

int ceu_strcmp(const char* str1, const char* str2);

/*!
 * Determine string length by searching for `\0`.
 * The string length will be the offset of `\0`.
 * i.e., number of characters plus one.
 *
 * @param instr Input string.
 */
size_t ceu_strlen(const char* instr);

/**
 * @brief Copy memory content.
 * @warning Ensure that the destination buffer is large enough.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 * @param n Number of unsigned chars to copy.
 * @return void* The destination buffer modified.
 */
void* ceu_memcpy(void* dest, const void* src, size_t n);

/**
 * @brief Set c to the first len unsigned chars of s.
 *
 * @param s The buffer to set.
 * @param c Unsigned char.
 * @param len Length to set.
 * @return void* The destination buffer modified.
 * @warning Ensure that the destination buffer is large enough.
 * @warning The code were not optimized to 4- or 8-byte alignments so are slow.
 */
void* ceu_memset(void* s, int c, size_t n);
#ifdef __cplusplus
}
#endif

#endif // CEU_STRING_H
