#include <stdarg.h>

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_check/ceu_check_utils.h"
#include "ceu_cstd/ceu_stdio.h"
#include "ceu_cstd/ceu_string.h"
#include <stdio.h>

char* ceu_str_join(char* buff1, char* buff2)
{
    char* dst_buff = NULL;
    if (buff1 == NULL || buff2 == NULL) {
        return NULL;
    }
    // +1 here was used to supress Windows CRT errors.
    dst_buff = (char*)ceu_scalloc(strlen(buff1) + strlen(buff2) + 1, sizeof(char));
    if (ceu_snprintf(dst_buff, strlen(buff1) + strlen(buff2) + 1, "%s%s", buff1, buff2) < 0) {
        ceu_free_non_null(dst_buff);
        return NULL;
    }
    // printf("'%s' + '%s' -> '%s'\n", buff1, buff2, dst_buff);
    return dst_buff;
}

char* ceu_str_join_with_sep(char* sep, ceu_str_join_null_action_t nb, int count, ...)
{
    char* curr_buf;
    va_list(args);
    char* new_item;
    int i;
    char* new_intem_buf;
    char* new_intem_buf2;
    char* retbuff;
    if (sep == NULL) {
        return NULL;
    }
    curr_buf = (char*)ceu_scalloc(1, sizeof(char));
    va_start(args, count);
    for (i = 0; i < count; ++i) {
        new_item = va_arg(args, char*);
        if (new_item == NULL) {
            if (nb == CEU_STR_JOIN_REGARD_AS_EMPTY_STR) {
                new_item = "";
            } else if (nb == CEU_STR_JOIN_SKIP) {
                continue;
            } else if (nb == CEU_STR_JOIN_WARN_SKIP) {
                printf("WARNING: NULL encountered at token %d\n", i);
                continue;
            }
        }
        new_intem_buf = ceu_str_join(curr_buf, new_item);
        if (new_intem_buf == NULL) {
            ceu_free_non_null(curr_buf);
            va_end(args);
            return NULL;
        }
        ceu_free_non_null(curr_buf);
        curr_buf = (char*)ceu_scalloc(strlen(new_intem_buf) + 1, sizeof(char));
        ceu_strncpy(curr_buf, new_intem_buf, strlen(new_intem_buf) + 1);
        ceu_free_non_null(new_intem_buf);

        new_intem_buf2 = ceu_str_join(curr_buf, sep);
        if (new_intem_buf2 == NULL) {
            return NULL;
        }

        ceu_free_non_null(curr_buf);
        curr_buf = (char*)ceu_scalloc(strlen(new_intem_buf2) + 1, sizeof(char));
        ceu_strncpy(curr_buf, new_intem_buf2, strlen(new_intem_buf2) + 1);
        ceu_free_non_null(new_intem_buf2);
    }
    retbuff = ceu_scalloc(strlen(curr_buf) - strlen(sep) + 1, sizeof(char));
    ceu_strncpy(retbuff, curr_buf, strlen(curr_buf) - strlen(sep));
    va_end(args);
    ceu_free_non_null(curr_buf);
    return retbuff;
}
