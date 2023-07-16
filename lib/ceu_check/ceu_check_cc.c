#include <stdio.h>
#include <stdlib.h>

#include "ceu_check/ceu_check_cc.h"
#include "ceu_cstd/ceu_stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

char* ceu_check_interpret_compilation_date_time(void)
{
    int retv;
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
#if defined(__DATE__) && defined(__TIME__)
    retv = ceu_snprintf(buff, 256, "%s, %s", __DATE__, __TIME__);
#elif defined(__DATE__)
    retv = ceu_snprintf(buff, 256, "%s, unknown time", __DATE__);
#else
    retv = ceu_snprintf(buff, 256, "unknown date & time");
#endif
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}

char* ceu_check_get_compiler_info(void)
{
    char* compiler_version_buff;
    char* buff = (char*)ceu_scalloc(1024, sizeof(char));
    int retv;
    char* date_time_buff = ceu_check_interpret_compilation_date_time();
    if (date_time_buff == NULL) {
        return NULL;
    }
    compiler_version_buff = interpret_compiler_version_number();
    if (compiler_version_buff == NULL) {
        ceu_free_non_null(date_time_buff);
        return NULL;
    }

    retv = ceu_snprintf(buff, 1024, "Compiled at %s with compiler '%s'\n\t%s", date_time_buff, CEU_COMPILER_NAME,
        compiler_version_buff);
    ceu_free_non_null(date_time_buff);
    ceu_free_non_null(compiler_version_buff);
    if (retv < 0) {
        return NULL;
    }
    return buff;
}

#if defined(CEU_COMPILER_IS_ICC)
char* interpret_icc_compiler_version_number()
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
#ifdef __INTEL_COMPILER_UPDATE
    retv = ceu_snprintf(buff, 256, "ICC compatible version number: %d.%d", __ICC, __INTEL_COMPILER_UPDATE);
#else
    retv = ceu_snprintf(buff, 256, "ICC compatible version number: %d", __ICC);
#endif
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else

char* interpret_icc_compiler_version_number(void)
{
    return NULL;
}

#endif
#if defined(CEU_COMPILER_IS_MSVC)
char* interpret_msvc_compiler_version_number(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
    int msv_major_version = CEU_COMPILER_VERSION / 100;
    int msc_minor_version = CEU_COMPILER_VERSION % 100;
#ifdef _MSC_FULL_VER
    retv = ceu_snprintf(buff, 256,
        "MSVC compatible version number: %d.%d\n\t\twith "
        "Visual Studio ver. %s (_MSC_VER=%d, _MSC_FULL_VER=%d)",
        msv_major_version, msc_minor_version, VISUAL_STUDIO_VER, _MSC_VER, _MSC_FULL_VER);
#else
    retv = ceu_snprintf(buff, 256,
        "MSVC compatible version number: %d.%d\n\t\twith Visual "
        "Studio ver. %s (_MSC_VER=%d, _MSC_FULL_VER=UNKNOWN)",
        msv_major_version, msc_minor_version, VISUAL_STUDIO_VER, _MSC_VER);
#endif
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else

char* interpret_msvc_compiler_version_number(void)
{
    return NULL;
}

#endif
#if defined(CEU_COMPILER_IS_NVHPC)
char* interpret_nvhpc_compiler_version_number()
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
    retv = ceu_snprintf(buff, 256, "NVHPC compatible version number: %d.%d.%d", __NVCOMPILER_MAJOR__,
        __NVCOMPILER_MINOR__, __NVCOMPILER_PATCHLEVEL__);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else

char* interpret_nvhpc_compiler_version_number(void)
{
    return NULL;
}

#endif
#if defined(CEU_COMPILER_IS_TINYCC)
char* interpret_tcc_compiler_version_number(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
    int major = __TINYC__ / 10000;
    int minor = (__TINYC__ - major * 10000) / 100;
    int patchlevel = __TINYC__ % 100;
    retv = ceu_snprintf(buff, 256, "TCC compatible version number: %d.%d.%d", major, minor, patchlevel);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else

char* interpret_tcc_compiler_version_number(void)
{
    return NULL;
}

#endif

#if defined(CEU_COMPILER_IS_BORLAND)
char* interpret_broadland_compiler_version_number(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
    int major = __BORLANDC__ / 256;
    int revision = (__BORLANDC__ - 256 * major) / 16 + __BORLANDC__ % 16;
    retv = ceu_snprintf(buff, 256, "Broadland compatible version number: %d.%d", major, revision);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}
#else

char* interpret_broadland_compiler_version_number(void)
{
    return NULL;
}

#endif
#if defined(CEU_COMPILER_IS_CLANG)

char* interpret_clang_compiler_version_number(void)
{
    int retv;
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
#ifdef __clang_major__
    retv = ceu_snprintf(buff, 256, "Clang compatible version number: %d.%d.%d", __clang_major__, __clang_minor__,
        __clang_patchlevel__);
#else
    retv = ceu_snprintf(buff, 256, "Clang compatible version number: unknown");
#endif
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}

#else

char* interpret_clang_compiler_version_number(void)
{
    return NULL;
}

#endif
#if defined(CEU_COMPILER_IS_GCC)

char* interpret_gcc_compiler_version_number(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
#ifdef __GNUC_PATCHLEVEL__
    retv = ceu_snprintf(buff, 256, "GCC compatible version number: %d.%d.%d", __GNUC__, __GNUC_MINOR__,
        __GNUC_PATCHLEVEL__);
#else
    retv = ceu_snprintf(buff, 256, "%d.%d", __GNUC__, __GNUC_MINOR__);
#endif
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}

#else

char* interpret_gcc_compiler_version_number(void)
{
    return NULL;
}

#endif

#if defined(__VERSION__)

char* interpret_compiler_macro_version_number(void)
{
    char* buff = (char*)ceu_scalloc(256, sizeof(char));
    int retv;
    retv = ceu_snprintf(buff, 256, "__VERSION__ version number: %s", __VERSION__);
    if (retv < 0) {
        ceu_free_non_null(buff);
        return NULL;
    }
    return buff;
}

#else

char* interpret_compiler_macro_version_number(void)
{
    return NULL;
}

#endif

char* interpret_compiler_version_number(void)
{
    char* tcc_comp_version = interpret_tcc_compiler_version_number();
    char* gcc_comp_version = interpret_gcc_compiler_version_number();
    char* icc_comp_version = interpret_icc_compiler_version_number();
    char* clang_comp_version = interpret_clang_compiler_version_number();
    char* msvc_comp_version = interpret_msvc_compiler_version_number();
    char* nvhpc_comp_version = interpret_nvhpc_compiler_version_number();
    char* broadland_comp_version = interpret_broadland_compiler_version_number();
    char* version_macro_version = interpret_compiler_macro_version_number();
    char* final_buff = ceu_str_join_with_sep("\n\t", CEU_STR_JOIN_SKIP, 8, tcc_comp_version, gcc_comp_version,
        icc_comp_version, clang_comp_version, msvc_comp_version,
        nvhpc_comp_version, broadland_comp_version, version_macro_version);
    ceu_free_non_null(tcc_comp_version);
    ceu_free_non_null(gcc_comp_version);
    ceu_free_non_null(icc_comp_version);
    ceu_free_non_null(clang_comp_version);
    ceu_free_non_null(msvc_comp_version);
    ceu_free_non_null(nvhpc_comp_version);
    ceu_free_non_null(broadland_comp_version);
    ceu_free_non_null(version_macro_version);
    return final_buff;
}

#ifdef __cplusplus
}
#endif
