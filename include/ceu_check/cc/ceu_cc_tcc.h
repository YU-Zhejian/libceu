#include <string.h>

#if defined(__TINYC__)
#define CEU_COMPILER_IS_TINYCC
#define CEU_COMPILER_VERSION __TINYC__
#define CEU_COMPILER_NAME "Tiny C Compiler"
#endif
