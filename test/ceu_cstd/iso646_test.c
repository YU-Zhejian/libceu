#ifdef __cplusplus
// Supressed in C++
int main(void)
{
    return 0;
}
#else
#include "minunit.h"
#include <ceu_cstd/ceu_stdbool.h>
#include <ceu_cstd/ceu_iso646.h>

void test_setup(void)
{
    // Empty
}
void test_teardown(void)
{
    // Empty
}

MU_TEST(basic_true_false)
{
    ceu_bool t = ceu_true;
    ceu_bool f = ceu_false;
    mu_assert_int_eq(1, t);
    mu_assert_int_eq(0, f);
    mu_assert_int_eq(0, t and f);
    mu_assert_int_eq(1, t or f);
    mu_assert_int_eq(0, not t);
    mu_assert_int_eq(1, not f);
    mu_assert_int_eq(1, t and t);
    mu_assert_int_eq(1, t or t);
    mu_assert_int_eq(0, f and f);
    mu_assert_int_eq(0, f and f);
    mu_assert_int_eq(0, f xor f);
    mu_assert_int_eq(0, t xor t);
    mu_assert_int_eq(1, t xor f);
    mu_assert_int_eq(1, f xor t);

    // and_eq
    f and_eq f;
    mu_assert_int_eq(0, f);
    t and_eq t;
    mu_assert_int_eq(1, t);
    t and_eq f;
    mu_assert_int_eq(0, t);
    t = ceu_true;
    f and_eq t;
    mu_assert_int_eq(0, f);
}

MU_TEST_SUITE(iso646_tests)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(basic_true_false);
}

int main(void)
{
    MU_RUN_SUITE(iso646_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}

#endif
