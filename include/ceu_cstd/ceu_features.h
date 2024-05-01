/**
 * @file ceu_features.h
 * @author YU Zhejian
 * @brief Defines "inline" macro. Will do nothing if inline macro or keyword had already been defined.
 * @version 0.1
 * @date 2024-04-28
 * 
 * @todo Check whether inline works. Also check for behaviour under C++.
 */

#ifndef CEU_FEATURES_H
#define CEU_FEATURES_H

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

// Following codes are from musl
#if (CEU_CM_HAVE_WORKING_C_INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C_INLINE_RUN_SHARED == 0)
// Normal condition where inline is supported
#elif (CEU_CM_HAVE_WORKING_C___INLINE_RUN_STATIC * CEU_CM_HAVE_WORKING_C___INLINE_RUN_SHARED == 0)
// Condition where __inline is supported
#define inline __inline
#elif (CEU_CM_HAVE_WORKING_C___INLINE___RUN_STATIC * CEU_CM_HAVE_WORKING_C___INLINE___RUN_SHARED == 0)
// Condition where __inline__ is supported
#define inline __inline__
#else
// Define inline as empty
#define inline
#endif
#endif
