/*****************************************************************//**
 * @file   ceu_os_mainframe_unix.h
 * @brief  Check whether CEU is compiled on Mainframe UNIX including Solaris, AIX and HU-UX.
 * 
 * @author YU Zhejian
 * @date   May 2024
 *********************************************************************/

#ifndef CEU_OS_MAINFRAME_UNIX_H
#define CEU_OS_MAINFRAME_UNIX_H


#ifndef CEU_CHECK_OS_H
#error "Do not include this file, include <ceu_check/ceu_check_os.h> instead!"
#endif


/**
 *@def CEU_ON_SOLARIS
 *@brief Indicating CEU is compiled on Solaris.
 */
#if defined(__sun) && defined(__SVR4)
#define CEU_ON_SOLARIS
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "Solaris"
#endif
#endif


 /**
  *@def CEU_ON_HP_UX
  *@brief Indicating CEU is compiled on HP-UX.
  */

#if defined(__hpux)
#define CEU_ON_HP_UX
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "HP-UX"
#endif
#endif

  /**
   *@def CEU_ON_AIX
   *@brief Indicating CEU is compiled on IBM AIX.
   */
#if defined(_AIX)
#define CEU_ON_AIX
#ifndef CEU_PRIMARY_OS_TYPE
#define CEU_PRIMARY_OS_TYPE "IBM AIX"
#endif
#endif


#endif
