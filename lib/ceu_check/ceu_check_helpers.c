#include "ceu_ystrlib/ceu_ystrlib_all.h"
#include "ceu_check/ceu_check_helpers.h"
#include <stdarg.h>

ceu_ystr_t* convert_version_to_ystr(ceu_size_t count, ...)
{
    ceu_ystr_t* rets = ceu_ystr_create_empty();
    va_list(args);
    for (ceu_size_t i = 0; i < count; ++i) {
        ceu_uint64_t new_item = va_arg(args, ceu_uint64_t);
        ceu_ystr_cstr_concat_inplace(rets, ".");
        ceu_ystr_t* new_item_str = ceu_ystr_from_uint(10, new_item);
        ceu_ystr_concat_inplace(rets, new_item_str);
        ceu_ystr_destroy(new_item_str);
    }
    va_end(args);
    return rets;
}