#include <assert.h>
#include <string.h>

#include "ceu_cstd/ceu_stdio/ceu_printf_core.h"
#include "ceu_cstd/ceu_string.h"

int main(void)
{
    char buff[120] = { "" };

    ceu_snprintf_core(buff, 120, "%d", 120);
    assert(ceu_strcmp(buff, "120") == 0);
    memset(buff, 0, 120);

    ceu_snprintf_core(buff, 120, "%05d", 120);
    assert(ceu_strcmp(buff, "00120") == 0);
    memset(buff, 0, 120);

    ceu_snprintf_core(buff, 120, "%+d", 120);
    assert(ceu_strcmp(buff, "+120") == 0);
    memset(buff, 0, 120);

    ceu_snprintf_core(buff, 120, "%s", "120");
    assert(ceu_strcmp(buff, "120") == 0);
    memset(buff, 0, 120);
}
