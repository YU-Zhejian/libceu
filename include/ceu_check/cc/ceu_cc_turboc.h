/*
 * Borland C/C++
 *
 * Version: 0xVRR : V = Version, RR = Revision
 *
 * Example: 0x551 = Borland C++ 5.51
 *
 * See: <https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Compiler_Versions>
 */
#include <string.h>

#if defined(__BORLANDC__) || defined(__CODEGEARC__) || defined(__BCPLUSPLUS__) || defined(__TCPLUSPLUS__) || defined(__TURBOC__)
#define CEU_COMPILER_IS_BORLAND
#if defined(__BORLANDC__)
#define CEU_COMPILER_VERSION __BORLANDC__
#else
#define CEU_COMPILER_VERSION 0
#endif
#if defined(__clang__)
#define CEU_COMPILER_NAME "Borland"
#else
#define CEU_COMPILER_NAME "Borland with Clang support"
#endif

static inline bool check_compiler_version(int major, int minor, int patchlevel)
{
   return major * 256 + minor / 10 * 16 + minor % 10 < CEU_COMPILER_VERSION;
}
static inline char *interpret_compiler_version_number()
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
#endif
