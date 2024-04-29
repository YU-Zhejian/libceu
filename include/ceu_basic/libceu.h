#ifndef LIBCEU_CEU_H
#define LIBCEU_CEU_H
#define CEU_LIB_CTIME_VERSION "0.1"

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

char* ceu_lib_rtime_version(void);

#ifdef __cplusplus
}
#endif
#endif // LIBCEU_CEU_H
