#define CEU_IS_TESTING_WHETHER_ASSERT_WORKS
#include <ceu_cstd/ceu_assert.h>
#include <minunit.h>

void test_setup(void)
{
    // Empty
}
void test_teardown(void)
{
    // Empty
}

MU_TEST(test_nop)
{
#define CEU_NDEBUG // NOLINT
#include <ceu_cstd/ceu_assert.h> // NOLINT // NOSONAR
    ceu_assert(0); // Nothing should happen
    ceu_assert(1); // Nothing should happen
    ceu_assert((1)); // Nothing should happen
}

MU_TEST(test_op)
{
#undef CEU_NDEBUG // NOLINT
#include <ceu_cstd/ceu_assert.h> // NOLINT
    mu_assert_string_eq("", ceu_assert(0));
    mu_assert_string_eq("Assertion failed on TEST_FILE:0 1", ceu_assert(1));
    mu_assert_string_eq("Assertion failed on TEST_FILE:0 (1)", ceu_assert((1)));
}

MU_TEST_SUITE(assert_tests)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_nop);
    MU_RUN_TEST(test_op);
}

int main(void)
{
    MU_RUN_SUITE(assert_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}
