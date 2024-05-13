/*!
 * @file ceu_stdint.h
 * @brief A simple stdint.h implementation.
 *
 * @todo Needs to further test on different 32- and 64-bit, LE and BE platforms.
 */

/*!
 * @typedef ceu_int8_t
 * @brief Signed integer that is of 8 byte length.
 */

#ifndef CEU_STDINT_H
#define CEU_STDINT_H

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif
#include <limits.h>



#include <ceu_check/ceu_check_cc_macro.h>

// Before performing any operation,
// we would check whether the environment satisfies C minumun standards.

#include <ceu_cstd/ceu_stdint/c_minimum_std.h>

// Now we define basic sizes that is always constant.
#include <ceu_cstd/ceu_stdint/c_basic_sizes.h>

#include <ceu_cstd/ceu_stdint/stdint_failsafe_maxmin.h>
#include <ceu_cstd/ceu_stdint/stdint_gcc_maxmin.h>
#include <ceu_cstd/ceu_stdint/stdint_msvc_maxmin.h>

#include <ceu_cstd/ceu_stdint/stdint_gcc_typedef.h>
#include <ceu_cstd/ceu_stdint/stdint_failsafe_typedef.h>

#include <ceu_cstd/ceu_stdint/stdint_printf_conversion.h>

#endif // CEU_STDINT_H
