#ifndef CEU_STDBOOL_H
#define CEU_STDBOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_basic/libceu_stddef.h"

#if CEU_HAVE_INCLUDE_STDBOOL_H == 1

#include <stdbool.h>

#else
#ifndef _STDBOOL
#define _STDBOOL

#ifndef __bool_true_false_are_defined

#define __bool_true_false_are_defined 1

#if (CEU_CM_HAVE_WORKING_C__BOOL_RUN_STATIC * CEU_CM_HAVE_WORKING_C__BOOL_RUN_SHARED == 0)
#define bool _Bool
#else
#define bool int
#endif

#define false 0
#define true 1
#endif // !__bool_true_false_are_defined

#endif /* _STDBOOL */
#endif

#ifdef __cplusplus
}
#endif

#endif
