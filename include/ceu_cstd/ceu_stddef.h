#ifndef CEU_STDDEF_H
#define CEU_STDDEF_H

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

#ifdef CEU_CM_TYPE_SIZE_T_SIZE
#if defined(CEU_CM_TYPE_USH_SIZE) && (CEU_CM_TYPE_USH_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned short ceu_size_t;
#elif defined(CEU_CM_TYPE_USHI_SIZE) && (CEU_CM_TYPE_USHI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned short int ceu_size_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned int ceu_size_t;
#elif defined(CEU_CM_TYPE_U_SIZE) && (CEU_CM_TYPE_U_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned ceu_size_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned int ceu_size_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long ceu_size_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long int ceu_size_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long ceu_size_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long int ceu_size_t;
#elif defined(CEU_CM_TYPE_ULL_SIZE) && (CEU_CM_TYPE_ULL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long long ceu_size_t;
#elif defined(CEU_CM_TYPE_ULLI_SIZE) && (CEU_CM_TYPE_ULLI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long long int ceu_size_t;
#else
#error "Failed to define ceu_size_t! Checked: unsigned short, unsigned short int, unsigned int, unsigned, unsigned int, unsigned long, unsigned long int"
#endif
#else
#error "Failed to define ceu_size_t! ceu_size_t seems not supported by the environhment."
#endif

// FIXME: Still requires revison here
#ifndef CEU_NULL
#ifndef __cplusplus
#define CEU_NULL ((void*)0)
#else
#define CEU_NULL 0
#endif
#endif

#endif // CEU_STDDEF_H
