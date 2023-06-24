#include "ceu_check/ceu_c_utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif


void ceu_die_with_retv(const char *reason, int retv)
{
    printf("Error occured! reason:\t%s", reason);
    exit(retv);
}

void ceu_die(const char *reason)
{
    ceu_die_with_retv(reason, 1);
}

/*!
 * @brief A simple wrapper to malloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void *ceu_smalloc(size_t size)
{
    void *m = malloc(size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    else {
        memset(m, 0, size);
    }
    return m;
}

/*!
* @brief A simple wrapper to realloc() that allows program exit with retv=12 if failed.
* @param size Number of bytes to allocate.
* @return Allocated memory
*/
void *ceu_srealloc(void *m, size_t size)
{
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    void *new_m = realloc(m, size);
    if (new_m == NULL) {
        free(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    else {
        memset(new_m, 0, size);
    }
    return new_m;
}

/*!
 * @brief A simple wrapper to calloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void *ceu_scalloc(size_t count, size_t size)
{
    void *m = calloc(count, size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return m;
}

void ceu_free_non_null(void *m)
{
    if (m != NULL) {
        free(m);
    }
}

char *ceu_str_join(char *buff1, char *buff2)
{
    if (buff1 == NULL || buff2 == NULL) {
        return NULL;
    }
    // +1 here was used to supress Windows CRT errors.
    char *dst_buff = (char *) ceu_scalloc(sizeof(char), strlen(buff1) + strlen(buff2) + 1);
    if (snprintf(dst_buff, strlen(buff1) + strlen(buff2) + 1, "%s%s", buff1, buff2) < 0) {
        free(dst_buff);
        return NULL;
    }
    // printf("'%s' + '%s' -> '%s'\n", buff1, buff2, dst_buff);
    return dst_buff;
}

char *ceu_str_join_with_sep(char *sep, ceu_str_join_null_action_t nb, int count, ...)
{
    if (sep == NULL) {
        return NULL;
    }
    int retv;
    char *curr_buf = (char *) ceu_smalloc(1);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        char *new_item = va_arg(args, char*);
        if (new_item == NULL) {
            if (nb == CEU_STR_JOIN_REGARD_AS_EMPTY_STR) {
                new_item = "";
            }
            else if (nb == CEU_STR_JOIN_SKIP) {
                continue;
            }
            else if (nb == CEU_STR_JOIN_WARN_SKIP) {
                printf("WARNING: NULL encountered at token %d\n", i);
                continue;
            }
        }
        char *new_intem_buf = ceu_str_join(curr_buf, new_item);
        if (new_intem_buf == NULL) {
            return NULL;
        }
        curr_buf = (char *) ceu_srealloc(curr_buf, sizeof(char) * strlen(new_intem_buf) + 1);
        retv = snprintf(curr_buf, strlen(new_intem_buf) + 1, "%s", new_intem_buf);
        free(new_intem_buf);
        if (retv < 0) {
            return NULL;
        }

        char *new_intem_buf2 = ceu_str_join(curr_buf, sep);
        if (new_intem_buf2 == NULL) {
            return NULL;
        }
        curr_buf = (char *) ceu_srealloc(curr_buf, sizeof(char) * strlen(new_intem_buf2) + 1);
        retv = snprintf(curr_buf, strlen(new_intem_buf2) + 1, "%s", new_intem_buf2);
        free(new_intem_buf2);
        if (retv < 0) {
            return NULL;
        }
    }
    char *retbuff = ceu_scalloc(strlen(curr_buf) - strlen(sep) + 1, sizeof(char));
    strncpy(retbuff, curr_buf, strlen(curr_buf) - strlen(sep));
    va_end(args);
    free(curr_buf);
    return retbuff;
}

#ifdef __cplusplus
}
#endif
