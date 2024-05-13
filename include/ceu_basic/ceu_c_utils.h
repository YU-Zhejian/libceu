/*!
 * @file ceu_c_utils.h
 * @brief Utility functions for memory allocation, deallocation, program termination, with debugging support.
 * @author YU Zhejian
 * @version 0.1
 * @date 2024-05-02
 */
#ifndef CEU_C_UTILS_H
#define CEU_C_UTILS_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_cstd/ceu_stddef.h>
#include <ceu_cstd/ceu_stdnoreturn.h>

CEU_BEGIN_C_DECLS

/*!
 * @brief Exit with exit value.
 * @param reason What to say before exit.
 * @param retv The exit value for a program.
 * @note If debug is allowed (i.e., `defined CEU_CM_IS_DEBUG && CEU_CM_IS_DEBUG == 1`), will use `abort` to allow debuggers to investigate
 */
noreturn void ceu_die_with_retv CEU_PARAMS((const char* reason, int retv));

/*!
 * @brief ::ceu_die_with_retv with #EXIT_FAILURE as return value.
 */
noreturn void ceu_die CEU_PARAMS((const char* reason));

/*!
 * @brief A simple wrapper to `malloc` that allows program exit with retv=12
 * if failed.
 * In this implementation, the allocated memory will be initialized with 0.
 * @param size Number of bytes to allocate.
 * @return Allocated memory.
 */
void* ceu_smalloc CEU_PARAMS((ceu_size_t size));

/*!
 * @brief A simple wrapper to `calloc` that allows program exit with retv=12
 * if failed.
 * In this implementation, the allocated memory will be initialized with 0.
 * @return Allocated memory
 */
void* ceu_scalloc CEU_PARAMS((ceu_size_t count, ceu_size_t size));

/*!
 * @brief A simple wrapper to `realloc` that allows program exit with retv=12
 * if failed.
 * In this implementation, the newly allocated memory will NOT be initialized with 0.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_srealloc CEU_PARAMS((void* m, ceu_size_t size));

/*!
 * @brief A simple wrapper to `realloc` that allows program exit with retv=12
 * if failed.
 *
 * In this implementation, the newly allocated memory will NOT be initialized with 0.
 *
 * @note This is a simple wrapper of ceu_srealloc since reallocarray is not POSIX compliant.
 *
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_sreallocarray CEU_PARAMS((void* m, ceu_size_t count, ceu_size_t size));

/*!
 * @brief Free a piece of memory if it is not #CEU_NULL. The piece of memory will be set to #CEU_NULL afterwards.
 *
 * @param m The memory to be freed.
 */
void ceu_free_non_null CEU_PARAMS((void* m));

/*!
 * @brief Wait for a keystroke and then exit the program with #EXIT_SUCCESS.
 * @note This function will not return.
 */
noreturn void ceu_press_any_key_to_exit CEU_PARAMS((void));

CEU_END_C_DECLS

#endif // CEU_C_UTILS_H
