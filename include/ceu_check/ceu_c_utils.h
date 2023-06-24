#ifndef CEU_APPEND_SPRINTF_H
#define CEU_APPEND_SPRINTF_H
#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef enum
{
	CEU_STR_JOIN_RETURN_NULL = 0,
	CEU_STR_JOIN_REGARD_AS_EMPTY_STR = 1,
	CEU_STR_JOIN_SKIP = 2,
	CEU_STR_JOIN_WARN_SKIP = 3
} ceu_str_join_null_action_t;


void ceu_die_with_retv(const char* reason, int retv);

void ceu_die(const char* reason);

/*!
 * @brief A simple wrapper to malloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_smalloc(size_t size);

/*!
* @brief A simple wrapper to realloc() that allows program exit with retv=12 if failed.
* @param size Number of bytes to allocate.
* @return Allocated memory
*/
void* ceu_srealloc(void* m, size_t size);

/*!
 * @brief A simple wrapper to calloc() that allows program exit with retv=12 if failed.
 * @param size Number of bytes to allocate.
 * @return Allocated memory
 */
void* ceu_scalloc(size_t count, size_t size);

void ceu_free_non_null(void* m);

char* ceu_str_join(char* buff1, char* buff2);

char* ceu_str_join_with_sep(char* sep, ceu_str_join_null_action_t nb, int count, ...);

#ifdef __cplusplus
}
#endif

#endif
