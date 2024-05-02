#ifndef CEU_STDIO_H
#define CEU_STDIO_H

#include <ceu_cstd/ceu_stddef.h> // ceu_size_t

#ifdef __cplusplus
extern "C" {
#endif
// FIXME: The current implementation is completely crap. Consider have it redone.
ceu_size_t ceu_snprintf(char* buff, ceu_size_t max_print_n_char, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // CEU_STDIO_H
