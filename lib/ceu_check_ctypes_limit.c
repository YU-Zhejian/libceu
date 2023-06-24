#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "ceu_check/ceu_c_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

	char* get_ctypes_limit_info(void)
	{
		char* headline = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(headline, 256, "Compile-time C Types max, min, etc. limits:");
		char* char_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			char_info,
			256,
			"char (%d bits, %llu size): %d -> %d",
			CHAR_BIT,
			(unsigned long long) sizeof(char),
			CHAR_MIN,
			CHAR_MAX
		);
		char* schar_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			schar_info,
			256,
			"schar (%llu size): %d -> %d",
			(unsigned long long) sizeof(signed char),
			SCHAR_MIN,
			SCHAR_MAX
		);
		char* uchar_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			uchar_info,
			256,
			"uchar (%llu size): %d -> %d",
			(unsigned long long) sizeof(unsigned char),
			0,
			UCHAR_MAX
		);
		char* other_char_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			other_char_info,
			256,
			"wchar_t (%llu size): %d -> %d, size_t (%llu size): %d -> %llu",
			(unsigned long long) sizeof(wchar_t),
			WCHAR_MIN,
			WCHAR_MAX,
			(unsigned long long) sizeof(size_t),
			0,
			(unsigned long long) SIZE_MAX
		);

		char* short_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			short_info,
			256,
			"short (%llu size): %d -> %d",
			(unsigned long long) sizeof(short),
			SHRT_MIN,
			SHRT_MAX
		);
		char* ushort_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			ushort_info,
			256,
			"ushort (%llu size): %d -> %d",
			(unsigned long long) sizeof(unsigned short),
			0,
			USHRT_MAX
		);

		char* int_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			int_info,
			256,
			"int (%llu size): %d -> %d",
			(unsigned long long) sizeof(int),
			INT_MIN,
			INT_MAX
		);
		char* uint_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			uint_info,
			256,
			"uint (%llu size): %d -> %ud",
			(unsigned long long) sizeof(unsigned int),
			0,
			UINT_MAX
		);

		char* long_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			long_info,
			256,
			"long (%llu size): %ld -> %ld",
			(unsigned long long) sizeof(long),
			LONG_MIN,
			LONG_MAX
		);
		char* ulong_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			ulong_info,
			256,
			"ullong (%llu size): %d -> %lu",
			(unsigned long long) sizeof(unsigned long),
			0,
			ULONG_MAX
		);
		char* llong_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			llong_info,
			256,
			"long (%llu size): %lld -> %lld",
			(unsigned long long) sizeof(long long),
			LLONG_MIN,
			LLONG_MAX
		);
		char* ullong_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			ullong_info,
			256,
			"ulong (%llu size): %d -> %llu",
			(unsigned long long) sizeof(unsigned long long),
			0,
			ULLONG_MAX
		);
		char* bool_info = (char*)ceu_scalloc(256, sizeof(char));
		snprintf(
			bool_info,
			256,
			"bool (%llu size): %d -> %d",
			(unsigned long long) sizeof(bool),
			false,
			true
		);

		char* retbuff = ceu_str_join_with_sep(
			"\n\t",
			CEU_STR_JOIN_WARN_SKIP,
			14,
			headline,
			char_info,
			schar_info,
			uchar_info,
			other_char_info,
			short_info,
			ushort_info,
			int_info,
			uint_info,
			long_info,
			ulong_info,
			llong_info,
			ullong_info,
			bool_info
		);
		ceu_free_non_null(headline);
		ceu_free_non_null(char_info);
		ceu_free_non_null(schar_info);
		ceu_free_non_null(uchar_info);
		ceu_free_non_null(other_char_info);
		ceu_free_non_null(ushort_info);
		ceu_free_non_null(int_info);
		ceu_free_non_null(uint_info);
		ceu_free_non_null(long_info);
		ceu_free_non_null(ulong_info);
		ceu_free_non_null(llong_info);
		ceu_free_non_null(ullong_info);
		ceu_free_non_null(bool_info);
		return retbuff;
	}

#ifdef __cplusplus
}
#endif
