#include "ceu_check/ceu_check_helpers.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"
#include <stdarg.h>

ceu_ystr_t* convert_version_to_ystr(ceu_size_t count, ...)
{
    ceu_ystr_t* rets = ceu_ystr_create_empty();
    bool is_first_item;
    ceu_uint64_t new_item;
	ceu_ystr_t* new_item_str;
    ceu_size_t i; /// Temporary variable used in loops

    va_list(args);
    va_start(args, count);
    is_first_item = true;
    for (i = 0; i < count; ++i) {
        new_item = va_arg(args, ceu_uint64_t);
        if (!is_first_item) {
            ceu_ystr_cstr_concat_inplace(rets, ".");
        }
        new_item_str = ceu_ystr_from_uint(10, new_item);
        ceu_ystr_concat_inplace(rets, new_item_str);
        ceu_ystr_destroy(new_item_str);
        is_first_item = false;
    }
    va_end(args);
    return rets;
}

ceu_ystr_t* convert_version_to_ystr3(ceu_uint64_t ver1, ceu_uint64_t ver2, ceu_uint64_t ver3)
{
    return convert_version_to_ystr(3, ver1, ver2, ver3);
}
ceu_ystr_t* convert_version_to_ystr2(ceu_uint64_t ver1, ceu_uint64_t ver2)
{
    return convert_version_to_ystr(2, ver1, ver2);
}
