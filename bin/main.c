#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_check/ceu_check_all.h"

#include "ceu_ystrlib/ceu_ystrlib_all.h"
#include <stdio.h>

int main(void)
{
    ceu_ystr_t* s = ceu_check_get_full_info();
    char* rets = ceu_ystr_to_cstr(s);
    printf("%s\n", rets);
    ceu_free_non_null(rets);
    ceu_ystr_destroy(s);
    ceu_press_any_key_to_exit();
    return 0; // NOLINT
}

#ifdef __cplusplus
}
#endif
