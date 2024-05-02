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
