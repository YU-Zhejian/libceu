#include "ceu_ystrlib/ceu_ystrlib_convert.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_string.h"

char* ceu_ystr_to_cstr(const ceu_ystr_t* ystr)
{
    char* rets = (char*)ceu_scalloc(ystr->consumed_length + 1, sizeof(char));
    ceu_strncpy(rets, ystr->buff, ystr->consumed_length);
    return rets;
}

void ceu_ystr_to_cstr_cpy(const ceu_ystr_t* ystr, char* dest)
{
    ceu_strncpy(dest, ystr->buff, ystr->consumed_length);
    dest[ystr->consumed_length + 1] = CEU_STRING_ENDING;
}

void ceu_ystr_to_cstr_ncpy(const ceu_ystr_t* ystr, char* dest, ceu_size_t n)
{
    if (ystr->consumed_length < n) {
        n = ystr->consumed_length;
    }
    ceu_strncpy(dest, ystr->buff, n);
}

ceu_ystr_t* ceu_ystr_create_from_cstr(const char* cstr)
{
    return ceu_ystr_create_from_cstr_reserve(cstr, 0);
}

ceu_ystr_t* ceu_ystr_create_from_cstr_guarantee(const char* cstr, ceu_size_t guarantee_buffer_length)
{
    ceu_ystr_t* ceu_ystr = (ceu_ystr_t*)ceu_smalloc(sizeof(ceu_ystr_t));
    ceu_size_t sl = ceu_strlen(cstr);
    ceu_ystr->buff_length = CEU_MAX(guarantee_buffer_length, sl + 1);
    ceu_ystr->buff = (char*)ceu_scalloc(ceu_ystr->buff_length, sizeof(char));
    ceu_ystr->consumed_length = sl;
    ceu_strncpy(ceu_ystr->buff, cstr, sl);
    return ceu_ystr;
}

ceu_ystr_t* ceu_ystr_create_from_cstr_reserve(const char* cstr, ceu_size_t reserved_length)
{
    ceu_ystr_t* ceu_ystr = (ceu_ystr_t*)ceu_smalloc(sizeof(ceu_ystr_t));
    ceu_size_t sl = ceu_strlen(cstr);
    ceu_ystr->buff_length = sl + reserved_length + 1;
    ceu_ystr->buff = (char*)ceu_scalloc(ceu_ystr->buff_length, sizeof(char));
    ceu_ystr->consumed_length = sl;
    ceu_strncpy(ceu_ystr->buff, cstr, sl);
    return ceu_ystr;
}
