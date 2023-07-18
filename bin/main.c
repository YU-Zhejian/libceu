#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_c_utils.h"
#include "ceu_check/ceu_check_all.h"
#include <stdio.h>

int main(void)
{
    char* s = ceu_check_get_full_info();
    printf("%s\n", s);
    ceu_free_non_null(s);
    ceu_press_any_key_to_exit();
    return 0;
}

#ifdef __cplusplus
}
#endif
