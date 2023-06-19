/**
 * For unknown ones
 */
#include <string.h>
#include <stdbool.h>

#ifndef CEU_COMPILER_NAME
#define CEU_COMPILER_NAME "unknown"
#define CEU_COMPILER_IS_UNKNOWN
#endif
#ifndef CEU_COMPILER_VERSION
#define CEU_COMPILER_VERSION -1

static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
	return true;
}
static inline char *interpret_compiler_version_number()
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