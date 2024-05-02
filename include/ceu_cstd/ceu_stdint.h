/**
 * @file ceu_stdint.h
 * @brief A simple stdint.h implementation.
 *
 * @todo Needs to further test on different 32- and 64-bit, LE and BE platforms.
 */

#ifndef CEU_STDINT_H
#define CEU_STDINT_H

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

#include "ceu_check/ceu_check_cc.h"
#include <limits.h>

#if (CEU_CM_TYPE_C_SIZE <= CEU_CM_TYPE_SH_SIZE && CEU_CM_TYPE_SH_SIZE <= CEU_CM_TYPE_I_SIZE && CEU_CM_TYPE_I_SIZE <= CEU_CM_TYPE_L_SIZE && CEU_CM_TYPE_L_SIZE <= CEU_CM_TYPE_LL_SIZE)
// Comfort C minimum std
#else
#error "The current C/C++ compiler does not follow basic C standard! Requrie: sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)"
#endif

#if (1 <= CEU_CM_TYPE_C_SIZE && 2 <= CEU_CM_TYPE_SH_SIZE && 2 <= CEU_CM_TYPE_I_SIZE && 4 <= CEU_CM_TYPE_L_SIZE && 8 <= CEU_CM_TYPE_LL_SIZE)
// Comfort C minimum std
#else
#error "The current C/C++ compiler does not follow basic C standard! Requrie: 1 <= sizeof(char); 2 <= sizeof(short); 2 <= sizeof(int); 4 <= sizeof(long); 8 <= sizeof(long long)"
#endif

#define CEU_INT8_SIZE 1
#define CEU_INT16_SIZE 2
#define CEU_INT32_SIZE 4
#define CEU_INT64_SIZE 8

#if defined(_I8_MIN) && !defined(INT8_MIN)
#define INT8_MIN _I8_MIN
#endif

#if defined(_I8_MAX) && !defined(INT8_MAX)
#define INT8_MAX _I8_MAX
#endif

#if defined(_UI8_MAX) && !defined(UINT8_MAX)
#define UINT8_MAX _UI8_MAX
#endif

#if defined(_I16_MIN) && !defined(INT16_MIN)
#define INT16_MIN _I16_MIN
#endif

#if defined(_I16_MAX) && !defined(INT16_MAX)
#define INT16_MAX _I16_MAX
#endif

#if defined(_UI16_MAX) && !defined(UINT16_MAX)
#define UINT16_MAX _UI16_MAX
#endif

#if defined(_I32_MIN) && !defined(INT32_MIN)
#define INT32_MIN _I32_MIN
#endif

#if defined(_I32_MAX) && !defined(INT32_MAX)
#define INT32_MAX _I32_MAX
#endif

#if defined(_UI32_MAX) && !defined(UINT32_MAX)
#define UINT32_MAX _UI32_MAX
#endif

#if defined(_I64_MIN) && !defined(INT64_MIN)
#define INT64_MIN _I64_MIN
#endif

#if defined(_I64_MAX) && !defined(INT64_MAX)
#define INT64_MAX _I64_MAX
#endif

#if defined(_UI64_MAX) && !defined(UINT64_MAX)
#define UINT64_MAX _UI64_MAX
#endif

#ifndef INT8_MAX
#define INT8_MAX 127
#endif

#ifndef INT8_MIN
#define INT8_MIN (-128)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 255
#endif

#ifndef INT16_MAX
#define INT16_MAX 32767
#endif

#ifndef INT16_MIN
#define INT16_MIN (-32768)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 65535
#endif

#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif

#ifndef INT32_MIN
#define INT32_MIN (-2147483648)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 4294967295
#endif

#ifndef INT64_MAX
#define INT64_MAX 9223372036854775807LL
#endif

#ifndef INT64_MIN
#define INT64_MIN (-9223372036854775807LL - 1LL)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 18446744073709551615ULL
#endif

#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX

#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN

#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX

#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

#if defined(CEU_CM_TYPE_SC_SIZE) && (CEU_CM_TYPE_SC_SIZE == CEU_INT8_SIZE) && defined(SCHAR_MIN) && (SCHAR_MIN == INT8_MIN) && defined(SCHAR_MAX) && (SCHAR_MAX == INT8_MAX)
typedef signed char int8_t;
#define CEU_INT8_PRINTF_MODIFIER "hhd"
#elif defined(CEU_CM_TYPE_C_SIZE) && (CEU_CM_TYPE_C_SIZE == CEU_INT8_SIZE) && defined(CHAR_MIN) && (CHAR_MIN == INT8_MIN) && defined(CHAR_MAX) && (CHAR_MAX == INT8_MAX)
typedef char int8_t;
#define CEU_INT8_PRINTF_MODIFIER "hhd"
#else
#error "Failed to define int8_t! Checked: signed char, char"
#endif

