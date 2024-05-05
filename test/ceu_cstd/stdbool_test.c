#ifdef __cplusplus
// Supressed in C++
int main(void)
{
    return 0;
}
#else
#include "minunit.h"
#include <ceu_cstd/ceu_stdbool.h>

#if !defined(__bool_true_false_are_defined) || __bool_true_false_are_defined != 1
#error "__bool_true_false_are_defined should have been defined to 1!"
#endif

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
    bool t = true;
    bool f = false;
    mu_assert_int_eq(1, t);
    mu_assert_int_eq(0, f);
    mu_assert_int_eq(0, t && f);
    mu_assert_int_eq(1, t || f);
    mu_assert_int_eq(0, !t);
    mu_assert_int_eq(1, !f);
    mu_assert_int_eq(1, t && t);
    mu_assert_int_eq(1, t || t);
    mu_assert_int_eq(0, f && f);
    mu_assert_int_eq(0, f || f);
}

MU_TEST(bool_from_int)
{
    bool t = 1;
    bool f = 0;
    mu_assert_int_eq(1, t);
    mu_assert_int_eq(0, f);
    mu_assert_int_eq(0, t && f);
    mu_assert_int_eq(1, t || f);
    mu_assert_int_eq(0, !t);
    mu_assert_int_eq(1, !f);
    mu_assert_int_eq(1, t && t);
    mu_assert_int_eq(1, t || t);
    mu_assert_int_eq(0, f && f);
    mu_assert_int_eq(0, f || f);
}

MU_TEST(bool_from_int_unstandard)
{
    bool t = 4;
    bool f = 0;
    mu_assert_int_eq(1, t);
    mu_assert_int_eq(0, f);
    mu_assert_int_eq(0, t && f);
    mu_assert_int_eq(1, t || f);
    mu_assert_int_eq(0, !t);
    mu_assert_int_eq(1, !f);
    mu_assert_int_eq(1, t && t);
    mu_assert_int_eq(1, t || t);
    mu_assert_int_eq(0, f && f);
    mu_assert_int_eq(0, f || f);
}

MU_TEST(bool_from_int_unstandard2)
{
    bool t = -125;
    bool f = 0;
    mu_assert_int_eq(1, t);
    mu_assert_int_eq(0, f);
    mu_assert_int_eq(0, t && f);
    mu_assert_int_eq(1, t || f);
    mu_assert_int_eq(0, !t);
    mu_assert_int_eq(1, !f);
    mu_assert_int_eq(1, t && t);
    mu_assert_int_eq(1, t || t);
    mu_assert_int_eq(0, f && f);
    mu_assert_int_eq(0, f || f);
}

MU_TEST_SUITE(bool_tests)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(basic_true_false);
    MU_RUN_TEST(bool_from_int);
    MU_RUN_TEST(bool_from_int_unstandard);
    MU_RUN_TEST(bool_from_int_unstandard2);
}

int main(void)
{
    MU_RUN_SUITE(bool_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}

#endif
