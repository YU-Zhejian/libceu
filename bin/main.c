#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "ceu_check/ceu_check_all.h"
#include "ceu_check/ceu_c_utils.h"

int main(void)
{
    char *s = ceu_check_get_full_info();
    printf("%s\n", s);
    ceu_free_non_null(s);
    puts("Press any key to exit...");
    getchar();
    return 0;
}

#ifdef __cplusplus
}
#endif
