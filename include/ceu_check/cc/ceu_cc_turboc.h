/*!
 * @file ceu_cc_turboc.h
 * @brief Feature detection macros to Borland (now acquired by Embarcadero) C/C++ compiler.
 *
 * Version: 0xVRR : V = Version, RR = Revision
 *
 * Example: 0x551 = Borland C++ 5.51
 *
 * @see https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Compiler_Versions
 * @see https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Predefined_Macros
 */

/*!
 * @def CEU_COMPILER_IS_BORLAND
 * @brief Indicator for Borland C/C++ compilers.
 *
 */
#if defined(__BORLANDC__) || defined(__CODEGEARC__) || defined(__BCPLUSPLUS__) || defined(__TCPLUSPLUS__) || defined(__TURBOC__)
#define CEU_COMPILER_IS_BORLAND
#if defined(__clang__)
#define CEU_COMPILER_NAME "Borland with Clang support"
#else
#define CEU_COMPILER_NAME "Borland"
#endif
#if __TURBOC__ < 0x0570
#define CEU_COMPILER_VERSION "unknown before Developer Studio 2006"
#elif __TURBOC__ == 0x0570
#define CEU_COMPILER_VERSION "Developer Studio 2006"
#elif __TURBOC__ == 0x0590
#define CEU_COMPILER_VERSION "C++Builder 2007"
#elif __TURBOC__ == 0x0591
#define CEU_COMPILER_VERSION "update 1 to C++Builder 2007"
#elif __TURBOC__ == 0x0592
#define CEU_COMPILER_VERSION "RAD Studio 2007"
#elif __TURBOC__ == 0x0593
#define CEU_COMPILER_VERSION "December update to RAD Studio 2007"
#elif __TURBOC__ == 0x0610
#define CEU_COMPILER_VERSION "C++Builder 2009 (with/without Update 1)"
#elif __TURBOC__ == 0x0620
#define CEU_COMPILER_VERSION "C++Builder 2010 (with/without Update 1)"
#elif __TURBOC__ == 0x0621
#define CEU_COMPILER_VERSION "C++Builder 2010 Update 2"
#elif __TURBOC__ == 0x0630
#define CEU_COMPILER_VERSION "C++Builder XE"
#elif __TURBOC__ == 0x0631
#define CEU_COMPILER_VERSION "C++Builder XE Update 1"
#elif __TURBOC__ == 0x0640
#define CEU_COMPILER_VERSION "C++Builder XE2"
#elif __TURBOC__ == 0x0650
#define CEU_COMPILER_VERSION "C++Builder XE3 (with/without Update 1)"
#elif __TURBOC__ == 0x0651
#define CEU_COMPILER_VERSION "C++Builder XE3 January 2013 update"
#elif __TURBOC__ == 0x0660
#define CEU_COMPILER_VERSION "C++Builder XE4"
#elif __TURBOC__ == 0x0670
#define CEU_COMPILER_VERSION "C++Builder XE5"
#elif __TURBOC__ == 0x0680
#define CEU_COMPILER_VERSION "C++Builder XE6"
#elif __TURBOC__ == 0x0690
#define CEU_COMPILER_VERSION "C++Builder XE7"
#elif __TURBOC__ == 0x0700
#define CEU_COMPILER_VERSION "C++Builder XE8"
#elif __TURBOC__ == 0x0710
#define CEU_COMPILER_VERSION "C++Builder Seattle"
#elif __TURBOC__ == 0x0711
#define CEU_COMPILER_VERSION "C++Builder Seattle Subscription Update 1"
#elif __TURBOC__ == 0x0720
#define CEU_COMPILER_VERSION "C++Builder Berlin"
#elif __TURBOC__ == 0x0730
#define CEU_COMPILER_VERSION "C++Builder Tokyo"
#elif __TURBOC__ == 0x0740
#define CEU_COMPILER_VERSION "C++Builder Rio"
#elif __TURBOC__ == 0x0750
#define CEU_COMPILER_VERSION "C++Builder Sydney"
#elif __TURBOC__ == 0x0760
#define CEU_COMPILER_VERSION "C++Builder Alexandria"
#elif __TURBOC__ > 0x0760
#define CEU_COMPILER_VERSION "unknown after C++Builder Alexandria"
#endif
#endif
