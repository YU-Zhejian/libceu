#ifndef LIBCEU_CEU_H
#define LIBCEU_CEU_H
#ifdef __cplusplus
extern "C" {
#endif
#define CEU_LIB_CTIME_VERSION "0.1"

#include "libceu_stddef.h"

// Require safe strting functions
#ifndef __STDC_WANT_LIB_EXT1__
#define __STDC_WANT_LIB_EXT1__ 1 // NOLINT
#endif

#if CEU_HAVE_SNPRINTF == 0
#if CEU_HAVE__SNPRINTF == 0

#error "Either _snprintf or snprintf should be defined!"
#else

#define snprintf _snprintf // MS Idiot.
#endif // !_snprintf
#endif // snprintf

char* ceu_lib_rtime_version(void);

#ifdef __cplusplus
}
#endif
#endif // LIBCEU_CEU_H
