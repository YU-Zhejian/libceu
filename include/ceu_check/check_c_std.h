/*!
 * @brief Get compile-time C standard.
 */
#include "ceu_check/ceu_append_sprintf.h"

#ifndef CEU_CHECK_C_STD_H
#define CEU_CHECK_C_STD_H

#define CEU_C_STD_LATEST 17

#ifndef __cplusplus

#ifndef __STDC_VERSION__
#define CEU_C_STD 0
#elif __STDC_VERSION__ == 199409L
#define CEU_C_STD 94
#elif __STDC_VERSION__ == 199901L
#define CEU_C_STD 99
#elif __STDC_VERSION__ == 201112L
#define CEU_C_STD 11
#elif __STDC_VERSION__ == 201710L
#define CEU_C_STD 17
#else
#define CEU_C_STD -1
#endif
#else
#define CEU_C_STD -2
#endif

/**
 * Get compile-time C standard version number.
 */
static inline void interpret_c_version(char *buff)
{
    if (CEU_C_STD == 0) {
        append_sprintf(buff, "%sunknown before 94", buff);
    }
    else if (CEU_C_STD == -1) {
        append_sprintf(buff, "%sunknown after %d", buff, CEU_C_STD_LATEST);
    }
    else if (CEU_C_STD == -2) {
        append_sprintf(buff, "%scompiler is C++ compiler", buff);
    }
    else {
        append_sprintf(buff, "%s%d", buff, CEU_C_STD);
    }
}

/**
 * Get a nicely formatted compile-time C standard version number.
 */
static inline void get_c_info(char *buff)
{
    append_sprintf(buff, "%sCompile-time C std.: ver. ", buff);
    interpret_c_version(buff);
    append_sprintf(buff, "%s\n", buff);
}


#endif //CEU_CHECK_C_STD_H
