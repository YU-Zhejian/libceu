#include "ceu_ystrlib/ceu_ystrlib_concat.h"

#include <stdarg.h>

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_ystrlib/ceu_ystrlib_convert.h"
#include "ceu_ystrlib/ceu_ystrlib_create.h"

typedef struct
{
    const char* buff;
    ceu_size_t consumed_length;
} ceu_ystr_view_t;

/*!
 * Create view for C String to reduce copying.
 * @warning This function is dangerous since it produces a ceu_ystr_t that needs to be freed by specific methods!
 * @param cstr Source C String.
 * @return The view.
 */
ceu_ystr_view_t* ceu_ystr_view_create_from_cstr(const char* cstr)
{
    ceu_ystr_view_t* ceu_ystr = (ceu_ystr_view_t*)ceu_smalloc(sizeof(ceu_ystr_view_t));
    ceu_size_t sl = ceu_strlen(cstr);
    ceu_ystr->buff = cstr;
    ceu_ystr->consumed_length = sl;
    return ceu_ystr;
}

ceu_ystr_view_t* ceu_ystr_view_create_from_ystr(const ceu_ystr_t* ystr)
{
    ceu_ystr_view_t* ceu_ystr = (ceu_ystr_view_t*)ceu_smalloc(sizeof(ceu_ystr_view_t));
    ceu_ystr->buff = ystr->buff;
    ceu_ystr->consumed_length = ystr->consumed_length;
    return ceu_ystr;
}

/*!
 * Destroy the peoxy.
 * @param ystr_view The view to some C string.
 */
void ceu_ystr_view_destroy(ceu_ystr_view_t* ystr_view)
{
    ystr_view->buff = CEU_NULL;
    ystr_view->consumed_length = 0;
    ceu_free_non_null(ystr_view);
}

void ceu_ystr_ystrview_concat_inplace(ceu_ystr_t* ystr, const ceu_ystr_view_t* ystr2)
{
    ceu_size_t new_consumed_length = ystr2->consumed_length + ystr->consumed_length;
    ceu_ystr_guarantee(ystr, new_consumed_length + 1);
    for (ceu_size_t i = 0; i < ystr2->consumed_length; ++i) {
        ystr->buff[i + ystr->consumed_length] = ystr2->buff[i];
    }
    ystr->consumed_length = new_consumed_length;
    ystr->buff[new_consumed_length] = CEU_STRING_ENDING;
}

ceu_ystr_t* ceu_ystr_ystrview_concat_const(const ceu_ystr_t* ystr, ceu_ystr_view_t* ystr2)
{
    ceu_size_t new_consumed_length = ystr2->consumed_length + ystr->consumed_length;
    ceu_ystr_t* ystr_ret = ceu_ystr_create_from_cstr_guarantee(ystr->buff, new_consumed_length + 1);

    for (ceu_size_t i = 0; i < ystr2->consumed_length; ++i) {
        ystr_ret->buff[i + ystr->consumed_length] = ystr2->buff[i];
    }
    ystr_ret->consumed_length = new_consumed_length;
    ystr_ret->buff[new_consumed_length] = CEU_STRING_ENDING;
    return ystr_ret;
}

void ceu_ystr_cstr_concat_inplace(ceu_ystr_t* ystr, const char* cstr)
{
    ceu_ystr_view_t* ystr2_view = ceu_ystr_view_create_from_cstr(cstr);
    ceu_ystr_ystrview_concat_inplace(ystr, ystr2_view);
    ceu_ystr_view_destroy(ystr2_view);
}

ceu_ystr_t* ceu_ystr_cstr_concat_const(const ceu_ystr_t* ystr, const char* cstr)
{
    ceu_ystr_view_t* ystr2_view = ceu_ystr_view_create_from_cstr(cstr);
    ceu_ystr_t* ystr_ret = ceu_ystr_ystrview_concat_const(ystr, ystr2_view);
    ceu_ystr_view_destroy(ystr2_view);
    return ystr_ret;
}

void ceu_ystr_concat_inplace(ceu_ystr_t* ystr, const ceu_ystr_t* ystr2)
{
    ceu_ystr_view_t* ystr2_view = ceu_ystr_view_create_from_ystr(ystr2);
    ceu_ystr_ystrview_concat_inplace(ystr, ystr2_view);
    ceu_ystr_view_destroy(ystr2_view);
}

ceu_ystr_t* ceu_ystr_concat_const(const ceu_ystr_t* ystr, const ceu_ystr_t* ystr2)
{
    ceu_ystr_view_t* ystr2_view = ceu_ystr_view_create_from_ystr(ystr2);
    ceu_ystr_t* ystr_ret = ceu_ystr_ystrview_concat_const(ystr, ystr2_view);
    ceu_ystr_view_destroy(ystr2_view);
    return ystr_ret;
}

ceu_ystr_t* ceu_ystr_join(const ceu_ystr_t* sep, bool skip_null, ceu_size_t count, ...)
{
    ceu_ystr_t* rets = ceu_ystr_create_empty();
    va_list(args);
    bool is_first_item = true;
    if (sep == CEU_NULL) {
        return CEU_NULL;
    }
    va_start(args, count);
    for (ceu_size_t i = 0; i < count; ++i) {
        ceu_ystr_t* new_item = va_arg(args, ceu_ystr_t*);
        if (new_item == CEU_NULL) {
            if (skip_null) {
                continue;
            } else {
                if (!is_first_item) {
                    ceu_ystr_concat_inplace(rets, sep);
                }
                is_first_item = false;
                ceu_ystr_cstr_concat_inplace(rets, "<nullptr>");
            }

        } else {
            if (!is_first_item) {
                ceu_ystr_concat_inplace(rets, sep);
            }
            is_first_item = false;
            ceu_ystr_concat_inplace(rets, new_item);
        }
    }
    va_end(args);
    return rets;
}

ceu_ystr_t* ceu_ystr_cstr_join(const char* sep, bool skip_null, ceu_size_t count, ...)
{
    ceu_ystr_t* rets = ceu_ystr_create_empty();
    va_list(args);
    bool is_first_item = true;
    if (sep == CEU_NULL) {
        return CEU_NULL;
    }
    va_start(args, count);
    for (ceu_size_t i = 0; i < count; ++i) {
        char* new_item = va_arg(args, char*);
        if (new_item == CEU_NULL) {
            if (skip_null) {
                continue;
            } else {
                if (!is_first_item) {
                    ceu_ystr_cstr_concat_inplace(rets, sep);
                }
                is_first_item = false;
                ceu_ystr_cstr_concat_inplace(rets, "<nullptr>");
            }

        } else {
            if (!is_first_item) {
                ceu_ystr_cstr_concat_inplace(rets, sep);
            }
            is_first_item = false;
            ceu_ystr_cstr_concat_inplace(rets, new_item);
        }
    }
    va_end(args);
    return rets;
}
