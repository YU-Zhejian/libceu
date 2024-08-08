/*!
 * @file ceu_c_utils.h
 * @brief Utility functions for memory allocation, deallocation, program termination, with debugging support.
 * @author YU Zhejian
 * @version 0.1
 * @date 2024-05-02
 *
 * This file assists standard functions defined in `stdlib.h`.
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
 * @warning Do not use this as a replacement of #ceu_assert. Always set `retv` to a non-zero value. If `retv` is #EXIT_SUCCESS, it will be set to #EXIT_FAILURE.
 * @note If debug is allowed (i.e., `defined CEU_CM_IS_DEBUG && CEU_CM_IS_DEBUG == 1`), will use `abort` to allow debuggers to investigate
 */
ceu_noreturn void ceu_die_with_retv CEU_PARAMS((const char* reason, int retv));

/*!
 * @brief ::ceu_die_with_retv with #EXIT_FAILURE as return value.
 */
ceu_noreturn void ceu_die CEU_PARAMS((const char* reason));

/*!
 * @brief A simple wrapper to `malloc` that allows program exit with retv=12
 * if #CEU_NULL is returned.
 *
 * @note In this implementation, the allocated memory will be initialized with 0.
 * @warning Allocation with `size` 0 is undefined behaviour. This version will try to emit a warning through log.h.
 *
 * @see [cppreference](https://en.cppreference.com/w/c/memory/malloc) description of `malloc`.
 *
 * @param size Number of bytes to allocate.
 * @return Allocated memory.
 */
void* ceu_smalloc CEU_PARAMS((ceu_size_t size));

/*!
 * @brief A simple wrapper to `calloc` that allows program exit with retv=12
 * if #CEU_NULL is returned.
 *
 * @note In this implementation, the allocated memory will be initialized with 0.
 * @note In this implementation, overflow detection will be performed, and error will be raised if overflow was detected.
 *
 * @warning Allocation with `size` or `count` 0 is undefined behaviour. This version will try to emit a warning through log.h.
 *
 * @param count Number of blocks sized `size` bytes to allocate.
 * @param size Number of bytes in each allocated blocks.
 *
 * @see [cppreference](https://en.cppreference.com/w/c/memory/calloc) description of `calloc`.
 * @see [POSIX.1 2018](https://pubs.opengroup.org/onlinepubs/9699919799/functions/calloc.html) description of `calloc`.
 *
 * @return Allocated memory
 */
void* ceu_scalloc CEU_PARAMS((ceu_size_t count, ceu_size_t size));

/*!
 * @brief A simple wrapper to `realloc` that allows program exit with retv=12
 * if #CEU_NULL is returned.
 *
 * @note In this implementation, the newly allocated memory will **NOT** be initialized with 0.
 * @note If `m` is #CEU_NULL, will convert the call to ::ceu_smalloc.
 *
 * @warning Allocation with `size` 0 is undefined behaviour. This version will try to emit a warning through log.h.
 * @warning If `m` is not a pointer allocated using ::ceu_smalloc, ::ceu_scalloc, ::ceu_srealloc or ::ceu_sreallocarray,
 * or had been previously deallocated, the behaviour is undefined. We have no way to test this. On Microsoft Windows,
 * your program may abort due to such issues.
 *
 * @param m Old allocated memory.
 * @param size Number of bytes to allocate.
 * @see [cppreference](https://en.cppreference.com/w/c/memory/realloc) description of `realloc`.
 * @return Allocated memory
 */
void* ceu_srealloc CEU_PARAMS((void* m, ceu_size_t size));

/*!
 * @brief A simple wrapper to ::ceu_srealloc that allows program exit with retv=12
 * if #CEU_NULL is returned.
 */
void* ceu_sreallocarray CEU_PARAMS((void* m, ceu_size_t count, ceu_size_t size));

/*!
 * @brief Free a piece of memory if it is not #CEU_NULL.
 *
 * @warning If `m` is not a pointer allocated using ::ceu_smalloc, ::ceu_scalloc, ::ceu_srealloc or ::ceu_sreallocarray,
 * or had been previously deallocated, the behaviour is undefined. We have no way to test this. On Microsoft Windows,
 * your program may abort due to such issues.
 * @note If we're not on Microsoft Windows (See #CEU_ON_WINDOWS), the piece of memory will be set to #CEU_NULL afterwards.
 * This will **NOT** be done under Microsoft Windows.
 * @param m The memory to be freed.
 */
void ceu_free_non_null CEU_PARAMS((void* m));

/*!
 * @brief Wait for a keystroke and then exit the program with #EXIT_SUCCESS.
 */
ceu_noreturn void ceu_press_any_key_to_exit CEU_PARAMS((void));

CEU_END_C_DECLS

#endif // CEU_C_UTILS_H
