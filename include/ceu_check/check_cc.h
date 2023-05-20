/**
 * @brief Header to get compiler information at compile time
 *
 * @details This header may detect information of C or C++ compilers.
 *
 * Usepackage https://sourceforge.net/p/predef/wiki/Architectures/
 */
#include <stdbool.h>
//#include "ceu_check/ceu_append_sprintf.h"

#ifndef CEU_CHECK_CC_H
#define CEU_CHECK_CC_H

/*
 * NVidia HPC (NVHPC) Toolkit NVC++
 */
#if defined(__NVCOMPILER_MAJOR__) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_NVHPC
#define CEU_COMPILER_VERSION __NVCOMPILER_MAJOR__*10000+__NVCOMPILER_MINOR__*100+__NVCOMPILER_PATCHLEVEL__
#define CEU_COMPILER_NAME "NVidia High Performance Computing (NVHPC) Toolkit NVC++"
#endif

#if defined(__TINYC__)
#define CEU_COMPILER_IS_TINYCC
#define CEU_COMPILER_VERSION __TINYC__
#define CEU_COMPILER_NAME "Tiny C Compiler"
#endif

// TODO: __PGIC__

/*
 * Borland C/C++
 *
 * Version: 0xVRR : V = Version, RR = Revision
 *
 * Example: 0x551 = Borland C++ 5.51
 * 
 * See: <https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Compiler_Versions>
 */
#if defined(__BORLANDC__) || defined(__CODEGEARC__) || defined(__BCPLUSPLUS__) || defined(__TCPLUSPLUS__) || defined(__TURBOC__) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_BORLAND
#define CEU_COMPILER_VERSION __BORLANDC__
#if defined(__clang__)
#define CEU_COMPILER_NAME "Borland"
#else
#define CEU_COMPILER_NAME "Borland with Clang support"
#endif
#endif


/**
 * Old Intel C/C++ compiler called ICC/ICPC
 */
#if defined(__ICC) || defined(__INTEL_COMPILER) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_ICC
#ifdef __llvm__
#define CEU_COMPILER_NAME "ICC"
#else
#define CEU_COMPILER_NAME "ICC with LLVM features"
#endif
#ifdef __INTEL_COMPILER_UPDATE
#define CEU_COMPILER_VERSION __ICC * 100 + __INTEL_COMPILER_UPDATE
#else
#define CEU_COMPILER_VERSION __ICC * 100 + __INTEL_COMPILER_UPDATE
#endif
#endif

/**
 * Microsoft MSVC. That is, what is bundled in Visual Studio.
 */
#if defined(_MSC_VER) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_MSVC
#define CEU_COMPILER_NAME "MSVC"
#define CEU_COMPILER_VERSION _MSC_VER
#endif

/*
 * Original LLVM Clang
 */
#if (defined(__clang__) || defined(__llvm__)) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_CLANG
#if defined(__INTEL_CLANG_COMPILER) || defined(__INTEL_LLVM_COMPILER)
#define CEU_COMPILER_NAME "Intel Clang"
#else
#define CEU_COMPILER_NAME "Clang"
#endif
#ifdef __clang_major__
#define CEU_COMPILER_VERSION __clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__
#endif
#endif


/*
 * GNU GCC and G++
 */
#if defined(__GNUC__) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_GCC
#define CEU_COMPILER_NAME "GCC"
#ifndef __GNUC_PATCHLEVEL__
#define __GNUC_PATCHLEVEL__ 0
#endif
#define CEU_COMPILER_VERSION __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__
#endif


/**
 * For unknown ones
 */
#ifndef CEU_COMPILER_NAME
#define CEU_COMPILER_NAME "unknown"
#define CEU_COMPILER_IS_UNKNOWN
#endif
#ifndef CEU_COMPILER_VERSION
#define CEU_COMPILER_VERSION -1
#endif

#if defined(CEU_COMPILER_IS_MSVC)
/**
 * Format MSVC version description and append it to buffer.
 */
