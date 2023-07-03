//
// Created by yuzj on 6/20/23.
//

#ifndef LIBCEU_CEU_H
#define LIBCEU_CEU_H
#define CEU_LIB_CTIME_VERSION "0.1"
#include "libceu_stddef.h"

#if (CEU_CM_HAVE_WORKING_C_INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C_INLINE_RUN_SHARED == 0)
// Normal condition where inline is supported
#else
// No inline. Check for __inline
#if (CEU_CM_HAVE_WORKING_C___INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C___INLINE_RUN_SHARED == 0)
#define inline __inline // MS Idiot.
#else
#error "Either __inline or inline should be defined!"
#endif
#endif

#if CEU_HAVE_SNPRINTF == 0
#if CEU_HAVE__SNPRINTF == 0

#error "Either _snprintf or snprintf should be defined!"
#else

#define snprintf _snprintf // MS Idiot.
#endif // !_snprintf
#endif // snprintf


char* ceu_lib_rtime_version(void);

#endif //LIBCEU_CEU_H
