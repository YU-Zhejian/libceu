#ifndef CEU_STDIO_H
#define CEU_STDIO_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
size_t ceu_snprintf(char* buff, size_t max_print_n_char, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // CEU_STDIO_H
