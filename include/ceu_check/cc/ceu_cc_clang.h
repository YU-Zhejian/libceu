/*
 * Original LLVM Clang
 */
#include <string.h>

#if (defined(__clang__) || defined(__llvm__)) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_CLANG
#if defined(__INTEL_CLANG_COMPILER) || defined(__INTEL_LLVM_COMPILER)
#define CEU_COMPILER_NAME "Intel Clang"
#else
#define CEU_COMPILER_NAME "Clang"
#endif
#ifdef __clang_major__
#define CEU_COMPILER_VERSION __clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__
#else
#define CEU_COMPILER_VERSION 0
#endif

static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return CEU_COMPILER_VERSION >= major * 10000 + minor * 100 + patchlevel;
}
static inline char *interpret_compiler_version_number()
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
#endif
