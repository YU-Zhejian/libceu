#include "ceu_check/ceu_check_cc.h"
#include "ceu_check/ceu_check_helpers.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"

ceu_ystr_t* ceu_check_interpret_compilation_date_time(void)
{
#if defined(__DATE__)
    char* date_str = __DATE__;
#else
    char* date_str = "unknown date";
#endif
#if defined(__TIME__)
    char* time_str = __TIME__;
#else
    char* time_str = "unknown time";
#endif
    ceu_ystr_t* rets = ceu_ystr_cstr_join(", ", ceu_true, 2, date_str, time_str);
    return rets;
}

ceu_ystr_t* interpret_intel_clang_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_INTEL_CLANG)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Intel Clang compatible version number: ", 128);
    ceu_ystr_t* clang_ver = convert_version_to_ystr3(__INTEL_CLANG_COMPILER / 10000, __INTEL_CLANG_COMPILER % 10000 / 100, __INTEL_CLANG_COMPILER % 100);
    ceu_ystr_concat_inplace(rets, clang_ver);
    ceu_ystr_destroy(clang_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_amd_clang_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_AOCC)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("AOCC compatible version number: ", 128);
#ifdef __aocc_major__
    ceu_ystr_t* clang_ver = convert_version_to_ystr3(__aocc_major__, __aocc_minor__, __aocc_patchlevel__);
#else
    ceu_ystr_t* clang_ver = ceu_ystr_create_from_cstr("unknown");
#endif
    ceu_ystr_concat_inplace(rets, clang_ver);
    ceu_ystr_destroy(clang_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_icc_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_ICC)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("ICC compatible version number: ", 128);
    ceu_ystr_t* icc_ver = ceu_ystr_from_uint(10, __ICC);
    ceu_ystr_concat_inplace(rets, icc_ver);
    ceu_ystr_destroy(icc_ver);
#ifdef __INTEL_COMPILER_UPDATE
    ceu_ystr_cstr_concat_inplace(rets, ".");
    ceu_ystr_t* icc_updates_ver = ceu_ystr_from_uint(10, __INTEL_COMPILER_UPDATE);
    ceu_ystr_concat_inplace(rets, icc_updates_ver);
    ceu_ystr_destroy(icc_updates_ver);
#endif
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_msvc_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_MSVC)
#ifdef _MSC_BUILD
    ceu_ystr_t* msc_build_ver = ceu_ystr_from_uint(10, _MSC_BUILD);
#else
    ceu_ystr_t* msc_build_ver = ceu_ystr_create_from_cstr("unknown");
#endif

#ifdef _MSC_FULL_VER
    ceu_ystr_t* msc_internal_ver = ceu_ystr_from_uint(10, _MSC_FULL_VER % 100000);
#else
    ceu_ystr_t* msc_internal_ver = ceu_ystr_create_from_cstr("unknown");
#endif

#ifdef _MSC_VER
    ceu_ystr_t* msc_major_ver = ceu_ystr_from_uint(10, _MSC_VER / 100);
    ceu_ystr_t* msc_minor_ver = ceu_ystr_from_uint(10, _MSC_VER % 100);
#else
    ceu_ystr_t* msc_major_ver = ceu_ystr_create_from_cstr("unknown");
    ceu_ystr_t* msc_minor_ver = ceu_ystr_create_from_cstr("unknown");
#endif
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("MSVC compatible version number: ", 128);
    ceu_ystr_t* sep = ceu_ystr_create_from_cstr(".");
    ceu_ystr_t* msvc_ver = ceu_ystr_join(sep, ceu_false, 4, msc_major_ver, msc_minor_ver, msc_internal_ver, msc_build_ver);
    ceu_ystr_concat_inplace(rets, msvc_ver);
    ceu_ystr_destroy(msvc_ver);
    ceu_ystr_destroy(sep);
    ceu_ystr_destroy(msc_major_ver);
    ceu_ystr_destroy(msc_minor_ver);
    ceu_ystr_destroy(msc_internal_ver);
    ceu_ystr_destroy(msc_build_ver);
    ceu_ystr_cstr_concat_inplace(rets, ", with Visual Studio ver. ");
    ceu_ystr_cstr_concat_inplace(rets, CEU_VISUAL_STUDIO_VER);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_nvhpc_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_NVHPC)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("NVHPC compatible version number: ", 128);
    ceu_ystr_t* nvhpc_ver = convert_version_to_ystr3(__NVCOMPILER_MAJOR__, __NVCOMPILER_MINOR__, __NVCOMPILER_PATCHLEVEL__);
    ceu_ystr_concat_inplace(rets, nvhpc_ver);
    ceu_ystr_destroy(nvhpc_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_pgi_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_PGIC)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("PGI compatible version number: ", 128);
    ceu_ystr_t* pgic_ver = convert_version_to_ystr3(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__);
    ceu_ystr_concat_inplace(rets, pgic_ver);
    ceu_ystr_destroy(pgic_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_tcc_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_TCC)
    int major = __TINYC__ / 10000;
    int minor = (__TINYC__ - major * 10000) / 100;
    int patchlevel = __TINYC__ % 100;

    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("TCC compatible version number: ", 128);
    ceu_ystr_t* tcc_ver = convert_version_to_ystr3(major, minor, patchlevel);
    ceu_ystr_concat_inplace(rets, tcc_ver);
    ceu_ystr_destroy(tcc_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_edg_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_EDG)
    int major = __EDG_VERSION__ / 100;
    int minor = (__EDG_VERSION__ - major * 100);

    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("EDG compatible version number: ", 128);
    ceu_ystr_t* edg_ver = convert_version_to_ystr2(major, minor);
    ceu_ystr_concat_inplace(rets, edg_ver);
    ceu_ystr_destroy(edg_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_broadland_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_BORLAND)
    int major = __BORLANDC__ / 256;
    int revision = (__BORLANDC__ - 256 * major) / 16 + __BORLANDC__ % 16;

    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Broadland compatible version number: ", 128);
    ceu_ystr_t* turboc_ver = convert_version_to_ystr2(major, revision);
    ceu_ystr_concat_inplace(rets, turboc_ver);
    ceu_ystr_destroy(turboc_ver);
    ceu_ystr_cstr_concat_inplace(rets, ", with ");
    ceu_ystr_cstr_concat_inplace(rets, CEU_CPPB_VERSION);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_clang_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_CLANG)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Clang compatible version number: ", 128);
