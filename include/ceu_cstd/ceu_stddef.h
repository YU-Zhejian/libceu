/**
 * @file ceu_stddef.h
 * @author YU Zhejian
 * @brief Definition of #CEU_NULL, #ceu_size_t and #ceu_ptrdiff_t commonly-seen in other `stddef.h`s.
 * @version 0.1
 * @date 2024-05-14
 *
 * @see ceu_stdbool.h for definition of #ceu_bool, #ceu_true and #ceu_false (which does not comfort C standards).
 * @see [cppreference](https://en.cppreference.com/w/c/types) description of what should be defined in `stddef.h`.
 * @see ceu_stdnoreturn.h for #ceu_noreturn.
 */
#ifndef CEU_STDDEF_H
#define CEU_STDDEF_H

#include <ceu_basic/libceu_stddef_dispatcher.h>

/*!
 * @def CEU_NULL
 * @brief The NULL pointer. By default, expand to `0` cast to `(void*)` under C and literal 0 under C++.
 *
 * As-is defined in POSIX.1 standard. You may also define your own if you know your compiler well.
 *
 * @see [POSIX.1-2008](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stddef.h.html) description of `NULL`.
 * @see [cppreference](https://en.cppreference.com/w/c/types/NULL) description of `NULL`.
 * @warning Do not use #CEU_NULL under C++ 11 or above. Use `nullptr`/`std:nullptr_t` instead.
 */
#ifndef CEU_NULL
#if defined(__cplusplus)
#define CEU_NULL 0
#else
#define CEU_NULL ((void*)0)
#endif
#endif

#if defined(CEU_UNDER_DOXYGEN)

/*!
 * @typedef ceu_size_t
 * @brief TODO
 */
typedef /* implementation-defined */ ceu_size_t;

/*!
 * @typedef ceu_ptrdiff_t
 * @brief TODO
 */
typedef /* implementation-defined */ ceu_ptrdiff_t;
#else

#ifdef __SIZE_TYPE__ // Shortcut for GCC-based compilers
typedef __SIZE_TYPE__ ceu_size_t;
#elif defined(CEU_CM_TYPE_SIZE_T_SIZE)
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

// FIXME: not implemented
// #ifdef __PTRDIFF_TYPE__
// typedef __PTRDIFF_TYPE__ ceu_ptrdiff_t;
// #else
// #error "Failed to define ceu_ptrdiff_t! ceu_ptrdiff_t seems not supported by the environhment."
// #endif
#endif
#endif // CEU_STDDEF_H
