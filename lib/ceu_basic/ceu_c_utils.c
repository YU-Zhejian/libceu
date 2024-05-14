#include <stdint.h> // SIZE_MAX
#include <stdio.h> // printf
#include <stdlib.h> // malloc, calloc, free, realloc

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_thirdparty/log.h"

void* ceu_smalloc(ceu_size_t size)
{
    if (size == 0 ){
        log_warn("malloc with size 0 is undefined behaviour. Use at risk.");
    }
    void* m = malloc(size);
    if (m == CEU_NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    } else {
        m = ceu_memset(m, 0, size);
    }
    return m;
}

void* ceu_scalloc(ceu_size_t count, ceu_size_t size)
{
    if (count == 0 || size == 0){
        log_warn("calloc with size or count 0 is undefined behaviour. Use at risk.");
    }
    void* m;
    if (count != 0 && size != 0 && count > SIZE_MAX / size) {
        ceu_die_with_retv("Overflow detected!", 12);
    }
    m = calloc(count, size);
    if (m == CEU_NULL) {
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return m;
}

void* ceu_srealloc(void* m, ceu_size_t size)
{
    if(m == CEU_NULL){
        return ceu_smalloc(size);
    }
    if (size == 0 ){
        log_warn("realloc with size 0 is undefined behaviour. Use at risk.");
    }
    void* retm = realloc(m, size);
    if (retm == CEU_NULL) {
        ceu_free_non_null(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return retm;
}

void* ceu_sreallocarray(void* m, ceu_size_t count, ceu_size_t size)
{
    if (count != 0 && size != 0 && count > SIZE_MAX / size) {
        ceu_die_with_retv("Overflow detected!", 12);
    }
    ceu_size_t realloc_count = size * count;
    void* retm = realloc(m, realloc_count);
    if (retm == CEU_NULL) {
        ceu_free_non_null(m);
        ceu_die_with_retv("ERR 12 -- Cannot allocate memory", 12);
    }
    return retm;
}

void ceu_free_non_null(void* m)
{
    if (m != CEU_NULL) {
        free(m);
    }
#ifndef CEU_ON_WINDOWS
    m = CEU_NULL;
#endif
}

noreturn void ceu_die_with_retv(const char* reason, int retv)
{
    if (retv == EXIT_SUCCESS){
        retv = EXIT_FAILURE;
    }
    printf("Error occurred! reason:\t%s\n", reason);
#if (defined CEU_CM_IS_DEBUG && CEU_CM_IS_DEBUG == 1)
    printf("Ready to return at %d, but abort to allow debugging.\n", retv);
    // To allow debuggers to investigate
    abort();
#else
    exit(retv);
#endif
}

noreturn void ceu_die(const char* reason)
{
    ceu_die_with_retv(reason, EXIT_FAILURE);
}

noreturn void ceu_press_any_key_to_exit(void)
{
    puts("Press any key to exit...");
    putchar(getchar());
    exit(EXIT_SUCCESS);
}
