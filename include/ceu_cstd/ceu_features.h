#ifndef CEU_FEATURES_H
#define CEU_FEATURES_H

#include "ceu_cstd/ceu_cdefs.h"
#include "libceu_stddef.h"

// Following codes are from musl

#if (CEU_CM_HAVE_WORKING_C_INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C_INLINE_RUN_SHARED == 0)
#if (CEU_CM_HAVE_WORKING_C___INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C___INLINE_RUN_SHARED == 0)
// Normal condition where inline and __inline is supported
#else
// Have inline but not __inline
#define __inline inline
#endif
#else // No inline. Check for __inline
#if (CEU_CM_HAVE_WORKING_C___INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C___INLINE_RUN_SHARED == 0)
#define inline __inline
#else
#error "Either __inline or inline should be defined!"
#endif
#endif

#if (CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC == 0)
// Normal condition where _Noreturn is supported
#else
#define _Noreturn __attribute__((__noreturn__))
#endif
#endif
