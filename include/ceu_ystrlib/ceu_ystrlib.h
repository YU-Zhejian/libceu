#ifndef LIBCEU_CEU_YSTRLIB_H
#define LIBCEU_CEU_YSTRLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct
{
    /// Common null-terminated buffer.
    char* buff;
    // Length of the buffer including NULL.
    size_t buff_length;
    // Consumed length of the buffer (i.e., strlen()) excluding NULL.
    size_t consumed_length;
} ceu_ystr_t;

ceu_ystr_t* ceu_ystr_create_empty();
ceu_ystr_t* ceu_ystr_create_sized(size_t reserved_length);
ceu_ystr_t* ceu_ystr_create_from_cstr(char* cstr, size_t reserved_length);

#ifdef __cplusplus
}
#endif

#endif // LIBCEU_CEU_YSTRLIB_H
