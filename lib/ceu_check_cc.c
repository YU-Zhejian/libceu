#include <stdio.h>
#include <stdlib.h>

#include "ceu_check/ceu_check_cc.h"

#ifdef __cplusplus
extern "C"
{
#endif

char* interpret_compilation_date_time(void)
{
	int retv;
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
#if defined(__DATE__) && defined(__TIME__)
	retv = snprintf(buff, 256, "%s, %s", __DATE__, __TIME__);
#elif defined(__DATE__)
	retv = snprintf(buff, 256, "%s, unknown time", __DATE__);
#else
	retv = snprintf(buff, 256, "unknown date & time");
#endif
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

char* get_compiler_info(void)
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 1024);
	int retv;
	char* date_time_buff = interpret_compilation_date_time();
	if (date_time_buff == NULL)
	{
		return NULL;
	}
	char* compiler_version_buff = interpret_compiler_version_number();
	if (compiler_version_buff == NULL)
	{
		free(date_time_buff);
		return NULL;
	}

	retv = snprintf(buff, 1024, "Compiled at %s with compiler '%s' ver. '%s'", date_time_buff, CEU_COMPILER_NAME,
			compiler_version_buff);
	free(date_time_buff);
	free(compiler_version_buff);
	if (retv < 0)
	{
		return NULL;
	}
	return buff;
}

#if defined(CEU_COMPILER_IS_CLANG)
bool check_compiler_version(int major, int minor, int patchlevel)
{
	return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
}
char *interpret_compiler_version_number()
{
	int retv;
	char *buff = (char *)scalloc(sizeof(char), 256);
	if (CEU_COMPILER_VERSION != 0)
	{
		retv = snprintf(buff, 256, "%d.%d.%d", __clang_major__, __clang_minor__, __clang_patchlevel__);
	}
	else
	{
		retv = snprintf(buff, 256, "unknown");
	}
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#elif defined(CEU_COMPILER_IS_GCC)

bool check_compiler_version(int major, int minor, int patchlevel)
{
	return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
}

char* interpret_compiler_version_number(void)
{
	char* buff = (char*)ceu_scalloc(sizeof(char), 256);
	int retv;
#ifdef __GNUC_PATCHLEVEL__
	retv = snprintf(buff, 256, "%d.%d.%d", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else
	retv = snprintf(buff, 256, "%d.%d", __GNUC__, __GNUC_MINOR__);
#endif
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}

#elif defined(CEU_COMPILER_IS_ICC)
bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major * 100 + minor < CEU_COMPILER_VERSION;
}
char *interpret_compiler_version_number()
{
	char *buff = (char *)scalloc(sizeof(char), 256);
	int retv;
#ifdef __INTEL_COMPILER_UPDATE
	retv = snprintf(buff, 256, "%d.%d", __ICC, __INTEL_COMPILER_UPDATE);
#else
	retv = snprintf(buff, 256, "%d", __ICC);
#endif
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#elif defined(CEU_COMPILER_IS_MSVC)
char *interpret_compiler_version_number()
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
#elif defined(CEU_COMPILER_IS_NVHPC)
bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major * 10000 + minor * 100 + patchlevel < CEU_COMPILER_VERSION;
}
char *interpret_compiler_version_number()
{
	char *buff = (char *)scalloc(sizeof(char), 256);
	int retv;
	retv = snprintf(buff, 256, "%d.%d.%d", __NVCOMPILER_MAJOR__, __NVCOMPILER_MINOR__, __NVCOMPILER_PATCHLEVEL__);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#elif defined(CEU_COMPILER_IS_TINYCC)
bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major < CEU_COMPILER_VERSION;
}
char *interpret_compiler_version_number()
{
	char *buff = (char *)scalloc(sizeof(char), 256);
	int retv;
	int major = __TCC__ / 10000;
	int minor = (__TCC__ - major * 10000) / 100;
	int patchlevel = __TCC__ % 100;
	retv = snprintf(buff, 256, "%d.%d.%d", major, minor, patchlevel);
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#elif defined(CEU_COMPILER_IS_BORLAND)
bool check_compiler_version(int major, int minor, int patchlevel)
{
   return major * 256 + minor / 10 * 16 + minor % 10 < CEU_COMPILER_VERSION;
}
char *interpret_compiler_version_number()
{
   char *buff = (char *)scalloc(sizeof(char), 256);
   int retv;
   int major = __BORLANDC__ / 256;
   int revision = (__BORLANDC__ - 256 * major) / 16 + __BORLANDC__ % 16;
   retv = snprintf(buff, 256, "%d.%d", major, revision);
   if (retv < 0)
   {
		free(buff);
		return NULL;
   }
   return buff;
}
#else
bool check_compiler_version(int major, int minor, int patchlevel)
{
	return true;
}
char *interpret_compiler_version_number()
{
	char *buff = (char *)scalloc(sizeof(char), 256);
	int retv;
	retv = snprintf(buff, 256, "unknown");
	if (retv < 0)
	{
		free(buff);
		return NULL;
	}
	return buff;
}
#endif

#ifdef __cplusplus
}
#endif
