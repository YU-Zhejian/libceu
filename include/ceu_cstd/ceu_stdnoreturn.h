/**
 * @file ceu_stdnoreturn.h
 * @author YU Zhejian
 * @brief Compatible file of <stdnoreturn.h>, providing definition of noreturn macro/keyword.
 * @version 0.1
 * @date 2024-04-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifdef __cplusplus
// FIXME: Temporary solution for C++ 11.
#define noreturn [[noreturn]]
#else
#ifndef CEU_STDNORETURN_H
#define CEU_STDNORETURN_H

#include "ceu_check/ceu_check_cc.h"

#include "ceu_basic/libceu_stddef.h"
#if (CEU_HAVE_INCLUDE_STDNORETURN_H == 1 && CEU_CM_HAVE_WORKING_C_NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C_NORETURN_RUN_SHARED == 0)
#include <stdnoreturn.h> // This file should define noreturn
#elif (CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC * CEU_CM_HAVE_WORKING_C__NORETURN_RUN_STATIC == 0)
// Normal condition where _Noreturn is supported
#define noreturn _Noreturn
#elif (CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_STATIC * #define CEU_CM_HAVE_WORKING_C___ATTRIBUTE___RUN_SHARED == 0)
// Normal condition where __attribute__((noreturn)) is supported
#define noreturn __attribute__((noreturn))
#else
// Have nothing!
#define noreturn // NOLINT
#endif
#endif
#endif
