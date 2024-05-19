/**
 * @file stdint_failsafe_typedef.h
 * @author YU Zhejian
 * @brief Failsafe definition to `ceu_intN_t` and `ceu_uintN_t`.
 * @version 0.1
 * @date 2024-05-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CEU_STDINT_TYPEDEF_FAILSAFE_H
#define CEU_STDINT_TYPEDEF_FAILSAFE_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

#if !defined(CEU_INT8_IS_DEFINED)
#if defined(CEU_CM_TYPE_SC_SIZE) && (CEU_CM_TYPE_SC_SIZE == CEU_INT8_SIZE) && defined(SCHAR_MIN) && (SCHAR_MIN == INT8_MIN) && defined(SCHAR_MAX) && (SCHAR_MAX == INT8_MAX)
typedef signed char ceu_int8_t;
#elif defined(CEU_CM_TYPE_C_SIZE) && (CEU_CM_TYPE_C_SIZE == CEU_INT8_SIZE) && defined(CHAR_MIN) && (CHAR_MIN == INT8_MIN) && defined(CHAR_MAX) && (CHAR_MAX == INT8_MAX)
typedef char ceu_int8_t;
#else
#error "Failed to define ceu_int8_t! Checked: signed char, char"
#endif
#endif

#if !defined(CEU_UINT8_IS_DEFINED)
#if defined(CEU_CM_TYPE_UC_SIZE) && (CEU_CM_TYPE_UC_SIZE == CEU_INT8_SIZE) && defined(UCHAR_MAX) && (UCHAR_MAX == UINT8_MAX)
typedef unsigned char ceu_uint8_t;
#else
#error "Failed to define ceu_uint8_t! Checked: unsigned char"
#endif
#endif

#if !defined(CEU_INT16_IS_DEFINED)
#if defined(CEU_CM_TYPE_SSH_SIZE) && (CEU_CM_TYPE_SSH_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef signed short ceu_int16_t;
#elif defined(CEU_CM_TYPE_SH_SIZE) && (CEU_CM_TYPE_SH_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef short ceu_int16_t;
#elif defined(CEU_CM_TYPE_SSHI_SIZE) && (CEU_CM_TYPE_SSHI_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef signed short int ceu_int16_t;
#elif defined(CEU_CM_TYPE_SHI_SIZE) && (CEU_CM_TYPE_SHI_SIZE == CEU_INT16_SIZE) && defined(SHRT_MIN) && (SHRT_MIN == INT16_MIN) && defined(SHRT_MAX) && (SHRT_MAX == INT16_MAX)
typedef short int ceu_int16_t;
#elif defined(CEU_CM_TYPE_SI_SIZE) && (CEU_CM_TYPE_SI_SIZE == CEU_INT16_SIZE) && defined(INT_MIN) && (INT_MIN == INT16_MIN) && defined(INT_MAX) && (INT_MAX == INT16_MAX)
typedef signed int ceu_int16_t;
#elif defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT16_SIZE) && defined(INT_MIN) && (INT_MIN == INT16_MIN) && defined(INT_MAX) && (INT_MAX == INT16_MAX)
typedef int ceu_int16_t;
#else
#error "Failed to define ceu_int16_t! Checked: signed short, short, signed short int, short int, signed int, int"
#endif
#endif

#if !defined(CEU_UINT16_IS_DEFINED)
#if defined(CEU_CM_TYPE_USH_SIZE) && (CEU_CM_TYPE_USH_SIZE == CEU_INT16_SIZE) && defined(USHRT_MAX) && (USHRT_MAX == UINT16_MAX)
typedef unsigned short ceu_uint16_t;
#elif defined(CEU_CM_TYPE_USHI_SIZE) && (CEU_CM_TYPE_USHI_SIZE == CEU_INT16_SIZE) && defined(USHRT_MAX) && (USHRT_MAX == UINT16_MAX)
typedef unsigned short int ceu_uint16_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_INT16_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT16_MAX)
typedef unsigned int ceu_uint16_t;
#elif defined(CEU_CM_TYPE_U_SIZE) && (CEU_CM_TYPE_U_SIZE == CEU_INT16_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT16_MAX)
typedef unsigned ceu_uint16_t;
#else
#error "Failed to define ceu_uint16_t! Checked: unsigned short, unsigned short int, unsigned, unsigned int"
#endif
#endif

#if !defined(CEU_INT32_IS_DEFINED)
#if defined(CEU_CM_TYPE_SI_SIZE) && (CEU_CM_TYPE_SI_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef signed int ceu_int32_t;
#elif defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef int ceu_int32_t;
#elif defined(CEU_CM_TYPE_SL_SIZE) && (CEU_CM_TYPE_SL_SIZE == CEU_INT32_SIZE) && defined(INT_MIN) && (INT_MIN == INT32_MIN) && defined(INT_MAX) && (INT_MAX == INT32_MAX)
typedef signed long ceu_int32_t;
#elif defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef long ceu_int32_t;
#elif defined(CEU_CM_TYPE_SLI_SIZE) && (CEU_CM_TYPE_SLI_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef signed long int ceu_int32_t;
#elif defined(CEU_CM_TYPE_LI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT32_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT32_MIN) && defined(LONG_MAX) && (LONG_MAX == INT32_MAX)
typedef long int ceu_int32_t;
#else
#error "Failed to define ceu_int32_t! Checked: signed int, int, signed long, long, signed long int, long int"
#endif
#endif

#if !defined(CEU_UINT32_IS_DEFINED)
#if defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_INT32_SIZE) && defined(UINT_MAX) && (UINT_MAX == UINT32_MAX)
typedef unsigned int ceu_uint32_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_INT32_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT32_MAX)
typedef unsigned long ceu_uint32_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_INT32_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT32_MAX)
typedef unsigned long int ceu_uint32_t;
#else
#error "Failed to define ceu_uint32_t! Checked: unsigned int, unsigned long, unsigned long int"
#endif
#endif

#if !defined(CEU_INT64_IS_DEFINED)
#if defined(CEU_CM_TYPE_SL_SIZE) && (CEU_CM_TYPE_SL_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef signed long ceu_int64_t;
#elif defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef long ceu_int64_t;
#elif defined(CEU_CM_TYPE_SLI_SIZE) && (CEU_CM_TYPE_SLI_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef signed long int ceu_int64_t;
#elif defined(CEU_CM_TYPE_LI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT64_SIZE) && defined(LONG_MIN) && (LONG_MIN == INT64_MIN) && defined(LONG_MAX) && (LONG_MAX == INT64_MAX)
typedef long int ceu_int64_t;
#elif defined(CEU_CM_TYPE_SLL_SIZE) && (CEU_CM_TYPE_SLL_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef signed long long ceu_int64_t;
#elif defined(CEU_CM_TYPE_LL_SIZE) && (CEU_CM_TYPE_LL_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef long long ceu_int64_t;
#elif defined(CEU_CM_TYPE_SLLI_SIZE) && (CEU_CM_TYPE_SLLI_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef signed long long int ceu_int64_t;
#elif defined(CEU_CM_TYPE_LLI_SIZE) && (CEU_CM_TYPE_LI_SIZE == CEU_INT64_SIZE) && defined(LLONG_MIN) && (LLONG_MIN == INT64_MIN) && defined(LLONG_MAX) && (LLONG_MAX == INT64_MAX)
typedef long long int ceu_int64_t;
#else
#error "Failed to define ceu_int64_t! Checked: signed long, long, signed long int, long int, signed long long, long long, signed long long int, long long int"
#endif
#endif

#if !defined(CEU_UINT64_IS_DEFINED)
#if defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_INT64_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT64_MAX)
typedef unsigned long ceu_uint64_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_INT64_SIZE) && defined(ULONG_MAX) && (ULONG_MAX == UINT64_MAX)
typedef unsigned long int ceu_uint64_t;
#elif defined(CEU_CM_TYPE_ULL_SIZE) && (CEU_CM_TYPE_ULL_SIZE == CEU_INT64_SIZE) && defined(ULLONG_MAX) && (ULLONG_MAX == UINT64_MAX)
typedef unsigned long long ceu_uint64_t;
#elif defined(CEU_CM_TYPE_ULLI_SIZE) && (CEU_CM_TYPE_ULLI_SIZE == CEU_INT64_SIZE) && defined(ULLONG_MAX) && (ULLONG_MAX == UINT64_MAX)
typedef unsigned long long int ceu_uint64_t;
#else
#error "Failed to define ceu_uint64_t! Checked: unsigned long, unsigned long int, unsigned long long, unsigned long long int"
#endif
#endif

#endif