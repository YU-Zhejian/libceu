#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_stdint.h"
#include "minunit.h"
#include <stdio.h>
#include <stdlib.h>

void test_setup(void)
{
    // Empty
}
void test_teardown(void)
{
    // Empty
}

#define TEST_INT(type_name, max_s, min_s, max_i, min_i, printf_mod, size, strtox) \
    MU_TEST(test_##type_name)                                                     \
    {                                                                             \
        char* end = CEU_NULL;                                                     \
        char var_max[] = { max_s };                                               \
        char var_min[] = { min_s };                                               \
        type_name test_var = strtox(max_s, &end, 10);                             \
        mu_assert(test_var == max_i, "");                                         \
        type_name test_var2 = strtox(min_s, &end, 10);                            \
        mu_assert(test_var2 == min_i, "");                                        \
        char buff[128] = { CEU_STRING_ENDING };                                   \
        sprintf(buff, printf_mod, test_var);                                      \
        mu_assert_string_eq(buff, var_max);                                       \
        test_var += 1;                                                            \
        mu_assert(test_var == min_i, "");                                         \
        sprintf(buff, printf_mod, test_var);                                      \
        mu_assert_string_eq(buff, var_min);                                       \
        mu_assert_int_eq(size, sizeof(type_name));                                \
    }
#define SIGNED_MODIFIER "d"
#define UNSIGNED_MODIFIER "u"

TEST_INT(ceu_int8_t, "127", "-128", INT8_MAX, INT8_MIN, "%" CEU_INT8_PRINTF_MODIFIER SIGNED_MODIFIER, CEU_INT8_SIZE, strtol)
TEST_INT(ceu_uint8_t, "255", "0", UINT8_MAX, 0, "%" CEU_INT8_PRINTF_MODIFIER UNSIGNED_MODIFIER, CEU_INT8_SIZE, strtol)
TEST_INT(ceu_int16_t, "32767", "-32768", INT16_MAX, INT16_MIN, "%" CEU_INT16_PRINTF_MODIFIER SIGNED_MODIFIER, CEU_INT16_SIZE, strtol)
TEST_INT(ceu_uint16_t, "65535", "0", UINT16_MAX, 0, "%" CEU_INT16_PRINTF_MODIFIER UNSIGNED_MODIFIER, CEU_INT16_SIZE, strtol)
TEST_INT(ceu_int32_t, "2147483647", "-2147483648", INT32_MAX, INT32_MIN, "%" CEU_INT32_PRINTF_MODIFIER SIGNED_MODIFIER, CEU_INT32_SIZE, strtol)
TEST_INT(ceu_uint32_t, "4294967295", "0", UINT32_MAX, 0, "%" CEU_INT32_PRINTF_MODIFIER UNSIGNED_MODIFIER, CEU_INT32_SIZE, strtoul)
TEST_INT(ceu_int64_t, "9223372036854775807", "-9223372036854775808", INT64_MAX, INT64_MIN, "%" CEU_INT64_PRINTF_MODIFIER SIGNED_MODIFIER, CEU_INT64_SIZE, strtoll)
TEST_INT(ceu_uint64_t, "18446744073709551615", "0", UINT64_MAX, 0, "%" CEU_INT64_PRINTF_MODIFIER UNSIGNED_MODIFIER, CEU_INT64_SIZE, strtoull)

MU_TEST(test_eq)
{
    mu_assert(INT8_MAX == CEU_INT8_C(127), "");
    mu_assert(UINT8_MAX == CEU_UINT8_C(255), "");
    mu_assert(INT16_MAX == CEU_INT16_C(32767), "");
    mu_assert(UINT16_MAX == CEU_UINT16_C(65535), "");
    mu_assert(INT32_MAX == CEU_INT32_C(2147483647), "");
    mu_assert(UINT32_MAX == CEU_UINT32_C(4294967295), "");
    mu_assert(INT64_MAX == CEU_INT64_C(9223372036854775807), "");
    mu_assert(UINT64_MAX == CEU_UINT64_C(18446744073709551615), "");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_ceu_int8_t);
    MU_RUN_TEST(test_ceu_uint8_t);
    MU_RUN_TEST(test_ceu_int16_t);
    MU_RUN_TEST(test_ceu_uint16_t);
    MU_RUN_TEST(test_ceu_int32_t);
    MU_RUN_TEST(test_ceu_uint32_t);
    MU_RUN_TEST(test_ceu_int64_t);
    MU_RUN_TEST(test_ceu_uint64_t);
    MU_RUN_TEST(test_eq);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
