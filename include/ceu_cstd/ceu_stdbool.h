/**
 * @file ceu_stdbool.h
 * @author your name (you@domain.com)
 * @brief Compatible file of <stdbool.h>, providing definition of bool, true, false macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 * 
 * This file will be supressed under C++.
 */
#ifndef CEU_STDBOOL_H
#define CEU_STDBOOL_H
// Supress definition of bool under C++.
#ifndef __cplusplus

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

#if (CEU_HAVE_INCLUDE_STDBOOL_H == 1 && CEU_CM_HAVE_WORKING_C_BOOL_RUN_STATIC * CEU_CM_HAVE_WORKING_C_BOOL_RUN_SHARED == 0)
// Normal condition where stdbool.h is available and compatible
#include <stdbool.h>

#else
// Define our own stdbool.h
#ifndef _STDBOOL
#define _STDBOOL

#ifndef __bool_true_false_are_defined

#define __bool_true_false_are_defined 1

#if (CEU_CM_HAVE_WORKING_C__BOOL_RUN_STATIC * CEU_CM_HAVE_WORKING_C__BOOL_RUN_SHARED == 0)
// If _Bool is available.
#define bool _Bool
// Fallback to int.
#else
#define bool int
#endif

#define false 0
#define true 1
#endif // !__bool_true_false_are_defined

#endif /* _STDBOOL */
#endif
#endif /* __cplusplus */
#endif
