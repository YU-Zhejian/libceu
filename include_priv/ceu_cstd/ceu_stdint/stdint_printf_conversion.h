#ifndef CEU_STDINT_PRINTF_CONVERSION_H
#define CEU_STDINT_PRINTF_CONVERSION_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

#if defined(CEU_CM_TYPE_C_SIZE) && (CEU_CM_TYPE_C_SIZE == CEU_INT8_SIZE)
#define CEU_INT8_PRINTF_MODIFIER "hh"
#define CEU_INT8_C(c) c
#define CEU_UINT8_C(c) c##U
#endif

#if defined(CEU_CM_TYPE_SH_SIZE) && (CEU_CM_TYPE_SH_SIZE == CEU_INT16_SIZE)
#define CEU_INT16_PRINTF_MODIFIER "h"
#define CEU_INT16_C(c) c
#define CEU_UINT16_C(c) c##U
#elif defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT16_SIZE)
#define CEU_INT16_PRINTF_MODIFIER ""
#define CEU_INT16_C(c) c
#define CEU_UINT16_C(c) c##U
#endif

#if defined(CEU_CM_TYPE_I_SIZE) && (CEU_CM_TYPE_I_SIZE == CEU_INT32_SIZE)
#define CEU_INT32_PRINTF_MODIFIER ""
#define CEU_INT32_C(c) c
#define CEU_UINT32_C(c) c##U
#elif defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT32_SIZE)
#define CEU_INT32_PRINTF_MODIFIER "l"
#define CEU_INT32_C(c) c##L
#define CEU_UINT32_C(c) c##UL
#endif

#if defined(CEU_CM_TYPE_L_SIZE) && (CEU_CM_TYPE_L_SIZE == CEU_INT64_SIZE)
#define CEU_INT64_PRINTF_MODIFIER "l"
#define CEU_INT64_C(c) c##L
#define CEU_UINT64_C(c) c##UL
#elif defined(CEU_CM_TYPE_LL_SIZE) && (CEU_CM_TYPE_LL_SIZE == CEU_INT64_SIZE)
#define CEU_INT64_PRINTF_MODIFIER "ll"
#define CEU_INT64_C(c) c##LL
#define CEU_UINT64_C(c) c##ULL
#endif

#endif // CEU_STDINT_PRINTF_CONVERSION_H
