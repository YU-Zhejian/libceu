/*!
 * @file ceu_c_utils.h
 * @brief Utility functions for various purpose.
 * @author YU Zhejian
 * @version 0.1
 * @date 2024-05-02
 */
#ifndef CEU_C_UTILS_H
#define CEU_C_UTILS_H

#include "ceu_cstd/ceu_stdnoreturn.h"

#include <ceu_cstd/ceu_stddef.h> // ceu_size_t

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Exit with exit value.
 * @param reason What to say before exit.
 * @param retv The exit value for a program.
 * @return No return.
 * @note If debug is allowed (i.e., `defined CEU_CM_IS_DEBUG && CEU_CM_IS_DEBUG == 1`), will use ::abort to allow debuggers to investigate
 */
noreturn void ceu_die_with_retv(const char* reason, int retv);

/*!
 * @brief ::ceu_die_with_retv with #EXIT_FAILURE as return value.
 */
noreturn void ceu_die(const char* reason);

/*!
 * @brief A simple wrapper to ::malloc() that allows program exit with retv=12
 * if failed.
 * In this implementation, the allocated memory will be initialized with 0.
 * @param size Number of bytes to allocate.
 * @return Allocated memory.
 */
void* ceu_smalloc(ceu_size_t size);

/*!
 * @brief A simple wrapper to ::calloc() that allows program exit with retv=12
 * if failed.
 * In this implementation, the allocated memory will be initialized with 0.
 * @return Allocated memory
 */
void* ceu_scalloc(ceu_size_t count, ceu_size_t size);

/*!
 * @brief A simple wrapper to ::realloc() that allows program exit with retv=12
 * if failed.
 * In this implementation, the newly allocated memory will NOT be initialized with 0.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_srealloc(void* m, ceu_size_t size);

/*!
 * @brief A simple wrapper to ::realloc() that allows program exit with retv=12
 * if failed.
 *
 * In this implementation, the newly allocated memory will NOT be initialized with 0.
 *
 * @note This is a simple wrapper of ceu_srealloc since reallocarray is not POSIX compliant.
 *
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_sreallocarray(void* m, ceu_size_t count, ceu_size_t size);

/*!
 * @brief Free a piece of memory if it is not CEU_NULL. The piece of memory will be set to CEU_NULL afterwards.
 *
 * @param m The memory to be freed.
 */
void ceu_free_non_null(void* m);

/*!
 * @brief Wait for a keystroke and then exit the program with #EXIT_SUCCESS.
 * @note This function will not return.
 */
noreturn void ceu_press_any_key_to_exit(void);

#ifdef __cplusplus
}
#endif

#endif // CEU_C_UTILS_H
