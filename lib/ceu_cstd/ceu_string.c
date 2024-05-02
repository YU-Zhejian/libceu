#include "ceu_cstd/ceu_string.h"

char* ceu_strncpy(char* dest, const char* src, ceu_size_t n)
{
    ceu_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

int ceu_strcmp(const char* str1, const char* str2)
{
    ceu_size_t ptr = 0;
    while (1) {
        if ((str1[ptr] == str2[ptr]) && (str1[ptr] != '\0') && (str2[ptr] != '\0')) {
            ptr++;
        } else {
            break;
        }
    }
    return (unsigned char)str1[ptr] - (unsigned char)str2[ptr];
}

ceu_size_t ceu_strlen(const char* instr)
{
    int reti = 0;
    while (instr[reti] != 0) {
        reti++;
    }
    return reti;
}

void* ceu_memcpy(void* dest, const void* src, ceu_size_t n)
{
    unsigned char* d = dest;
    const unsigned char* s = src;
    for (; n; n--)
        *d++ = *s++;
    return dest;
}

void* ceu_memset(void* s, int c, ceu_size_t n)
{
    unsigned char* p = s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}
