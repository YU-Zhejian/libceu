/*
 * GNU GCC and G++
 */
#include <string.h>

#if defined(__GNUC__) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_GCC
#define CEU_COMPILER_NAME "GCC"

#ifdef __GNUC_PATCHLEVEL__
#define CEU_COMPILER_VERSION __GNUC__ * 10000 + __GNUC_MINOR__ * 100
#else
#define CEU_COMPILER_VERSION __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__
#endif

static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
}

static inline char* interpret_compiler_version_number()
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

#endif