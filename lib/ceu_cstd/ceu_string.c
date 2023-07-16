#include <string.h>
#include "ceu_cstd/ceu_string.h"


#ifdef __cplusplus
extern "C"
{
#endif

char *ceu_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

int ceu_strcmp(const char *str1, const char *str2) {
    size_t ptr = 0;
    while (1) {
        if ((str1[ptr] == str2[ptr]) && (str1[ptr] != '\0') && (str2[ptr] != '\0')) {
            ptr++;
        } else {
            break;
        }
    }
    return (unsigned char) str1[ptr] - (unsigned char) str2[ptr];
}

void *ceu_memset(void *s, int c, size_t n) {
    return memset(s, c, n); // TODO: NOT implemented, alignment issues
}

#ifdef __cplusplus
}
#endif