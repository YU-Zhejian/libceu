#include "minunit.h"

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"

void test_setup(void)
{
    // Empty
}
void test_teardown(void)
{
    // Empty
}

MU_TEST(ystr_create_empty)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_empty();
    mu_assert_int_eq(DEFAULT_CEU_YSTR_SIZE + 1, ystr1->buff_length);
    mu_assert_int_eq(0, ystr1->consumed_length);
    mu_assert_string_eq("", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_create_sized)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_sized(10);
    mu_assert_int_eq(10 + 1, ystr1->buff_length);
    mu_assert_int_eq(0, ystr1->consumed_length);
    mu_assert_string_eq("", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_create_from_cstr)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10", 0);
    mu_assert_int_eq(2 + 1, ystr1->buff_length);
    mu_assert_int_eq(2, ystr1->consumed_length);
    mu_assert_string_eq("10", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_create_from_cstr2)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10", 10);
    mu_assert_int_eq(12 + 1, ystr1->buff_length);
    mu_assert_int_eq(2, ystr1->consumed_length);
    mu_assert_string_eq("10", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_create_from_cstr3)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    mu_assert_int_eq(12 + 1, ystr1->buff_length);
    mu_assert_int_eq(2, ystr1->consumed_length);
    mu_assert_string_eq("10", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_clear)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    ceu_ystr_clear(ystr1);
    mu_assert_int_eq(12 + 1, ystr1->buff_length);
    mu_assert_int_eq(0, ystr1->consumed_length);
    mu_assert_string_eq("", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_clean)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    ceu_ystr_clean(ystr1);
    mu_assert_int_eq(DEFAULT_CEU_YSTR_SIZE + 1, ystr1->buff_length);
    mu_assert_int_eq(0, ystr1->consumed_length);
    mu_assert_string_eq("", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_to_cstr)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    char* cstr = ceu_ystr_to_cstr(ystr1);
    mu_assert_string_eq("10", cstr);
    ceu_ystr_destroy(ystr1);
    ceu_free_non_null(cstr);
}

MU_TEST(ystr_to_cstr_cpy)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    char* cstr = (char*)ceu_scalloc(100, sizeof(char));
    ceu_ystr_to_cstr_cpy(ystr1, cstr);
    mu_assert_string_eq("10", cstr);
    ceu_ystr_destroy(ystr1);
    ceu_free_non_null(cstr);
}

MU_TEST(ystr_to_cstr_ncpy)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("1000000", 0);
    char* cstr = (char*)ceu_scalloc(100, sizeof(char));
    ceu_ystr_to_cstr_ncpy(ystr1, cstr, 3);
    mu_assert_string_eq("100", cstr);
    ceu_ystr_destroy(ystr1);
    ceu_free_non_null(cstr);
}

MU_TEST(ystr_to_cstr_ncpy2)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10", 0);
    char* cstr = (char*)ceu_scalloc(100, sizeof(char));
    ceu_ystr_to_cstr_ncpy(ystr1, cstr, 100);
    mu_assert_string_eq("10", cstr);
    ceu_ystr_destroy(ystr1);
    ceu_free_non_null(cstr);
}

MU_TEST(ystr_copy)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("10\0SomeOtherContent", 10);
    ceu_ystr_t* ystr2 = ceu_ystr_copy(ystr1);
    mu_assert_string_eq(ystr1->buff, ystr2->buff);
    mu_assert_int_eq(ystr1->buff_length, ystr2->buff_length);
    mu_assert_int_eq(ystr1->consumed_length, ystr2->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr2);
}

MU_TEST(ystr_shrink)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("1000", 10);
    ceu_ystr_shrink(ystr1, 18);
    mu_assert_string_eq("1000", ystr1->buff);
    mu_assert_int_eq(15, ystr1->buff_length);
    mu_assert_int_eq(4, ystr1->consumed_length);
    ceu_ystr_shrink(ystr1, 8);
    mu_assert_string_eq("1000", ystr1->buff);
    mu_assert_int_eq(8, ystr1->buff_length);
    mu_assert_int_eq(4, ystr1->consumed_length);
    ceu_ystr_shrink(ystr1, 3);
    mu_assert_string_eq("10", ystr1->buff);
    mu_assert_int_eq(3, ystr1->buff_length);
    mu_assert_int_eq(2, ystr1->consumed_length);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_garantee)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3", 0);
    ceu_ystr_guarantee(ystr1, 10);
    mu_assert_string_eq("3", ystr1->buff);
    mu_assert_int_eq(10, ystr1->buff_length);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_concat_inplace)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 0);
    ceu_ystr_t* ystr2 = ceu_ystr_create_from_cstr("km/h", 0);
    ceu_ystr_concat_inplace(ystr1, ystr2);
    mu_assert_string_eq("3000km/h", ystr1->buff);
    mu_assert_int_eq(9, ystr1->buff_length);
    mu_assert_int_eq(8, ystr1->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr2);
}

