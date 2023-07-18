#ifndef CEU_CHECK_UTILS_H
#define CEU_CHECK_UTILS_H
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CEU_STR_JOIN_RETURN_NULL = 0,
    CEU_STR_JOIN_REGARD_AS_EMPTY_STR = 1,
    CEU_STR_JOIN_SKIP = 2,
    CEU_STR_JOIN_WARN_SKIP = 3
} ceu_str_join_null_action_t;

char* ceu_str_join(char* buff1, char* buff2);

char* ceu_str_join_with_sep(char* sep, ceu_str_join_null_action_t nb, int count, ...);
#ifdef __cplusplus
}
#endif

#endif
