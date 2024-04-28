#include <stdio.h>
#include <stdlib.h>

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_cstd/ceu_stdio.h"

void* ceu_smalloc(size_t size)
{
    void* m = malloc(size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    } else {
        m = memset(m, 0, size);
    }
    return m;
}

void* ceu_scalloc(size_t count, size_t size)
{
    void* m = calloc(count, size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return m;
}

void ceu_free_non_null(void* m)
{
    if (m != NULL) {
        free(m);
    }
}

noreturn void ceu_die_with_retv(char* reason, int retv)
{

    printf("Error occured! reason:\t%s", reason);
#ifdef CEU_CM_IS_DEBUG
    // To allow debuggers to investigate
    abort();
#else
    exit(retv);
#endif
}

noreturn void ceu_die(char* reason)
{
    ceu_die_with_retv(reason, 1);
}

void ceu_ensure_not_none(char* vname, char* file_name, int lineno)
{
    char lineno_s[20] = "";
    ceu_snprintf(lineno_s, 20, "%d", lineno);
    //	ceu_die(ceu_str_join_with_sep("", CEU_STR_JOIN_REGARD_AS_EMPTY_STR, 6, file_name, ":", lineno_s, "\t", vname,
    //			" is NULL!"));
    ceu_die(""); // TODO
}

noreturn void ceu_press_any_key_to_exit(void)
{
    puts("Press any key to exit...");
    getchar();
    exit(0);
}