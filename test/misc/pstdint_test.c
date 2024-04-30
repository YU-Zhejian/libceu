#include <ceu_w32api/pstdint.h>
/*
 *  Please compile with the maximum warning settings to make sure macros are
 *  not defined more than once.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define glue3_aux(x, y, z) x##y##z
#define glue3(x, y, z) glue3_aux(x, y, z)

#define DECLU(bits) glue3(uint, bits, _t) glue3(u, bits, ) = glue3(UINT, bits, _C)(0);
#define DECLI(bits) glue3(int, bits, _t) glue3(i, bits, ) = glue3(INT, bits, _C)(0);

#define DECL(us, bits) glue3(DECL, us, )(bits)

#define TESTUMAX(bits)                               \
    glue3(u, bits, ) = ~glue3(u, bits, );            \
    if (glue3(UINT, bits, _MAX) != glue3(u, bits, )) \
    printf("Something wrong with UINT%d_MAX\n", bits)

#define REPORTERROR(msg)          \
    {                             \
        err_n++;                  \
        if (err_first <= 0)       \
            err_first = __LINE__; \
        printf msg;               \
    }

#define X_SIZE_MAX ((size_t) - 1)

int main()
{
    int err_n = 0;
    int err_first = 0;
    DECL(I, 8)
    DECL(U, 8)
    DECL(I, 16)
    DECL(U, 16)
    DECL(I, 32)
    DECL(U, 32)
#ifdef INT64_MAX
    DECL(I, 64)
    DECL(U, 64)
#endif
    intmax_t imax = INTMAX_C(0);
    uintmax_t umax = UINTMAX_C(0);
    char str0[256], str1[256];

    sprintf(str0, "%" PRINTF_INT32_MODIFIER "d", INT32_C(2147483647));
    if (0 != strcmp(str0, "2147483647"))
        REPORTERROR(("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str0));
    if (atoi(PRINTF_INT32_DEC_WIDTH) != (int)strlen(str0))
        REPORTERROR(("Something wrong with PRINTF_INT32_DEC_WIDTH : %s\n", PRINTF_INT32_DEC_WIDTH));
    sprintf(str0, "%" PRINTF_INT32_MODIFIER "u", UINT32_C(4294967295));
    if (0 != strcmp(str0, "4294967295"))
        REPORTERROR(("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str0));
    if (atoi(PRINTF_UINT32_DEC_WIDTH) != (int)strlen(str0))
        REPORTERROR(("Something wrong with PRINTF_UINT32_DEC_WIDTH : %s\n", PRINTF_UINT32_DEC_WIDTH));
#ifdef INT64_MAX
    sprintf(str1, "%" PRINTF_INT64_MODIFIER "d", INT64_C(9223372036854775807));
    if (0 != strcmp(str1, "9223372036854775807"))
        REPORTERROR(("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str1));
    if (atoi(PRINTF_INT64_DEC_WIDTH) != (int)strlen(str1))
        REPORTERROR(
            ("Something wrong with PRINTF_INT64_DEC_WIDTH : %s, %d\n", PRINTF_INT64_DEC_WIDTH, (int)strlen(str1)));
    sprintf(str1, "%" PRINTF_INT64_MODIFIER "u", UINT64_C(18446744073709550591));
    if (0 != strcmp(str1, "18446744073709550591"))
        REPORTERROR(("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str1));
    if (atoi(PRINTF_UINT64_DEC_WIDTH) != (int)strlen(str1))
        REPORTERROR(
            ("Something wrong with PRINTF_UINT64_DEC_WIDTH : %s, %d\n", PRINTF_UINT64_DEC_WIDTH, (int)strlen(str1)));
#endif

    sprintf(str0, "%d %x\n", 0, ~0);

    sprintf(str1, "%d %x\n", i8, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with i8 : %s\n", str1));
    sprintf(str1, "%u %x\n", u8, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with u8 : %s\n", str1));
    sprintf(str1, "%d %x\n", i16, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with i16 : %s\n", str1));
    sprintf(str1, "%u %x\n", u16, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with u16 : %s\n", str1));
    sprintf(str1, "%" PRINTF_INT32_MODIFIER "d %x\n", i32, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with i32 : %s\n", str1));
    sprintf(str1, "%" PRINTF_INT32_MODIFIER "u %x\n", u32, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with u32 : %s\n", str1));
#ifdef INT64_MAX
    sprintf(str1, "%" PRINTF_INT64_MODIFIER "d %x\n", i64, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with i64 : %s\n", str1));
#endif
    sprintf(str1, "%" PRINTF_INTMAX_MODIFIER "d %x\n", imax, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with imax : %s\n", str1));
    sprintf(str1, "%" PRINTF_INTMAX_MODIFIER "u %x\n", umax, ~0);
    if (0 != strcmp(str0, str1))
        REPORTERROR(("Something wrong with umax : %s\n", str1));

    TESTUMAX(8);
    TESTUMAX(16);
    TESTUMAX(32);
#ifdef INT64_MAX
    TESTUMAX(64);
#endif

#define STR(v) #v
#define Q(v) printf("sizeof " STR(v) " = %u\n", (unsigned)sizeof(v));
    if (err_n) {
        printf("pstdint.h is not correct.  Please use sizes below to correct it:\n");
    }

    Q(int)
    Q(unsigned)
    Q(long int)
    Q(short int)
    Q(int8_t)
    Q(int16_t)
    Q(int32_t)
#ifdef INT64_MAX
    Q(int64_t)
#endif

#if UINT_MAX < X_SIZE_MAX
    printf("UINT_MAX < X_SIZE_MAX\n");
#else
    printf("UINT_MAX >= X_SIZE_MAX\n");
#endif
    printf("%" PRINTF_INT64_MODIFIER "u vs %" PRINTF_INT64_MODIFIER "u\n", UINT_MAX, X_SIZE_MAX);

    return EXIT_SUCCESS;
}
