/**
 * Microsoft MSVC. That is, what is bundled in Visual Studio.
 */
#include <string.h>

#if defined(_MSC_VER) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_MSVC
#define CEU_COMPILER_NAME "MSVC"
#define CEU_COMPILER_VERSION _MSC_VER
#if CEU_COMPILER_VERSION == 800
#define VISUAL_STUDIO_VER "1"
#elif CEU_COMPILER_VERSION == 900
#define VISUAL_STUDIO_VER "3"
#elif CEU_COMPILER_VERSION == 1000
#define VISUAL_STUDIO_VER "4"
#elif CEU_COMPILER_VERSION == 1100
#define VISUAL_STUDIO_VER "5"
#elif CEU_COMPILER_VERSION == 1200
#define VISUAL_STUDIO_VER "6"
#elif CEU_COMPILER_VERSION == 1300
#define VISUAL_STUDIO_VER "7"
#elif CEU_COMPILER_VERSION == 1310
#define VISUAL_STUDIO_VER "7.1 (2003)"
#elif CEU_COMPILER_VERSION == 1400
#define VISUAL_STUDIO_VER "8 (2005)"
#elif CEU_COMPILER_VERSION == 1500
#define VISUAL_STUDIO_VER "9 (2008)"
#elif CEU_COMPILER_VERSION == 1600
#define VISUAL_STUDIO_VER "10 (2010)"
#elif CEU_COMPILER_VERSION == 1700
#define VISUAL_STUDIO_VER "11 (2012)"
#elif CEU_COMPILER_VERSION == 1800
#define VISUAL_STUDIO_VER "12 (2013)"
#elif CEU_COMPILER_VERSION == 1900
#define VISUAL_STUDIO_VER "14 (2015)"
#elif CEU_COMPILER_VERSION == 1910
#define VISUAL_STUDIO_VER "15 (2017 Update 1 & 2)"
#elif CEU_COMPILER_VERSION == 1911
#define VISUAL_STUDIO_VER "15 (2017 Update 3 & 4)"
#elif CEU_COMPILER_VERSION == 1912
#define VISUAL_STUDIO_VER "15 (2017 Update 5)"
#elif CEU_COMPILER_VERSION == 1913
#define VISUAL_STUDIO_VER "15 (2017 Update 6)"
#elif CEU_COMPILER_VERSION == 1914
#define VISUAL_STUDIO_VER "15 (2017 Update 7)"
#elif CEU_COMPILER_VERSION == 1915
#define VISUAL_STUDIO_VER "15 (2017 Update 8)"
#elif CEU_COMPILER_VERSION == 1916
#define VISUAL_STUDIO_VER "15 (2017 Update 9)"
#elif CEU_COMPILER_VERSION == 1920
#define VISUAL_STUDIO_VER "16 (2019 RTW)"
#elif CEU_COMPILER_VERSION == 1921
#define VISUAL_STUDIO_VER "16 (2019 Update 1)"
#elif CEU_COMPILER_VERSION == 1922
#define VISUAL_STUDIO_VER "16 (2019 Update 2)"
#elif CEU_COMPILER_VERSION == 1923
#define VISUAL_STUDIO_VER "16 (2019 Update 3)"
#elif CEU_COMPILER_VERSION == 1924
#define VISUAL_STUDIO_VER "16 (2019 Update 4)"
#elif CEU_COMPILER_VERSION == 1925
#define VISUAL_STUDIO_VER "16 (2019 Update 5)"
#elif CEU_COMPILER_VERSION == 1926
#define VISUAL_STUDIO_VER "16 (2019 Update 6)"
#elif CEU_COMPILER_VERSION == 1927
#define VISUAL_STUDIO_VER "16 (2019 Update 7)"
#elif CEU_COMPILER_VERSION == 1928
#define VISUAL_STUDIO_VER "16 (2019 Update 8 & 9)"
#elif CEU_COMPILER_VERSION == 1929
#define VISUAL_STUDIO_VER "16 (2019 Update 10 & 11)"
#elif CEU_COMPILER_VERSION == 1930
#define VISUAL_STUDIO_VER "17 (2022 RTW)"
#elif CEU_COMPILER_VERSION == 1931
#define VISUAL_STUDIO_VER "17.1 (2022)"
#elif CEU_COMPILER_VERSION == 1932
#define VISUAL_STUDIO_VER "17.2 (2022)"
#elif CEU_COMPILER_VERSION == 1933
#define VISUAL_STUDIO_VER "17.3 (2022)"
#elif CEU_COMPILER_VERSION == 1934
#define VISUAL_STUDIO_VER "17.4 (2022)"
#elif CEU_COMPILER_VERSION == 1935
#define VISUAL_STUDIO_VER "17.5 (2022)"
#elif CEU_COMPILER_VERSION > 1935
#define VISUAL_STUDIO_VER "unknown later than 17.5 (2022)"
#else
#define VISUAL_STUDIO_VER "unknown"
#endif

static inline char *interpret_compiler_version_number()
{
	char *buff = (char *)ceu_scalloc(sizeof(char), 256);
	int retv;
	int msv_major_version = CEU_COMPILER_VERSION / 100;
	int msc_minor_version = CEU_COMPILER_VERSION % 100;
#ifdef _MSC_FULL_VER
	retv = snprintf(buff, 256, "%d.%d, with Visual Studio ver. %s (_MSC_VER=%d, _MSC_FULL_VER=%d)", msv_major_version, msc_minor_version, VISUAL_STUDIO_VER, _MSC_VER, _MSC_FULL_VER);
#else
	retv = snprintf(buff, 256, "%d.%d, with Visual Studio ver. %s (_MSC_VER=%d, _MSC_FULL_VER=UNKNOWN)", msv_major_version, msc_minor_version, VISUAL_STUDIO_VER, _MSC_VER);
#endif
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#endif
