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
        char* end = NULL;                                                         \
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

TEST_INT(int8_t, "127", "-128", INT8_MAX, INT8_MIN, "%" CEU_INT8_PRINTF_MODIFIER, CEU_INT8_SIZE, strtol)
TEST_INT(uint8_t, "255", "0", UINT8_MAX, 0, "%" CEU_UINT8_PRINTF_MODIFIER, CEU_INT8_SIZE, strtol)
TEST_INT(int16_t, "32767", "-32768", INT16_MAX, INT16_MIN, "%" CEU_INT16_PRINTF_MODIFIER, CEU_INT16_SIZE, strtol)
TEST_INT(uint16_t, "65535", "0", UINT16_MAX, 0, "%" CEU_UINT16_PRINTF_MODIFIER, CEU_INT16_SIZE, strtol)
TEST_INT(int32_t, "2147483647", "-2147483648", INT32_MAX, INT32_MIN, "%" CEU_INT32_PRINTF_MODIFIER, CEU_INT32_SIZE, strtol)
TEST_INT(uint32_t, "4294967295", "0", UINT32_MAX, 0LL, "%" CEU_UINT32_PRINTF_MODIFIER, CEU_INT32_SIZE, strtoul)
TEST_INT(int64_t, "9223372036854775807", "-9223372036854775808", INT64_MAX, INT64_MIN, "%" CEU_INT64_PRINTF_MODIFIER, CEU_INT64_SIZE, strtoll)
TEST_INT(uint64_t, "18446744073709551615", "0", UINT64_MAX, 0ULL, "%" CEU_UINT64_PRINTF_MODIFIER, CEU_INT64_SIZE, strtoull)

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_int8_t);
    MU_RUN_TEST(test_uint8_t);
    MU_RUN_TEST(test_int16_t);
    MU_RUN_TEST(test_uint16_t);
    MU_RUN_TEST(test_int32_t);
    MU_RUN_TEST(test_uint32_t);
    MU_RUN_TEST(test_int64_t);
    MU_RUN_TEST(test_uint64_t);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
