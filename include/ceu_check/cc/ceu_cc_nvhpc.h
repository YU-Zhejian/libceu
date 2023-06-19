/*!
@file nvhpc.h
@brief For NVidia HPC (NVHPC) Toolkit NVC++
*/
#include <string.h>

#if defined(__NVCOMPILER_MAJOR__)
#define CEU_COMPILER_IS_NVHPC
#define CEU_COMPILER_VERSION __NVCOMPILER_MAJOR__ * 10000 + __NVCOMPILER_MINOR__ * 100 + __NVCOMPILER_PATCHLEVEL__
#define CEU_COMPILER_NAME "NVidia High Performance Computing (NVHPC) Toolkit NVC++"
static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return major * 10000 + minor * 100 + patchlevel < CEU_COMPILER_VERSION;
}
static inline char *interpret_compiler_version_number()
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
#endif
