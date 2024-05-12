#ifndef CEU_STDINT_GCC_TYPEDEF_H
#define CEU_STDINT_GCC_TYPEDEF_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

#if !defined(CEU_INT8_PRINTF_MODIFIER) && defined(__INT8_TYPE__)
typedef __INT8_TYPE__ ceu_int8_t;
#define CEU_INT8_IS_DEFINED
#endif

#if !defined(CEU_UINT8_PRINTF_MODIFIER) && defined(__UINT8_TYPE__)
typedef __UINT8_TYPE__ ceu_uint8_t;
#define CEU_UINT8_IS_DEFINED
#endif

#if !defined(CEU_INT16_PRINTF_MODIFIER) && defined(__INT16_TYPE__)
typedef __INT16_TYPE__ ceu_int16_t;
#define CEU_INT16_IS_DEFINED
#endif

#if !defined(CEU_UINT16_PRINTF_MODIFIER) && defined(__UINT16_TYPE__)
typedef __UINT16_TYPE__ ceu_uint16_t;
#define CEU_UINT16_IS_DEFINED
#endif

#if !defined(CEU_INT32_PRINTF_MODIFIER) && defined(__INT32_TYPE__)
typedef __INT32_TYPE__ ceu_int32_t;
#define CEU_INT32_IS_DEFINED
#endif

#if !defined(CEU_UINT32_PRINTF_MODIFIER) && defined(__UINT32_TYPE__)
typedef __UINT32_TYPE__ ceu_uint32_t;
#define CEU_UINT32_IS_DEFINED
#endif

#if !defined(CEU_INT64_PRINTF_MODIFIER) && defined(__INT64_TYPE__)
typedef __INT64_TYPE__ ceu_int64_t;
#define CEU_INT64_IS_DEFINED
#endif

#if !defined(CEU_UINT64_PRINTF_MODIFIER) && defined(__UINT64_TYPE__)
typedef __UINT64_TYPE__ ceu_uint64_t;
#define CEU_UINT64_IS_DEFINED
#endif

#endif