#if defined(CEU_CM_TYPE_UC_SIZE) && (CEU_CM_TYPE_UC_SIZE == CEU_INT8_SIZE) && defined(UCHAR_MAX) && (UCHAR_MAX == UINT8_MAX)
typedef unsigned char uint8_t;
#define CEU_UINT8_PRINTF_MODIFIER "hhu"
#else
#error "Failed to define uint8_t! Checked: unsigned char"
#endif

#if defined(CEU_CM_TYPE_SSH_SIZE) && (CEU_CM_TYPE_SSH_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef signed short int16_t;
#define CEU_INT16_PRINTF_MODIFIER "hd"
#elif defined(CEU_CM_TYPE_SH_SIZE) && (CEU_CM_TYPE_SH_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef short int16_t;
#define CEU_INT16_PRINTF_MODIFIER "hd"
#elif defined(CEU_CM_TYPE_SSHI_SIZE) && (CEU_CM_TYPE_SSHI_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef signed short int int16_t;
#define CEU_INT16_PRINTF_MODIFIER "hd"
#elif defined(CEU_CM_TYPE_SHI_SIZE) && (CEU_CM_TYPE_SHI_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef short int int16_t;
#define CEU_INT16_PRINTF_MODIFIER "hd"
#elif defined(CEU_CM_TYPE_SI_SIZE) && (CEU_CM_TYPE_SI_SIZE == CEU_INT16_SIZE) && defined(INT_MIN) && (INT_MIN == INT16_MIN) && defined(INT_MAX) && (INT_MAX == INT16_MAX)
typedef signed int int16_t;
#define CEU_INT16_PRINTF_MODIFIER "d"
#elif defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT16_SIZE) && defined(INT_MIN) && (INT_MIN == INT16_MIN) && defined(INT_MAX) && (INT_MAX == INT16_MAX)
typedef int int16_t;
#define CEU_INT16_PRINTF_MODIFIER "d"
#else
#error "Failed to define int16_t! Checked: signed short, short, signed short int, short int, signed int, int"
#endif

#if defined(CEU_CM_TYPE_USH_SIZE) && (CEU_CM_TYPE_USH_SIZE == CEU_INT16_SIZE) && defined(USHRT_MAX) && (USHRT_MAX == UINT16_MAX)
typedef unsigned short uint16_t;
#define CEU_UINT16_PRINTF_MODIFIER "hu"
#elif defined(CEU_CM_TYPE_USHI_SIZE) && (CEU_CM_TYPE_USHI_SIZE == CEU_INT16_SIZE) && defined(USHRT_MAX) && (USHRT_MAX == UINT16_MAX)
typedef unsigned short int uint16_t;
#define CEU_UINT16_PRINTF_MODIFIER "hu"
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_INT16_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT16_MAX)
typedef unsigned int uint16_t;
#define CEU_UINT16_PRINTF_MODIFIER "u"
#elif defined(CEU_CM_TYPE_U_SIZE) && (CEU_CM_TYPE_U_SIZE == CEU_INT16_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT16_MAX)
typedef unsigned uint16_t;
#define CEU_UINT16_PRINTF_MODIFIER "u"
#else
#error "Failed to define uint16_t! Checked: unsigned short, unsigned short int, unsigned int, unsigned"
#endif

#if defined(CEU_CM_TYPE_SI_SIZE) && (CEU_CM_TYPE_SI_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef signed int int32_t;
#define CEU_INT32_PRINTF_MODIFIER "d"
#elif defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef int int32_t;
#define CEU_INT32_PRINTF_MODIFIER "d"
#elif defined(CEU_CM_TYPE_SL_SIZE) && (CEU_CM_TYPE_SL_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef signed long int32_t;
#define CEU_INT32_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef long int32_t;
#define CEU_INT32_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_SLI_SIZE) && (CEU_CM_TYPE_SLI_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef signed long int int32_t;
#define CEU_INT32_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_LI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef long int int32_t;
#define CEU_INT32_PRINTF_MODIFIER "ld"
#else
#error "Failed to define int32_t! Checked: signed int, int, signed long, long, signed long int, long int"
#endif

