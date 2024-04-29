#include <stdio.h>
#include <stdlib.h>

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_cstd/ceu_stdio.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_check/ceu_check_os.h"

void* ceu_smalloc(size_t size)
{
    void* m = malloc(size);
    if (m == NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    } else {
        m = ceu_memset(m, 0, size);
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

void* ceu_srealloc(void* m, size_t size)
{
    void* retm = realloc(m, size);
    if (retm == NULL) {
        ceu_free_non_null(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return retm;
}

void* ceu_sreallocarray(void* m, size_t count, size_t size){
    void* retm = realloc(m, size * count);
    if (retm == NULL) {
        ceu_free_non_null(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return retm;
}

void ceu_free_non_null(void* m)
{
    if (m != NULL) {
       free(m);
    }
#ifndef CEU_ON_WINDOWS
    m = NULL;
#endif
}

noreturn void ceu_die_with_retv(char* reason, int retv)
{
    printf("Error occured! reason:\t%s\n", reason);
#if (defined CEU_CM_IS_DEBUG && CEU_CM_IS_DEBUG == 1)
    printf("Ready to return at %d, but abort to allow debugging.\n", retv);
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