MU_TEST(ystr_concat_inplace2)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 10);
    ceu_ystr_t* ystr2 = ceu_ystr_create_from_cstr("km/h", 0);
    ceu_ystr_concat_inplace(ystr1, ystr2);
    mu_assert_string_eq("3000km/h", ystr1->buff);
    mu_assert_int_eq(15, ystr1->buff_length);
    mu_assert_int_eq(8, ystr1->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr2);
}

MU_TEST(ystr_concat_inplace3)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 10);
    ceu_ystr_cstr_concat_inplace(ystr1, "km/h");
    mu_assert_string_eq("3000km/h", ystr1->buff);
    mu_assert_int_eq(15, ystr1->buff_length);
    mu_assert_int_eq(8, ystr1->consumed_length);
    ceu_ystr_destroy(ystr1);
}

MU_TEST(ystr_concat_const)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 0);
    ceu_ystr_t* ystr2 = ceu_ystr_create_from_cstr("km/h", 0);
    ceu_ystr_t* ystr_ret = ceu_ystr_concat_const(ystr1, ystr2);
    mu_assert_string_eq("3000km/h", ystr_ret->buff);
    mu_assert_int_eq(9, ystr_ret->buff_length);
    mu_assert_int_eq(8, ystr_ret->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr2);
    ceu_ystr_destroy(ystr_ret);
}

MU_TEST(ystr_concat_const2)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 10);
    ceu_ystr_t* ystr2 = ceu_ystr_create_from_cstr("km/h", 0);
    ceu_ystr_t* ystr_ret = ceu_ystr_concat_const(ystr1, ystr2);
    mu_assert_string_eq("3000km/h", ystr_ret->buff);
    mu_assert_int_eq(15, ystr_ret->buff_length);
    mu_assert_int_eq(8, ystr_ret->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr2);
    ceu_ystr_destroy(ystr_ret);
}

MU_TEST(ystr_concat_const3)
{
    ceu_ystr_t* ystr1 = ceu_ystr_create_from_cstr("3000", 10);
    ceu_ystr_t* ystr_ret = ceu_ystr_cstr_concat_const(ystr1, "km/h");
    mu_assert_string_eq("3000km/h", ystr_ret->buff);
    mu_assert_int_eq(15, ystr_ret->buff_length);
    mu_assert_int_eq(8, ystr_ret->consumed_length);
    ceu_ystr_destroy(ystr1);
    ceu_ystr_destroy(ystr_ret);
}

MU_TEST(ystr_int)
{
    ceu_ystr_t* ystr1;
    ystr1 = ceu_ystr_from_uint(10, 120);
    mu_assert_string_eq("120", ystr1->buff);
    ceu_ystr_destroy(ystr1);

    ystr1 = ceu_ystr_from_uint(2, 120);
    mu_assert_string_eq("1111000", ystr1->buff);
    ceu_ystr_destroy(ystr1);

    ystr1 = ceu_ystr_from_uint(16, 120);
    mu_assert_string_eq("78", ystr1->buff);
    ceu_ystr_destroy(ystr1);

    ystr1 = ceu_ystr_from_uint(16, UINT64_MAX);
    mu_assert_string_eq("FFFFFFFFFFFFFFFF", ystr1->buff);
    ceu_ystr_destroy(ystr1);

    ystr1 = ceu_ystr_from_uint(2, UINT64_MAX);
    mu_assert_string_eq("1111111111111111111111111111111111111111111111111111111111111111", ystr1->buff);
    ceu_ystr_destroy(ystr1);

    ystr1 = ceu_ystr_from_uint(10, UINT64_MAX);
    mu_assert_string_eq("18446744073709551615", ystr1->buff);
    ceu_ystr_destroy(ystr1);
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(ystr_create_empty);
    MU_RUN_TEST(ystr_create_sized);
    MU_RUN_TEST(ystr_create_from_cstr);
    MU_RUN_TEST(ystr_create_from_cstr2);
    MU_RUN_TEST(ystr_create_from_cstr3);
    MU_RUN_TEST(ystr_clear);
    MU_RUN_TEST(ystr_clean);
    MU_RUN_TEST(ystr_to_cstr);
    MU_RUN_TEST(ystr_to_cstr_cpy);
    MU_RUN_TEST(ystr_to_cstr_ncpy);
    MU_RUN_TEST(ystr_to_cstr_ncpy2);
    MU_RUN_TEST(ystr_copy);
    MU_RUN_TEST(ystr_garantee);
    MU_RUN_TEST(ystr_concat_inplace);
    MU_RUN_TEST(ystr_concat_inplace2);
    MU_RUN_TEST(ystr_concat_inplace3);
    MU_RUN_TEST(ystr_concat_const);
    MU_RUN_TEST(ystr_concat_const2);
    MU_RUN_TEST(ystr_concat_const3);
    MU_RUN_TEST(ystr_shrink);
    MU_RUN_TEST(ystr_int);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
