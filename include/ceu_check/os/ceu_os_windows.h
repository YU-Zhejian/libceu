/*****************************************************************//**
 * @file   ceu_os_winsows.h
 * @brief  Check whether CEU is compiled on some Microsoft Windows, including CYGWin/MSYS2/MinGW.
 * 
 * @author YU Zhejian
 * @date   May 2024
 *********************************************************************/

#ifndef CEU_OS_WINDOWS_H
#define CEU_OS_WINDOWS_H


#ifndef CEU_CHECK_OS_H
#error "Do not include this file, include <ceu_check/ceu_check_os.h> instead!"
#endif


 /**
  *@def CEU_ON_MSYS
  *@brief Indicating CEU is compiled on MSYS
  */
#if defined(__MSYS__)
#define CEU_PRIMARY_OS_TYPE "MSYS"

#define CEU_ON_MSYS
#endif

  /**
   *@def CEU_ON_CYGWIN
   *@brief Indicating CEU is compiled on CYGWin.
   */

#if defined(__CYGWIN__)
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "CYGWIN"
#endif
#define CEU_ON_CYGWIN
#endif

   /**
	*@def CEU_ON_MINGW32
	*@brief Indicating CEU is compiled on MinGW 32.
	*/

#if defined(__MINGW32__) || defined(__WINNT__) || defined(__WINNT)
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "MINGW32"
#endif
#define CEU_ON_MINGW32
#endif

	/**
	 *@def CEU_ON_CYGWIN_LIKE
	 *@brief Indicating CEU is compiled on CygWin/MSYS/MinGW or friends.
	 */

#if defined(CEU_ON_CYGWIN) || defined(CEU_ON_MINGW32) || defined(CEU_ON_MSYS)
#define CEU_ON_CYGWIN_LIKE
#endif


 /**
  *@def CEU_ON_WINDOWS_64
  *@brief Indicating CEU is compiled on 64-bit Microsoft Windows.
  */
  /**
   *@def CEU_ON_WINDOWS_32
   *@brief Indicating CEU is compiled on 32-bit Microsoft Windows.
   */

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
#define CEU_ON_WINDOWS_64
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 64"
#endif
#elif (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__))
#define CEU_ON_WINDOWS_32
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows 32"
#endif
#endif

   /**
	*@def CEU_ON_WINDOWS
	*@brief Indicating CEU is compiled on Microsoft Windows.
	*/

#if defined(CEU_ON_WINDOWS_32) || defined(CEU_ON_WINDOWS_64)
#define CEU_ON_WINDOWS
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Microsoft Windows"
#endif
#endif


#endif