inline void print_msvc_ver(char* buff, const char* vs_ver, int msc_ver_macro) {
    int msv_major_version = msc_ver_macro / 100;
    int msc_minor_version = msc_ver_macro % 100;
    append_sprintf(buff, "%s ver. %d.%d, with Visual Studio ver. %s", buff, msv_major_version, msc_minor_version, vs_ver);
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get a string describing compiler version.
 *
 * @param buff Buffer to append
 */
static inline void interpret_compiler_version_number(char *buff)
{

#if defined(CEU_COMPILER_IS_TCC)
    int major = __TCC__//10000;
    int minor = (__TCC__ - major * 10000) // 100;
    int patchlevel = __TCC__ % 100;
    append_sprintf(buff, "%s ver. %d.%d.%d", buff, major, minor, patchlevel);
#elif defined(CEU_COMPILER_IS_NVHPC)
    append_sprintf(buff, "%s ver. %d.%d.%d", buff, __NVCOMPILER_MAJOR__, __NVCOMPILER_MINOR__, __NVCOMPILER_PATCHLEVEL__);
#elif defined(CEU_COMPILER_IS_BORLAND)
    int major = __BORLANDC__ / 256;
    int revision = (__BORLANDC__ - 256 * major) / 16 + __BORLANDC__ % 16;
    append_sprintf(buff, "%s ver. %d.%d", buff, major, revision);
#elif defined(CEU_COMPILER_IS_ICC)
#ifdef __INTEL_COMPILER_UPDATE
    append_sprintf(buff, "%s ver. %d.%d", buff, __ICC, __INTEL_COMPILER_UPDATE);
#else
    append_sprintf(buff, "%s ver. %d", buff, __ICC);
#endif
#elif defined(CEU_COMPILER_IS_GCC)
    append_sprintf(buff, "%s ver. %d.%d.%d", buff, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(CEU_COMPILER_IS_MSVC)
    switch (_MSC_VER) {
    case 800:
        print_msvc_ver(buff, "1", _MSC_VER);
        break;
    case 900:
        print_msvc_ver(buff, "3", _MSC_VER);
        break;
    case 1000:
        print_msvc_ver(buff, "4", _MSC_VER);
        break;
    case 1100:
        print_msvc_ver(buff, "5", _MSC_VER);
        break;
    case 1200:
        print_msvc_ver(buff, "6", _MSC_VER);
        break;
    case 1300:
        print_msvc_ver(buff, "7", _MSC_VER);
        break;
    case 1310:
        print_msvc_ver(buff, "7.1 (2003)", _MSC_VER);
        break;
    case 1400:
        print_msvc_ver(buff, "8 (2005)", _MSC_VER);
        break;
    case 1500:
        print_msvc_ver(buff, "9 (2008)", _MSC_VER);
        break;
    case 1600:
        print_msvc_ver(buff, "10 (2010)", _MSC_VER);
        break;
    case 1700:
        print_msvc_ver(buff, "11 (2012)", _MSC_VER);
        break;
    case 1800:
        print_msvc_ver(buff, "12 (2013)", _MSC_VER);
        break;
    case 1900:
        print_msvc_ver(buff, "14 (2015)", _MSC_VER);
        break;
    case 1910:
        print_msvc_ver(buff, "15 (2017 Update 1 & 2)", _MSC_VER);
        break;
    case 1911:
        print_msvc_ver(buff, "15 (2017 Update 3 & 4)", _MSC_VER);
        break;
    case 1912:
        print_msvc_ver(buff, "15 (2017 Update 5)", _MSC_VER);
        break;
    case 1913:
        print_msvc_ver(buff, "15 (2017 Update 6)", _MSC_VER);
        break;
    case 1914:
        print_msvc_ver(buff, "15 (2017 Update 7)", _MSC_VER);
        break;
    case 1915:
        print_msvc_ver(buff, "15 (2017 Update 8)", _MSC_VER);
        break;
    case 1916:
        print_msvc_ver(buff, "15 (2017 Update 9)", _MSC_VER);
        break;
    case 1920:
        print_msvc_ver(buff, "16 (2019 RTW)", _MSC_VER);
        break;
    case 1921:
        print_msvc_ver(buff, "16 (2019 Update 1)", _MSC_VER);
        break;
    case 1922:
        print_msvc_ver(buff, "16 (2019 Update 2)", _MSC_VER);
        break;
    case 1923:
        print_msvc_ver(buff, "16 (2019 Update 3)", _MSC_VER);
        break;
    case 1924:
        print_msvc_ver(buff, "16 (2019 Update 4)", _MSC_VER);
        break;
    case 1925:
        print_msvc_ver(buff, "16 (2019 Update 5)", _MSC_VER);
        break;
    case 1926:
        print_msvc_ver(buff, "16 (2019 Update 6)", _MSC_VER);
        break;
    case 1927:
        print_msvc_ver(buff, "16 (2019 Update 7)", _MSC_VER);
        break;
    case 1928:
        print_msvc_ver(buff, "16 (2019 Update 8 & 9)", _MSC_VER);
        break;
    case 1929:
        print_msvc_ver(buff, "16 (2019 Update 10 & 11)", _MSC_VER);
        break;
    case 1930:
        print_msvc_ver(buff, "17 (2022 RTW)", _MSC_VER);
        break;
    default:
        if (_MSC_VER > 1930){
            append_sprintf(buff, "%s ver. unknown, but larger than 19.30 (Visual Studio 17 aka. 2022 RTW)", buff);
        }
        else if (_MSC_VER < 800){
            append_sprintf(buff, "%s ver. unknown, but smaller than 8.0 (Visual Studio 1)", buff);
        } else {
            append_sprintf(buff, "%s ver. unknown", buff);
        }
    }
#ifdef _MSC_FULL_VER
    append_sprintf(buff, "%s (_MSC_VER=%d, _MSC_FULL_VER=%d)", buff, _MSC_VER, _MSC_FULL_VER);
#else
    append_sprintf(buff, "%s (_MSC_VER=%d, _MSC_FULL_VER=UNKNOWN)", buff, _MSC_VER);
#endif // _MSC_FULL_VER

#elif defined(CEU_COMPILER_IS_CLANG)

    append_sprintf(buff, "%s ver. %d.%d.%d", buff, __clang_major__, __clang_minor__, __clang_patchlevel__);

#else
    append_sprintf(buff, "%s ver. %s", buff, CEU_COMPILER_VERSION);
#endif

#ifdef __VERSION__
    append_sprintf(buff, "%s (__VERSION__=%s)", buff, __VERSION__);
#else
    append_sprintf(buff, "%s (__VERSION__=UNDEFINED)", buff);
#endif
}

/**
 * Check whether compiler have version greater or equal than given.
 *
 * @param major The first digit of corresponding version number.
 * @param minor The second digit of corresponding version number.
 * @param patchlevel The third digit of corresponding version number.
 * Not used when CEU_COMPILER_IS_MSVC, CEU_COMPILER_IS_BORLAND and CEU_COMPILER_IS_ICC.
 */
static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
#if defined(CEU_COMPILER_IS_TCC)
    return major * 10000 + minor * 100 + patchlevel >= __TCC__;
#elif defined(CEU_COMPILER_IS_NVHPC)
    return __NVCOMPILER_MAJOR__ >= major && __NVCOMPILER_MINOR__ >= minor && __NVCOMPILER_PATCHLEVEL__ >= patchlevel;
#elif defined(CEU_COMPILER_IS_BORLAND)
    return CEU_COMPILER_VERSION >= major * 256 + minor / 10 * 16 + minor % 10;
#elif defined(CEU_COMPILER_IS_ICC)
    return CEU_COMPILER_VERSION >= major * 100 + minor;
#elif defined(CEU_COMPILER_IS_GCC)
    return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
#elif defined(CEU_COMPILER_IS_MSVC)
    return _MSC_VER >= major;
#elif defined(CEU_COMPILER_IS_CLANG)
    return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
#else
    return true;
#endif
}

/**
 * Get compiling date & time, and append them to buffer.
 */
static inline void interpret_compilation_date_time(char *buff)
{
#if defined(__DATE__) && defined(__TIME__)
    append_sprintf(buff, "%sCompiled at %s, %s", buff, __DATE__, __TIME__);
#elif defined(__DATE__)
    append_sprintf(buff, "%sCompiled at %s with unknown time", buff, __DATE__);
#else
    append_sprintf(buff, "%sCompiled at unknown date or time", buff);
#endif
}

/**
 * Get a nicely formatted compiler information and append it to a buffer.
 */
static inline void get_compiler_info(char *buff)
{
    interpret_compilation_date_time(buff);
    append_sprintf(buff, "%s with compiler %s", buff, CEU_COMPILER_NAME);
    interpret_compiler_version_number(buff);
    append_sprintf(buff, "%s\n", buff);
}

#ifdef __cplusplus
}
#endif

#endif //CEU_CHECK_CC_H
