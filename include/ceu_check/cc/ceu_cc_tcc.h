#include <string.h>

#if defined(__TINYC__)
#define CEU_COMPILER_IS_TINYCC
#define CEU_COMPILER_VERSION __TINYC__
#define CEU_COMPILER_NAME "Tiny C Compiler"

static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major < CEU_COMPILER_VERSION;
}
static inline char *interpret_compiler_version_number()
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
#endif
