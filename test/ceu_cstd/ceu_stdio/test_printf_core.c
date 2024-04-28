#include "minunit.h"

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_cstd/ceu_stdio/ceu_printf_core.h"
#include "ceu_cstd/ceu_string.h"

static char buff[120] = { "" };
void test_setup(void)
{
    ceu_memset(buff, 0, 120);
}
void test_teardown(void)
{
    // Empty
}

MU_TEST(C1)
{
    ceu_snprintf_core(buff, 120, "%d", 120);
    mu_assert_string_eq(buff, "120");
    ceu_memset(buff, 0, 120);
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(C1);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