#if defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_INT32_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT32_MAX)
typedef unsigned int uint32_t;
#define CEU_UINT32_PRINTF_MODIFIER "u"
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_INT32_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT32_MAX)
typedef unsigned long uint32_t;
#define CEU_UINT32_PRINTF_MODIFIER "lu"
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_INT32_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT32_MAX)
typedef unsigned long int uint32_t;
#define CEU_UINT32_PRINTF_MODIFIER "lu"
#else
#error "Failed to define uint32_t! Checked: unsigned int, unsigned long, unsigned long int"
#endif

// TODO: Following code may go wrong!
#define CEU_HAVE_INT64 1

#if defined(CEU_CM_TYPE_SL_SIZE) && (CEU_CM_TYPE_SL_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef signed long int64_t;
#define CEU_INT64_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef long int64_t;
#define CEU_INT64_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_SLI_SIZE) && (CEU_CM_TYPE_SLI_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef signed long int int64_t;
#define CEU_INT64_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_LI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef long int int64_t;
#define CEU_INT64_PRINTF_MODIFIER "ld"
#elif defined(CEU_CM_TYPE_SLL_SIZE) && (CEU_CM_TYPE_SLL_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef signed long long int64_t;
#define CEU_INT64_PRINTF_MODIFIER "lld"
#elif defined(CEU_CM_TYPE_LL_SIZE) && (CEU_CM_TYPE_LL_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef long long int64_t;
#define CEU_INT64_PRINTF_MODIFIER "lld"
#elif defined(CEU_CM_TYPE_SLLI_SIZE) && (CEU_CM_TYPE_SLLI_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef signed long long int int64_t;
#define CEU_INT64_PRINTF_MODIFIER "lld"
#elif defined(CEU_CM_TYPE_LLI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef long long int int64_t;
#define CEU_INT64_PRINTF_MODIFIER "lld"
#else
#undef CEU_HAVE_INT64
#warning "Failed to define int64_t! Checked: signed long, long, signed long int, long int, signed long long, long long, signed long long int, long long int"
#endif

#define CEU_HAVE_UINT64 1
#if defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_INT64_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT64_MAX)
typedef unsigned long uint64_t;
#define CEU_UINT64_PRINTF_MODIFIER "lu"
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_INT64_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT64_MAX)
typedef unsigned long int uint64_t;
#define CEU_UINT64_PRINTF_MODIFIER "lu"
#elif defined(CEU_CM_TYPE_ULL_SIZE) && (CEU_CM_TYPE_ULL_SIZE == CEU_INT64_SIZE) && defined(ULLONG_MAX) && (ULLONG_MAX == UINT64_MAX)
typedef unsigned long long uint64_t;
#define CEU_UINT64_PRINTF_MODIFIER "llu"
#elif defined(CEU_CM_TYPE_ULLI_SIZE) && (CEU_CM_TYPE_ULLI_SIZE == CEU_INT64_SIZE) && defined(ULLONG_MAX) && (ULLONG_MAX == UINT64_MAX)
typedef unsigned long long int uint64_t;
#define CEU_UINT64_PRINTF_MODIFIER "llu"
#else
#undef CEU_HAVE_UINT64
#error "Failed to define uint64_t! Checked: unsigned long, unsigned long int, unsigned long long, unsigned long long int"
#endif

#ifdef CEU_HAVE_INT64
typedef int64_t intmax_t;
#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#else
typedef int32_t intmax_t;
#define INTMAX_MIN INT32_MIN
#define INTMAX_MAX INT32_MAX
#endif

#ifdef CEU_HAVE_UINT64
typedef uint64_t uintmax_t;
#define UINTMAX_MAX UINT64_MAX
#else
typedef uint32_t uintmax_t;
#define UINTMAX_MAX UINT32_MAX
#endif

typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;
typedef int_least8_t int_fast8_t;
typedef uint_least8_t uint_fast8_t;
typedef int_least16_t int_fast16_t;
typedef uint_least16_t uint_fast16_t;
typedef int_least32_t int_fast32_t;
typedef uint_least32_t uint_fast32_t;
typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;

#endif // CEU_STDINT_H
