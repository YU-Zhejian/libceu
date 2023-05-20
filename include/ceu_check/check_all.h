//
// Created by yuzj on 1/15/22.
//

#ifdef __cplusplus
extern "C" {
#endif


#include <string.h>
#include <stdlib.h> // extern char * *environ
#include "ceu_check/check_os.h"
#include "ceu_check/check_cc.h"

#ifdef __cplusplus
#include "ceu_check/check_cxx_std.hpp"
#else
#include "ceu_check/check_c_std.h"
#endif

#include "ceu_check/ceu_append_sprintf.h"
#include "ceu_check/check_resource_limit.h"

#ifndef CPPTETGS_EXPERIMENTAL_UTILS_H
#define CPPTETGS_EXPERIMENTAL_UTILS_H

static inline void get_full_info(char *buff)
{
    get_compiler_info(buff);
#ifdef __cplusplus
    get_cxx_info(buff);
#else
    get_c_info(buff);
#endif
    get_os_info(buff);
    get_runtime_os_info(buff);
    get_rlimit_info(buff);
    get_runtime_posix_sysconf_limit_info(buff);
    get_compiletime_posix_standard(buff);
    get_ctypes_limit_info(buff);
    append_sprintf(buff, "%s\n", buff);
}

#ifdef __cplusplus
}
#endif
#endif //CPPTETGS_EXPERIMENTAL_UTILS_H
