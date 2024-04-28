#ifndef CEU_C_UTILS_H
#define CEU_C_UTILS_H
#ifdef __cplusplus
extern "C" {
#endif
#include "ceu_cstd/ceu_stdnoreturn.h"

#include <stddef.h>

#define CEU_ENSURE_NOT_NONE(X)                           \
    {                                                    \
        if (X == NULL) {                                 \
            ceu_ensure_not_none(#X, __FILE__, __LINE__); \
        };                                               \
    }

/*!
 * Internal -- DO NOT USE!
 *
 * @param vname Variable name that was none.
 * @param file_name Name of the source file.
 * @param lineno Line number.
 */
void ceu_ensure_not_none(char* vname, char* file_name, int lineno);

noreturn void ceu_die_with_retv(char* reason, int retv);

noreturn void ceu_die(char* reason);

/*!
 * @brief A simple wrapper to malloc() that allows program exit with retv=12
 * if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_smalloc(size_t size);

/*!
 * @brief A simple wrapper to calloc() that allows program exit with retv=12
 * if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_scalloc(size_t count, size_t size);

/**
 * @brief Free a piece of memory if it is not NULL. The piece of memory will be set to NULL afterwards.
 *
 * @param m The memory to be freed.
 */
void ceu_free_non_null(void* m);
#ifdef __cplusplus
}
#endif

noreturn void ceu_press_any_key_to_exit(void);

#endif // CEU_C_UTILS_H
