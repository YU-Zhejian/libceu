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
 * @see [GCC definition](https://gcc.gnu.org/onlinedocs/gcc/Attribute-Syntax.html).
 */

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

// Default to NOP
#ifndef CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC
#define CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC 127
#endif
#ifndef CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED
#define CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED 127
#endif

#if (CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED * CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC == 0)
#else
#define __attribute__(x) // NOLINT
#endif
