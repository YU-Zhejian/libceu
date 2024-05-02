/*!
 * @file ceu_cdefs.h
 * @author YU Zhejian
 * @brief Defines some macros, see below for details.
 * @version 0.1
 * @date 2024-04-28
 */

/*!
 * @def __attribute__
 * @brief Defines GNU-compatuble __attribute__ macro for platforms that does not provide this macro to empty.
 */

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

#if (CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC * CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC == 0)
#else
// Define GNU-compatuble __attribute__ macro.
#define __attribute__(x) // NOLINT
#endif
