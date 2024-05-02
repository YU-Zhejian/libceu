#ifndef CEU_STDDEF_H
#define CEU_STDDEF_H

#ifdef CEU_CM_UNDER_CMAKE
#include "ceu_basic/libceu_stddef_cmake.h"
#endif

#ifdef CEU_CM_TYPE_SIZE_T_SIZE
#if defined(CEU_CM_TYPE_USH_SIZE) && (CEU_CM_TYPE_USH_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned short size_t;
#elif defined(CEU_CM_TYPE_USHI_SIZE) && (CEU_CM_TYPE_USHI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned short int size_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned int size_t;
#elif defined(CEU_CM_TYPE_U_SIZE) && (CEU_CM_TYPE_U_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned size_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned int size_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long size_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long int size_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long size_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long int size_t;
#elif defined(CEU_CM_TYPE_ULL_SIZE) && (CEU_CM_TYPE_ULL_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long long size_t;
#elif defined(CEU_CM_TYPE_ULLI_SIZE) && (CEU_CM_TYPE_ULLI_SIZE == CEU_CM_TYPE_SIZE_T_SIZE)
typedef unsigned long long int size_t;
#else
#error "Failed to define size_t! Checked: unsigned short, unsigned short int, unsigned int, unsigned, unsigned int, unsigned long, unsigned long int"
#endif
#else
#error "Failed to define size_t! size_t seems not supported by the environhment."
#endif

#ifdef CEU_CM_TYPE_PTRDIFF_T_SIZE
#if defined(CEU_CM_TYPE_USH_SIZE) && (CEU_CM_TYPE_USH_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned short ptrdiff_t;
#elif defined(CEU_CM_TYPE_USHI_SIZE) && (CEU_CM_TYPE_USHI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned short int ptrdiff_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned int ptrdiff_t;
#elif defined(CEU_CM_TYPE_U_SIZE) && (CEU_CM_TYPE_U_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned ptrdiff_t;
#elif defined(CEU_CM_TYPE_UI_SIZE) && (CEU_CM_TYPE_UI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned int ptrdiff_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long ptrdiff_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long int ptrdiff_t;
#elif defined(CEU_CM_TYPE_UL_SIZE) && (CEU_CM_TYPE_UL_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long ptrdiff_t;
#elif defined(CEU_CM_TYPE_ULI_SIZE) && (CEU_CM_TYPE_ULI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long int ptrdiff_t;
#elif defined(CEU_CM_TYPE_ULL_SIZE) && (CEU_CM_TYPE_ULL_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long long ptrdiff_t;
#elif defined(CEU_CM_TYPE_ULLI_SIZE) && (CEU_CM_TYPE_ULLI_SIZE == CEU_CM_TYPE_PTRDIFF_T_SIZE)
typedef unsigned long long int ptrdiff_t;
#else
#error "Failed to define ptrdiff_t! Checked: unsigned short, unsigned short int, unsigned int, unsigned, unsigned int, unsigned long, unsigned long int"
#endif
#else
#error "Failed to define ptrdiff_t! ptrdiff_t seems not supported by the environhment."
#endif

#ifndef NULL
#ifndef __cplusplus
#define NULL ((void*)0)
#else
#define NULL 0
#endif
#endif

#endif // CEU_STDDEF_H
