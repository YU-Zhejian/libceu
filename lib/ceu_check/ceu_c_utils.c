#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "ceu_check/ceu_c_utils.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_cstd/ceu_stdio.h"


#ifdef __cplusplus
extern "C"
{
#endif

noreturn void ceu_die_with_retv(char *reason, int retv) {
    printf("Error occured! reason:\t%s", reason);
    exit(retv);
}

noreturn void ceu_die(char *reason) {
    ceu_die_with_retv(reason, 1);
}

/*!
 * @brief A simple wrapper to malloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void *ceu_smalloc(size_t size) {
    void *m = malloc(size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    } else {
        memset(m, 0, size);
    }
    return m;
}

/*!
* @brief A simple wrapper to realloc() that allows program exit with retv=12 if failed.
* @param size Number of bytes to allocate.
* @return Allocated memory
*/
void *ceu_srealloc(void *m, size_t size) {
    void *new_m;
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    new_m = realloc(m, size);
    if (new_m == NULL) {
        ceu_free_non_null(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    } else {
        memset(new_m, 0, size);
    }
    return new_m;
}

/*!
 * @brief A simple wrapper to calloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void *ceu_scalloc(size_t count, size_t size) {
    void *m = calloc(count, size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return m;
}

void ceu_free_non_null(void *m) {
    if (m != NULL) {
        free(m);
    }
}

char *ceu_str_join(char *buff1, char *buff2) {
    char *dst_buff = NULL;
    if (buff1 == NULL || buff2 == NULL) {
        return NULL;
    }
    // +1 here was used to supress Windows CRT errors.
    dst_buff = (char *) ceu_scalloc(strlen(buff1) + strlen(buff2) + 1, sizeof(char));
    if (ceu_snprintf(dst_buff, strlen(buff1) + strlen(buff2) + 1, "%s%s", buff1, buff2) < 0) {
        ceu_free_non_null(dst_buff);
        return NULL;
    }
    // printf("'%s' + '%s' -> '%s'\n", buff1, buff2, dst_buff);
    return dst_buff;
}

char *ceu_str_join_with_sep(char *sep, ceu_str_join_null_action_t nb, int count, ...) {
    int retv;
    char *curr_buf;
    va_list args;
    char *new_item;
    int i;
    char *new_intem_buf;
    char *new_intem_buf2;
    char *retbuff;
    if (sep == NULL) {
        return NULL;
    }
    curr_buf = (char *) ceu_smalloc(1);
    va_start(args, count);
    for (i = 0; i < count; ++i) {
        new_item = va_arg(args,
                          char*);
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
            va_end(args);
            return NULL;
        }
        curr_buf = (char *) ceu_srealloc(curr_buf, sizeof(char) * strlen(new_intem_buf) + 1);
        retv = snprintf(curr_buf, strlen(new_intem_buf) + 1, "%s", new_intem_buf);
        free(new_intem_buf);
        if (retv < 0) {
            va_end(args);
            return NULL;
        }

        new_intem_buf2 = ceu_str_join(curr_buf, sep);
        if (new_intem_buf2 == NULL) {
            return NULL;
        }
        curr_buf = (char *) ceu_srealloc(curr_buf, sizeof(char) * strlen(new_intem_buf2) + 1);
        retv = snprintf(curr_buf, strlen(new_intem_buf2) + 1, "%s", new_intem_buf2);
        ceu_free_non_null(new_intem_buf2);
        if (retv < 0) {
            va_end(args);
            return NULL;
        }
    }
    retbuff = ceu_scalloc(strlen(curr_buf) - strlen(sep) + 1, sizeof(char));
    ceu_strncpy(retbuff, curr_buf, strlen(curr_buf) - strlen(sep));
    va_end(args);
    ceu_free_non_null(curr_buf);
    return retbuff;
}

void ceu_ensure_not_none(char *vname, char *file_name, int lineno) {
    char lineno_s[10] = "";
    snprintf(lineno_s, 10, "%d", lineno);
    ceu_die(ceu_str_join_with_sep(
            "",
            CEU_STR_JOIN_REGARD_AS_EMPTY_STR,
            6,
            file_name,
            ":",
            lineno_s,
            "\t",
            vname,
            " is NULL!"
    ));
}

noreturn void ceu_press_any_key_to_exit() {
    puts("Press any key to exit...");
    getchar();
    exit(0);
}

#ifdef __cplusplus
}
#endif
