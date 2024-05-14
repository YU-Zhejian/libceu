#ifdef __cplusplus
// Supressed in C++
int main(void)
{
    return 0;
}
#else
#include "minunit.h"
#include <ceu_cstd/ceu_stdbool.h>

// Check for C minimun standard in pre-processor
#if (1)
// As expected where 1 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (0)
#error "Your pre-processor does not comfort C minumun standard."
#else
// As expected where 0 evaluated to false.
#endif

#if (!0)
// As expected where !0 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (!!1)
// As expected where !!1 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if ((!(!4)) == 1)
// As expected where !!4 evaluated to 1.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (1 && 1)
// As expected where 1 && 1 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (1 || 1)
// As expected where 1 || 1 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (1 || 0)
// As expected where 1 || 0 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (0 || 1)
// As expected where 0 || 1 evaluated to true.
#else
#error "Your pre-processor does not comfort C minumun standard."
#endif

#if (0 && 1)
#error "Your pre-processor does not comfort C minumun standard."
#else
// As expected where 0 && 1 evaluated to false.
#endif

#if (1 && 0)
#error "Your pre-processor does not comfort C minumun standard."
#else
// As expected where 1 && 0 evaluated to false.
#endif

#if (0 && 0)
#error "Your pre-processor does not comfort C minumun standard."
#else
// As expected where 0 && 0 evaluated to false.
#endif

#if (0 || 0)
#error "Your pre-processor does not comfort C minumun standard."
#else
// As expected where 0 || 0 evaluated to false.
#endif

#if !defined(__bool_true_false_are_defined) || __bool_true_false_are_defined != 1
#error "__bool_true_false_are_defined should have been defined to 1!"
#endif

#define BOOL_ASSERTS             \
    mu_assert_int_eq(1, t);      \
    mu_assert_int_eq(0, f);      \
    mu_assert_int_eq(0, t&& f);  \
    mu_assert_int_eq(1, t || f); \
    mu_assert_int_eq(0, !t);     \
    mu_assert_int_eq(1, !f);     \
    mu_assert_int_eq(1, t&& t);  \
    mu_assert_int_eq(1, t || t); \
    mu_assert_int_eq(0, f&& f);  \
    mu_assert_int_eq(0, f || f); \
    mu_assert_int_eq(0, t ^ t);  \
    mu_assert_int_eq(0, f ^ f);  \
    mu_assert_int_eq(1, t ^ f);  \
    mu_assert_int_eq(1, f ^ t);

void test_setup(void)
{
    // Empty
}
void test_teardown(void)
{
    // Empty
}

MU_TEST(working_if)
{
    if (1) {
        // As expected where 1 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }
    if (0) {
        mu_fail("Your if statement does not comfort C minumun standard.");
    } else {
        // As expected where 0 evaluated to false.
    }

    if (!0) {
        // As expected where !0 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (!!1) {
        // As expected where !!1 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if ((!(!4)) == 1) {
        // As expected where !!4 evaluated to 1.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (1 && 1) {
        // As expected where 1 && 1 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (1 || 1) {
        // As expected where 1 || 1 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (1 || 0) {
        // As expected where 1 || 0 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (0 || 1) {
        // As expected where 0 || 1 evaluated to true.
    } else {
        mu_fail("Your if statement does not comfort C minumun standard.");
    }

    if (0 && 1) {
        mu_fail("Your if statement does not comfort C minumun standard.");
    } else {
        // As expected where 0 && 1 evaluated to false.
    }

    if (1 && 0) {
        mu_fail("Your if statement does not comfort C minumun standard.");
    } else {
        // As expected where 1 && 0 evaluated to false.
    }

    if (0 && 0) {
        mu_fail("Your if statement does not comfort C minumun standard.");
    } else {
        // As expected where 0 && 0 evaluated to false.
    }

    if (0 || 0) {
        mu_fail("Your if statement does not comfort C minumun standard.");
    } else {
        // As expected where 0 || 0 evaluated to false.
    }
    // Test for other operators will be at #BOOL_ASSERTS.
}

MU_TEST(basic_true_false)
{
    bool t = true;
    bool f = false;
    BOOL_ASSERTS
}

MU_TEST(bool_from_int)
{
    bool t = 1;
    bool f = 0;
    BOOL_ASSERTS
}

MU_TEST_SUITE(bool_tests)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(working_if);
    MU_RUN_TEST(basic_true_false);
    MU_RUN_TEST(bool_from_int);
}

int main(void)
{
    MU_RUN_SUITE(bool_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}

#endif