#ifdef __clang_major__
    ceu_ystr_t* clang_ver = convert_version_to_ystr3(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
    ceu_ystr_t* clang_ver = ceu_ystr_create_from_cstr("UNKNOWN");
#endif
    ceu_ystr_concat_inplace(rets, clang_ver);
#ifdef __clang_version__
    ceu_ystr_cstr_concat_inplace(rets, " (");
    ceu_ystr_cstr_concat_inplace(rets, __clang_version__);
    ceu_ystr_cstr_concat_inplace(rets, ")");
#endif
    ceu_ystr_destroy(clang_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_gcc_compiler_version_number(void)
{
#if defined(CEU_COMPILER_IS_GCC)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("GCC compatible version number: ", 128);
#ifdef __GNUC_PATCHLEVEL__
    ceu_ystr_t* gcc_ver = convert_version_to_ystr3(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else
    ceu_ystr_t* gcc_ver = convert_version_to_ystr2(__GNUC__, __GNUC_MINOR__);
#endif
    ceu_ystr_concat_inplace(rets, gcc_ver);
    ceu_ystr_destroy(gcc_ver);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* interpret_compiler_macro_version_number(void)
{
#if defined(__VERSION__)
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("__VERSION__: ", 128);
    ceu_ystr_cstr_concat_inplace(rets, __VERSION__);
    return rets;
#else
    return CEU_NULL;
#endif
}

ceu_ystr_t* ceu_check_interpret_compiler_version_number(void)
{
    ceu_ystr_t* tcc_comp_version = interpret_tcc_compiler_version_number();
    ceu_ystr_t* edg_comp_version = interpret_edg_compiler_version_number();
    ceu_ystr_t* gcc_comp_version = interpret_gcc_compiler_version_number();
    ceu_ystr_t* icc_comp_version = interpret_icc_compiler_version_number();
    ceu_ystr_t* intel_clang_comp_version = interpret_intel_clang_compiler_version_number();
    ceu_ystr_t* amd_clang_comp_version = interpret_amd_clang_compiler_version_number();
    ceu_ystr_t* clang_comp_version = interpret_clang_compiler_version_number();
    ceu_ystr_t* msvc_comp_version = interpret_msvc_compiler_version_number();
    ceu_ystr_t* nvhpc_comp_version = interpret_nvhpc_compiler_version_number();
    ceu_ystr_t* pgi_comp_version = interpret_pgi_compiler_version_number();
    ceu_ystr_t* broadland_comp_version = interpret_broadland_compiler_version_number();
    ceu_ystr_t* version_macro_version = interpret_compiler_macro_version_number();
    ceu_ystr_t* sep = ceu_ystr_create_from_cstr("\n\t");

    ceu_ystr_t* final_buff = ceu_ystr_join(sep, ceu_true, 12, tcc_comp_version, edg_comp_version, gcc_comp_version,
        icc_comp_version, clang_comp_version, msvc_comp_version, pgi_comp_version,
        nvhpc_comp_version, broadland_comp_version, intel_clang_comp_version, amd_clang_comp_version, version_macro_version);
    ceu_ystr_destroy(sep);
    ceu_ystr_destroy(tcc_comp_version);
    ceu_ystr_destroy(edg_comp_version);
    ceu_ystr_destroy(gcc_comp_version);
    ceu_ystr_destroy(icc_comp_version);
    ceu_ystr_destroy(intel_clang_comp_version);
    ceu_ystr_destroy(clang_comp_version);
    ceu_ystr_destroy(msvc_comp_version);
    ceu_ystr_destroy(pgi_comp_version);
    ceu_ystr_destroy(nvhpc_comp_version);
    ceu_ystr_destroy(broadland_comp_version);
    ceu_ystr_destroy(amd_clang_comp_version);
    ceu_ystr_destroy(version_macro_version);
    return final_buff;
}

ceu_ystr_t* ceu_check_get_compiler_info(void)
{
    ceu_ystr_t* date_time_buff = ceu_check_interpret_compilation_date_time();
    ceu_ystr_t* compiler_version_buff = ceu_check_interpret_compiler_version_number();
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("Compiled at ", 128);
    ceu_ystr_concat_inplace(rets, date_time_buff);
    ceu_ystr_cstr_concat_inplace(rets, " with compiler '");
    ceu_ystr_cstr_concat_inplace(rets, CEU_COMPILER_NAME);
    ceu_ystr_cstr_concat_inplace(rets, "' with version:\n\t");
    ceu_ystr_concat_inplace(rets, compiler_version_buff);

    ceu_ystr_destroy(compiler_version_buff);
    ceu_ystr_destroy(date_time_buff);
    return rets;
}
