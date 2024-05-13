/*!
 * @file stdint_gcc_maxmin.h
 * @brief Process pre-defined macros like `__INT16_MAX__`.
 *
 * @see https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
 */
#ifndef LIBCEU_STDINT_GCC_MAXMIN_H
#define LIBCEU_STDINT_GCC_MAXMIN_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

#if defined(__INT8_MAX__) && !defined(INT8_MAX)
#define INT8_MAX __INT8_MAX__
#endif

#if defined(INT8_MAX) && !defined(INT8_MIN)
#define INT8_MIN (-INT8_MAX - 1)
#endif

#if defined(__UINT8_MAX__) && !defined(UINT8_MAX)
#define UINT8_MAX __UINT8_MAX__
#endif

#if defined(__INT16_MAX__) && !defined(INT16_MAX)
#define INT16_MAX __INT16_MAX__
#endif

#if defined(INT16_MAX) && !defined(INT16_MIN)
#define INT16_MIN (-INT16_MAX - 1)
#endif

#if defined(__UINT16_MAX__) && !defined(UINT16_MAX)
#define UINT16_MAX __UINT16_MAX__
#endif

#if defined(__INT32_MAX__) && !defined(INT32_MAX)
#define INT32_MAX __INT32_MAX__
#endif

#if defined(INT32_MAX) && !defined(INT32_MIN)
#define INT32_MIN (-INT32_MAX - 1)
#endif

#if defined(__UINT32_MAX__) && !defined(UINT32_MAX)
#define UINT32_MAX __UINT32_MAX__
#endif

#if defined(__INT64_MAX__) && !defined(INT64_MAX)
#define INT64_MAX __INT64_MAX__
#endif

#if defined(INT64_MAX) && !defined(INT64_MIN)
#define INT64_MIN (-INT64_MAX - 1)
#endif

#if defined(__UINT64_MAX__) && !defined(UINT64_MAX)
#define UINT64_MAX __UINT64_MAX__
#endif

#if defined(__SIZE_MAX__) && !defined(SIZE_MAX)
#define SIZE_MAX __SIZE_MAX__
#endif

#if defined(__PTRDIFF_MAX__) && !defined(PTRDIFF_MAX)
#define PTRDIFF_MAX __PTRDIFF_MAX__
#endif

#endif // LIBCEU_STDINT_GCC_MAXMIN_H
