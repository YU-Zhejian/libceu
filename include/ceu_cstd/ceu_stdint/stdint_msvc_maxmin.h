#ifndef LIBCEU_STDINT_MSVC_MAXMIN_H
#define LIBCEU_STDINT_MSVC_MAXMIN_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

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

// MSVC should define SIZE_MAX, so no operation here.
// FIXME: However, MSVC sees not define PTRDIFF_MAX

#endif // LIBCEU_STDINT_MSVC_MAXMIN_H
