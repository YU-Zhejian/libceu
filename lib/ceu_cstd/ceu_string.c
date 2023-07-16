#include "ceu_cstd/ceu_string.h"


#ifdef __cplusplus
extern "C"
{
#endif

char * ceu_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( ; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

#ifdef __cplusplus
}
#endif