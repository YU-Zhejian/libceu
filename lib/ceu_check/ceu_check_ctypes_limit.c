#include "ceu_check/ceu_check_ctypes_limit.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_cstd/ceu_stdint.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"
#include <ceu_cstd/ceu_stdbool.h>
#include <stdio.h>

// FIXME: Temporary fix for Microsoft Visual Studio 2010.
// #define snprintf _snprintf

ceu_ystr_t* ceu_check_get_ctypes_limit_info(void)
{
    ceu_size_t buff_len = 1024;
    char* char_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* schar_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* uchar_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* size_t_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* short_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* ushort_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* int_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* uint_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* long_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* ulong_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* llong_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* bool_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    char* ullong_info = (char*)ceu_scalloc(buff_len, sizeof(char));
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Compile-time C Types max, min, etc. limits:", 4096);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(char_info, buff_len, "char      (%d bits, %zu size):      %+21d -> %+21d", CHAR_BIT,
        sizeof(char), CHAR_MIN, CHAR_MAX);
    ceu_ystr_cstr_concat_inplace(rets, char_info);
    ceu_free_non_null(char_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(schar_info, buff_len, "schar     (%zu size):              %+21d -> %+21d",
        sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    ceu_ystr_cstr_concat_inplace(rets, schar_info);
    ceu_free_non_null(schar_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(uchar_info, buff_len, "uchar     (%zu size):              %+21d -> %+21d",
        sizeof(unsigned char), 0, UCHAR_MAX);
    ceu_ystr_cstr_concat_inplace(rets, uchar_info);
    ceu_free_non_null(uchar_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(size_t_info, buff_len, "ceu_size_t    (%zu size):              %+21d -> %21llu",
        sizeof(ceu_size_t), 0, (unsigned long long)SIZE_MAX);
    ceu_ystr_cstr_concat_inplace(rets, size_t_info);
    ceu_free_non_null(size_t_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(short_info, buff_len, "short     (%zu size):              %+21hd -> %+21hd",
        sizeof(short), SHRT_MIN, SHRT_MAX);
    ceu_ystr_cstr_concat_inplace(rets, short_info);
    ceu_free_non_null(short_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(ushort_info, buff_len, "ushort    (%zu size):              %+21hd -> %21hu",
        sizeof(unsigned short), 0u, USHRT_MAX);
    ceu_ystr_cstr_concat_inplace(rets, ushort_info);
    ceu_free_non_null(ushort_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(int_info, buff_len, "int       (%zu size):              %+21d -> %+21d", sizeof(int),
        INT_MIN, INT_MAX);
    ceu_ystr_cstr_concat_inplace(rets, int_info);
    ceu_free_non_null(int_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(uint_info, buff_len, "uint      (%zu size):              %+21d -> %21u",
        sizeof(unsigned int), 0u, UINT_MAX);
    ceu_ystr_cstr_concat_inplace(rets, uint_info);
    ceu_free_non_null(uint_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(long_info, buff_len, "long      (%zu size):              %+21ld -> %+21ld",
        sizeof(long), LONG_MIN, LONG_MAX);
    ceu_ystr_cstr_concat_inplace(rets, long_info);
    ceu_free_non_null(long_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(ulong_info, buff_len, "ulong     (%zu size):              %+21d -> %21lu",
        sizeof(unsigned long), 0, ULONG_MAX);
    ceu_ystr_cstr_concat_inplace(rets, ulong_info);
    ceu_free_non_null(ulong_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(llong_info, buff_len, "llong     (%zu size):              %+21lld -> %+21lld",
        sizeof(long long), LLONG_MIN, LLONG_MAX);
    ceu_ystr_cstr_concat_inplace(rets, llong_info);
    ceu_free_non_null(llong_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(ullong_info, buff_len, "ullong    (%zu size):              %+21d -> %21llu",
        sizeof(unsigned long long), 0, ULLONG_MAX);
    ceu_ystr_cstr_concat_inplace(rets, ullong_info);
    ceu_free_non_null(ullong_info);

    ceu_ystr_cstr_concat_inplace(rets, "\n\t");
    snprintf(bool_info, buff_len, "bool      (%zu size):              %+21d -> %+21d", sizeof(bool),
        false, true);
    ceu_ystr_cstr_concat_inplace(rets, bool_info);
    ceu_free_non_null(bool_info);

    return rets;
}
