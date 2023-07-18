#ifndef CEU_STDIO_H
#define CEU_STDIO_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
size_t ceu_snprintf(char* buff, size_t max_print_n_char, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // CEU_STDIO_H
