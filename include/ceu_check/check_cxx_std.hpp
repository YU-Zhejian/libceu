//
// Created by yuzj on 1/15/22.
//

#include "ceu_check/ceu_append_sprintf.h"

#ifndef CEU_CHECK_CXX_STD_H
#define CEU_CHECK_CXX_STD_H


#if defined(_MSVC_LANG)
#define CEU_CXX_STD_VERSION_MACRO _MSVC_LANG
#elif defined(__cplusplus)
#define CEU_CXX_STD_VERSION_MACRO __cplusplus
#else
#define CEU_CXX_STD_VERSION_MACRO -2
#endif

#define CEU_CXX_STD_LATEST 23

#if CEU_CXX_STD_VERSION_MACRO != -2

#if CEU_CXX_STD_VERSION_MACRO == 1 or CEU_CXX_STD_VERSION_MACRO < 199711L
#define CEU_CXX_STD 0
#elif CEU_CXX_STD_VERSION_MACRO >= 202100L
#define CEU_CXX_STD 23
#elif CEU_CXX_STD_VERSION_MACRO >= 202002L
#define CEU_CXX_STD 20
#elif CEU_CXX_STD_VERSION_MACRO >= 201703L
#define CEU_CXX_STD 17
#elif CEU_CXX_STD_VERSION_MACRO >= 201402L
#define CEU_CXX_STD 14
#elif CEU_CXX_STD_VERSION_MACRO >= 201103L
#define CEU_CXX_STD 11
#elif CEU_CXX_STD_VERSION_MACRO >= 199711L
#define CEU_CXX_STD 98
#else
#define CEU_CXX_STD -1
#endif

#else
#define CEU_CXX_STD -2
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get compile-time C++ standard version number.
 */
static inline void interpret_cxx_version(char *buff)
{
    if (CEU_CXX_STD == 0) {
        append_sprintf(buff, "%sbefore 98 (%ld)", buff, CEU_CXX_STD_VERSION_MACRO);
    }
    else if (CEU_CXX_STD == -1) {
        append_sprintf(buff, "%sunknown (%ld)", buff, CEU_CXX_STD_LATEST, CEU_CXX_STD_VERSION_MACRO);
    }
    else if (CEU_CXX_STD == -2) {
        append_sprintf(buff, "%sunknown (_MSVC_LANG and __cplusplus undefined)", buff);
    }
    else {
        append_sprintf(buff, "%s%d (%ld)", buff, CEU_CXX_STD, CEU_CXX_STD_VERSION_MACRO);
    }
}

/**
 * Get a nicely formatted compile-time C++ standard version number.
 */
static inline void get_cxx_info(char *buff)
{
    append_sprintf(buff, "%sCompile-time C++ std.: ver. ", buff);
    interpret_cxx_version(buff);
    append_sprintf(buff, "%s\n", buff);
}


#ifdef __cplusplus
}
#endif
#endif //CEU_CHECK_CXX_STD_H
