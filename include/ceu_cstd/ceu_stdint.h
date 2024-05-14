/*!
 * @file ceu_stdint.h
 * @brief A simple stdint.h implementation.
 *
 * @todo Needs to further test on different 32- and 64-bit, LE and BE platforms.
 *
 * The content of the file is as follows:
 *
 * 1. Check whether Satisfies Minimum C Standard. They are:
 *   - `char`, `short`, `integer`, `long` and `long long` are defined.
 *   - For types in `char`, `short`, `integer`, `long` and `long long`, size of the former is not smaller than the latter.
 *   - Check for basic size limitations: `1 <= sizeof(char)`; `2 <= sizeof(short)`; `2 <= sizeof(int)`; `4 <= sizeof(long)`; `8 <= sizeof(long long)`.
 * 2. Define sizes of `ceu_intN_t` and `ceu_uintN_t`, namely #CEU_INT8_SIZE, #CEU_INT16_SIZE, #CEU_INT32_SIZE and #CEU_INT64_SIZE.
 * 3. Define maximum and minimum of the types, on following basis:
 *   - If GCC-specific size macros like `__INT16_MAX__` were detected, will use them directly.
 *   - If MSVC-specific size macros like `_I8_MIN` were defined, will use them directly.
 *   - If non of above is satisfied, will define them using literals.
 *
 * @see https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html for GCC specific macros that generates stdint.h.
 * @see https://learn.microsoft.com/en-us/cpp/c-runtime-library/data-type-constants for MSVC specific macros that generates stdint.h.
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

/*!
 * @typedef ceu_uint8_t
 * @brief Unsigned integer that is of 8 byte length.
 */
typedef /* inplementation-defined */ ceu_uint8_t;

/*!
 * @typedef ceu_uint16_t
 * @brief Unsigned integer that is of 16 byte length.
 */
typedef /* inplementation-defined */ ceu_uint16_t;

/*!
 * @typedef ceu_uint32_t
 * @brief Unsigned integer that is of 32 byte length.
 */
typedef /* inplementation-defined */ ceu_uint32_t;

/*!
 * @typedef ceu_uint64_t
 * @brief Unsigned integer that is of 64 byte length.
 */
typedef /* inplementation-defined */ ceu_uint64_t;

/*!
 * @def CEU_INT8_SIZE
 * @brief Size of `int8_t` or `uint8_t`.
 */
#define CEU_INT8_SIZE 1

/*!
 * @def CEU_INT16_SIZE
 * @brief Size of `int16_t` or `uint16_t`.
 */
#define CEU_INT16_SIZE 2

/*!
 * @def CEU_INT32_SIZE
 * @brief Size of `int32_t` or `uint32_t`..
 */
#define CEU_INT32_SIZE 4

/*!
 * @def CEU_INT64_SIZE
 * @brief Size of `int64_t` or `uint64_t`.
 */
#define CEU_INT64_SIZE 8

/*!
 * @def INT8_MIN
 * @brief A literal representing minimum of #ceu_int8_t, should be equal to -128.
 */
#define INT8_MIN /* implementation-defined */

/*!
 * @def INT8_MAX
 * @brief A literal representing maximum of #ceu_int8_t, should be equal to 127.
 */
#define INT8_MAX /* implementation-defined */

/*!
 * @def UINT8_MAX
 * @brief A literal representing maximum of #ceu_uint8_t, should be equal to 255.
 */
#define UINT8_MAX /* implementation-defined */

/*!
 * @def INT16_MIN
 * @brief A literal representing minimum of #ceu_int16_t, should be equal to -32,768.
 */
#define INT16_MIN /* implementation-defined */

/*!
 * @def INT16_MAX
 * @brief A literal representing maximum of #ceu_int16_t, should be equal to 32,767.
 */
#define INT16_MAX /* implementation-defined */

/*!
 * @def UINT16_MAX
 * @brief A literal representing maximum of #ceu_uint16_t, should be equal to 65,535.
 */
#define UINT16_MAX /* implementation-defined */

/*!
 * @def INT32_MIN
 * @brief A literal representing minimum of #ceu_int32_t, should be equal to -2,147,483,648.
 */
#define INT32_MIN /* implementation-defined */

/*!
 * @def INT32_MAX
 * @brief A literal representing maximum of #ceu_int32_t, should be equal to 2,147,483,647.
 */
#define INT32_MAX /* implementation-defined */

/*!
 * @def UINT32_MAX
 * @brief A literal representing maximum of #ceu_uint32_t, should be equal to 4,294,967,295.
 */
#define UINT32_MAX /* implementation-defined */

/*!
 * @def INT64_MIN
 * @brief A literal representing minimum of #ceu_int64_t, should be equal to -9,223,372,036,854,775,808.
 */
#define INT64_MIN /* implementation-defined */

/*!
 * @def INT64_MAX
 * @brief A literal representing maximum of #ceu_int64_t, should be equal to 9,223,372,036,854,775,807.
 */
#define INT64_MAX /* implementation-defined */

/*!
 * @def UINT64_MAX
 * @brief A literal representing maximum of #ceu_uint64_t, should be equal to 18,446,744,073,709,551,615.
 */
#define UINT64_MAX /* implementation-defined */

#else

#include <ceu_basic/libceu_stddef_dispatcher.h>
#define __STDC_WANT_SECURE_LIB__ 1
#include <limits.h>

// clang-format off
#include <ceu_check/ceu_check_cc_macro.h>

// Before performing any operation,
// we would check whether the environment satisfies C minimum standards.

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
