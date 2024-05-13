/*!
 * @file ceu_stdint.h
 * @brief A simple stdint.h implementation.
 *
 * @todo Needs to further test on different 32- and 64-bit, LE and BE platforms.
 */

#ifndef CEU_STDINT_H
#define CEU_STDINT_H

// Begin doxygen stub.
#ifdef CEU_UNDER_DOXYGEN

/*!
 * @typedef ceu_int8_t
 * @brief Signed integer that is of 8 byte length.
 */
typedef /* inplementation-defined */ ceu_int8_t;

/*!
 * @typedef ceu_int16_t
 * @brief Signed integer that is of 16 byte length.
 */
typedef /* inplementation-defined */ ceu_int16_t;

/*!
 * @typedef ceu_int32_t
 * @brief Signed integer that is of 32 byte length.
 */
typedef /* inplementation-defined */ ceu_int32_t;

/*!
 * @typedef ceu_int64_t
 * @brief Signed integer that is of 64 byte length.
 */
typedef /* inplementation-defined */ ceu_int64_t;
#else

#include <ceu_basic/libceu_stddef_dispatcher.h>
#include <limits.h>

// clang-format off
#include <ceu_check/ceu_check_cc_macro.h>

// Before performing any operation,
// we would check whether the environment satisfies C minumun standards.

#include <ceu_cstd/ceu_stdint/c_minimum_std.h> // NOLINT

// Now we define basic sizes that is always constant.
#include <ceu_cstd/ceu_stdint/c_basic_sizes.h> // NOLINT

#include <ceu_cstd/ceu_stdint/stdint_gcc_maxmin.h> // NOLINT
#include <ceu_cstd/ceu_stdint/stdint_msvc_maxmin.h> // NOLINT
#include <ceu_cstd/ceu_stdint/stdint_failsafe_maxmin.h> // NOLINT

#include <ceu_cstd/ceu_stdint/stdint_gcc_typedef.h> // NOLINT
#include <ceu_cstd/ceu_stdint/stdint_failsafe_typedef.h> // NOLINT

#include <ceu_cstd/ceu_stdint/stdint_printf_conversion.h> // NOLINT
// clang-format on
#endif

#endif // CEU_STDINT_H
