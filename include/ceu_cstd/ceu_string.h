/*!
 * @file ceu_string.h
 * @brief POSIX-2008 compiliant string \& memory manipulation functions from <string.h>.
 *
 * Pure-C functions, portable but slow.
 * @todo void    *memccpy(void *restrict, const void *restrict, int, ceu_size_t);
 * @todo void    *memchr(const void *, int, ceu_size_t);
 * @todo int      memcmp(const void *, const void *, ceu_size_t);
 * @todo void    *memmove(void *, const void *, ceu_size_t);
 * @todo char    *stpcpy(char *restrict, const char *restrict);
 * @todo char    *stpncpy(char *restrict, const char *restrict, ceu_size_t);
 * @todo char    *strcat(char *restrict, const char *restrict);
 * @todo char    *strchr(const char *, int);
 * @todo int      strcoll(const char *, const char *);
 * @todo int      strcoll_l(const char *, const char *, locale_t);
 * @todo char    *strcpy(char *restrict, const char *restrict);
 * @todo ceu_size_t   strcspn(const char *, const char *);
 * @todo char    *strdup(const char *);
 * @todo char    *strerror(int);
 * @todo char    *strerror_l(int, locale_t);
 * @todo int      strerror_r(int, char *, ceu_size_t);
 * @todo char    *strncat(char *restrict, const char *restrict, ceu_size_t);
 * @todo int      strncmp(const char *, const char *, ceu_size_t);
 * @todo char    *strndup(const char *, ceu_size_t);
 * @todo ceu_size_t   strnlen(const char *, ceu_size_t);
 * @todo char    *strpbrk(const char *, const char *);
 * @todo char    *strrchr(const char *, int);
 * @todo char    *strsignal(int);
 * @todo ceu_size_t   strspn(const char *, const char *);
 * @todo char    *strstr(const char *, const char *);
 * @todo char    *strtok(char *restrict, const char *restrict);
 * @todo char    *strtok_r(char *restrict, const char *restrict, char **restrict);
 * @todo ceu_size_t   strxfrm(char *restrict, const char *restrict, ceu_size_t);
 * @todo ceu_size_t   strxfrm_l(char *restrict, const char *restrict, ceu_size_t, locale_t);
 */
#ifndef CEU_STRING_H
#define CEU_STRING_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_cstd/ceu_stddef.h>

CEU_BEGIN_C_DECLS

/*!
 * @brief Copy characters from `src` to `dst` until encountered `\0` or reached `n`.
 *
 * The `strncpy` definition provided by GNU.
 *
 * If `\0` encountered without reaching `n`, additional `\0` would be padded
 * to the end of `dst` until reached `n`.
 *
 * However, if `n` is reached first, no `\0` will be added.
 *
 * @warning This function does not guarantee that destination string is ended with `\0`!
 *
 * @param dest Destination buffer.
 * @param src Source buffer.
 * @param n Number of character to copy.
 * @return Destination buffer.
 */
char* ceu_strncpy CEU_PARAMS((char* dest, const char* src, ceu_size_t n));

int ceu_strcmp CEU_PARAMS((const char* str1, const char* str2));

/*!
 * Determine string length by searching for `\0`.
 * The string length will be the offset of `\0`.
 * i.e., number of characters plus one.
 *
 * @param instr Input string.
 */
ceu_size_t ceu_strlen CEU_PARAMS((const char* instr));

/*!
 * @brief Copy memory content.
 * @warning Ensure that the destination buffer is large enough.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 * @param n Number of unsigned chars to copy.
 * @return void* The destination buffer modified.
 */
void* ceu_memcpy CEU_PARAMS((void* dest, const void* src, ceu_size_t n));

/*!
 * @brief Set `c` to the first `n` unsigned chars of `s`.
 *
 * @param s The buffer to set.
 * @param c Unsigned char.
 * @param n Length to set.
 * @return void* The destination buffer modified.
 * @warning Ensure that the destination buffer is large enough.
 * @warning The code were not optimized to 4- or 8-byte alignments so are slow.
 */
void* ceu_memset CEU_PARAMS((void* s, int c, ceu_size_t n));
CEU_END_C_DECLS

#endif // CEU_STRING_H
