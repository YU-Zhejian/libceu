#ifndef CEU_CHECK_C_CXX_STD_PRIV_H
#define CEU_CHECK_C_CXX_STD_PRIV_H

#include "ceu_check/ceu_check_c_cxx_std.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"

ceu_ystr_t* ceu_interpret_c_std_version(void)
{
    ceu_ystr_t* cstd_macro;
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Compile-time C std.: ver. ", 128);
    ceu_ystr_cstr_concat_inplace(rets, CEU_C_STD);
#ifdef CEU_C_STD_VERSION_MACRO
    cstd_macro = ceu_ystr_from_uint(10, CEU_C_STD_VERSION_MACRO);
#else
    cstd_macro = ceu_ystr_create_from_cstr("__STDC_VERSION__ undefined");
#endif
    ceu_ystr_cstr_concat_inplace(rets, " (");
    ceu_ystr_concat_inplace(rets, cstd_macro);
    ceu_ystr_cstr_concat_inplace(rets, ")");
    ceu_ystr_destroy(cstd_macro);
    return rets;
}

ceu_ystr_t* ceu_interpret_cxx_std_version(void)
{
    ceu_ystr_t* cxxstd_macro;
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Compile-time C++ std.: ver. ", 128);
    ceu_ystr_cstr_concat_inplace(rets, CEU_CXX_STD);
#ifdef CEU_CXX_STD_VERSION_MACRO
    cxxstd_macro = ceu_ystr_from_uint(10, CEU_CXX_STD_VERSION_MACRO);
#else
    cxxstd_macro = ceu_ystr_create_from_cstr("_MSVC_LANG and __cplusplus undefined");
#endif
    ceu_ystr_cstr_concat_inplace(rets, " (");
    ceu_ystr_concat_inplace(rets, cxxstd_macro);
    ceu_ystr_cstr_concat_inplace(rets, ")");
    ceu_ystr_destroy(cxxstd_macro);
    return rets;
}
#endif
