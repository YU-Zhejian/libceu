#ifndef CEU_STRING_H
#define CEU_STRING_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "libceu_stddef.h"
#include <string.h>

#if CEU_HAVE_STRNCPY_S == 1
    static inline int ceu_strncpy(char* dst, char* src, size_t count) {
        return strncpy_s(dst, count, src, count);
    }
#else
    static inline int ceu_strncpy(char* dst, char* src, size_t count) {
        return strncpy(dst, src, count);
    }
#endif

#ifdef __cplusplus
}
#endif

#endif // CEU_STRING_H