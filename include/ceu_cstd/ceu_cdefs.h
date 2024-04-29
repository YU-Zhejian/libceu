/**
 * @file ceu_cdefs.h
 * @author YU Zhejian
 * @brief Defines GNU-compatuble __attribute__ macro.
 * @version 0.1
 * @date 2024-04-28
 *
 */

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

#if (CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC * CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC == 0)
#else
// Define GNU-compatuble __attribute__ macro.
#define __attribute__(x)
#endif
