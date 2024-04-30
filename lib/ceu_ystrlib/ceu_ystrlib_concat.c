#include "ceu_ystrlib/ceu_ystrlib_concat.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_ystrlib/ceu_ystrlib_create.h"

/**
 * Create proxy for C String to reduce copying.
 * @warning This function is dangerous since it produces a ceu_ystr_t that needs to be freed by specific methods!
 * @param cstr Source C String.
 * @return The proxy.
 */
ceu_ystr_t* ceu_ystr_proxy_create_from_cstr(const char* cstr)
{
    ceu_ystr_t* ceu_ystr = (ceu_ystr_t*)ceu_smalloc(sizeof(ceu_ystr_t));
    size_t sl = ceu_strlen(cstr);
    ceu_ystr->buff_length = sl + 1;
    ceu_ystr->buff = cstr;
    ceu_ystr->consumed_length = sl;
    return ceu_ystr;
}

/**
 * Destroy the peoxy.
 * @warning Do not use it on normal yStr, otherwise memory leak.
 * @param ystr The proxy to some C string.
 */
void ceu_ystr_proxy_destroy(ceu_ystr_t* ystr)
{
    ystr->buff = NULL;
    ystr->consumed_length = 0;
    ystr->buff_length = 0;
    ceu_free_non_null(ystr);
}

void ceu_ystr_cstr_concat_inplace(ceu_ystr_t* ystr, const char* cstr)
{
    ceu_ystr_t* ystr2 = ceu_ystr_proxy_create_from_cstr(cstr);
    ceu_ystr_concat_inplace(ystr, ystr2);
    ceu_ystr_proxy_destroy(ystr2);
}

ceu_ystr_t* ceu_ystr_cstr_concat_const(const ceu_ystr_t* ystr, const char* cstr)
{
    ceu_ystr_t* ystr2 = ceu_ystr_proxy_create_from_cstr(cstr);
    ceu_ystr_t* ystr_ret = ceu_ystr_concat_const(ystr, ystr2);
    ceu_ystr_proxy_destroy(ystr2);
    return ystr_ret;
}

void ceu_ystr_concat_inplace(ceu_ystr_t* ystr, const ceu_ystr_t* ystr2)
{
    size_t new_consumed_length = ystr2->consumed_length + ystr->consumed_length;
    ceu_ystr_guarantee(ystr, new_consumed_length + 1);
    for (size_t i = 0; i < ystr2->consumed_length; ++i) {
        ystr->buff[i + ystr->consumed_length] = ystr2->buff[i];
    }
    ystr->consumed_length = new_consumed_length;
    ystr->buff[new_consumed_length] = CEU_STRING_ENDING;
}

ceu_ystr_t* ceu_ystr_concat_const(const ceu_ystr_t* ystr, const ceu_ystr_t* ystr2)
{
    size_t new_consumed_length = ystr2->consumed_length + ystr->consumed_length;
    ceu_ystr_t* ystr_ret = ceu_ystr_create_from_cstr_guarantee(ystr->buff, new_consumed_length + 1);

    for (size_t i = 0; i < ystr2->consumed_length; ++i) {
        ystr_ret->buff[i + ystr->consumed_length] = ystr2->buff[i];
    }
    ystr_ret->consumed_length = new_consumed_length;
    ystr_ret->buff[new_consumed_length] = CEU_STRING_ENDING;
    return ystr_ret;
}
