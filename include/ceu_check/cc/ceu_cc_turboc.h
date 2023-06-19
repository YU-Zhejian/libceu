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
#endif
