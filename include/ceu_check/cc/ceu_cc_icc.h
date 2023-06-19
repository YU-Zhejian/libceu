/**
 * Old Intel C/C++ compiler called ICC/ICPC
 */
#include <string.h>

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define CEU_COMPILER_IS_ICC
#ifdef __llvm__
#define CEU_COMPILER_NAME "ICC"
#else
#define CEU_COMPILER_NAME "ICC with LLVM features"
#endif
#ifdef __INTEL_COMPILER_UPDATE
#define CEU_COMPILER_VERSION __ICC * 100 + __INTEL_COMPILER_UPDATE
#else
#define CEU_COMPILER_VERSION __ICC * 100
#endif
static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major * 100 + minor < CEU_COMPILER_VERSION;
}
static inline char *interpret_compiler_version_number()
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

#endif