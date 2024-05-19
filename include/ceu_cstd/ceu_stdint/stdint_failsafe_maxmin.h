/*!
 * @file stdint_failsafe_maxmin.h
 * @brief Define max and min in fail-safe mode.
 */
#ifndef LIBCEU_STDINT_FAILSAFE_MAXMIN_H
#define LIBCEU_STDINT_FAILSAFE_MAXMIN_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
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

#ifndef SIZE_MAX
#if defined(CEU_CM_TYPE_SIZE_T_SIZE)
#if CEU_CM_TYPE_SIZE_T_SIZE == CEU_INT8_SIZE
#define SIZE_MAX UINT8_MAX
#elif CEU_CM_TYPE_SIZE_T_SIZE == CEU_INT16_SIZE
#define SIZE_MAX UINT16_MAX
#elif CEU_CM_TYPE_SIZE_T_SIZE == CEU_INT32_SIZE
#define SIZE_MAX UINT32_MAX
#elif CEU_CM_TYPE_SIZE_T_SIZE == CEU_INT64_SIZE
#define SIZE_MAX UINT64_MAX
#endif
#else
#error "Failed to determine size of ceu_size_t!"
#endif
#endif

// FIXME: PTRDIFF_MAX
#ifndef PTRDIFF_MAX
#define PTRDIFF_MAX SIZE_MAX
#endif

#endif // LIBCEU_STDINT_FAILSAFE_MAXMIN_H
