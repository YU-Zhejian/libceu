#ifndef CEU_STRING_H
#define CEU_STRING_H
#ifdef __cplusplus
extern "C" {
#endif

#include "libceu_stddef.h"

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
 * @param dest Destination buffer.
 * @param src Source buffer.
 * @param n Number of character to copy.
 * @return Destination buffer.
 */
char* ceu_strncpy(char* dest, const char* src, size_t n);

int ceu_strcmp(const char* str1, const char* str2);

size_t ceu_strlen(const char* instr);

#ifdef __cplusplus
}
#endif

#endif // CEU_STRING_H
