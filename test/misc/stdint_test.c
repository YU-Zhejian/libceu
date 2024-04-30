#include "ceu_basic/ceu_fast_macros.h"
#include "minunit.h"
#include <ceu_w32api/pstdint.h>
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

TEST_INT(int8_t, "127", "-128", 127, -128, "%d", 1, strtol)
TEST_INT(uint8_t, "255", "0", 255, 0, "%u", 1, strtol)
TEST_INT(int16_t, "32767", "-32768", 32767, -32768, "%d", 2, strtol)
TEST_INT(uint16_t, "65535", "0", 65535, 0, "%u", 2, strtol)
TEST_INT(int32_t, "2147483647", "-2147483648", 2147483647, -2147483648, "%d", 4, strtol)
TEST_INT(uint32_t, "4294967295", "0", 4294967295LL, 0LL, "%u", 4, strtoul)
TEST_INT(int64_t, "9223372036854775807", "-9223372036854775808", 9223372036854775807LL, (-9223372036854775807LL - 1LL), "%lld", 8, strtoll)
TEST_INT(uint64_t, "18446744073709551615", "0", 18446744073709551615ULL, 0ULL, "%llu", 8, strtoull)

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
