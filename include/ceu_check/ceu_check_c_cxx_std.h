/*!
@file check_cxx_std.hpp
@brief Check Compile-Time C++ standard.
*/

/*!
@def CEU_CXX_STD
@brief The C++ Standard in a human-readable way.
*/

/*!
@def CEU_CXX_STD_VERSION_MACRO
@brief The C++ Standard version.
*/
#ifndef CEU_CHECK_C_CXX_STD_H
#define CEU_CHECK_C_CXX_STD_H

#include "libceu.h"

#if defined(_MSVC_LANG)
#define CEU_CXX_STD_VERSION_MACRO _MSVC_LANG
#elif defined(__cplusplus)
#define CEU_CXX_STD_VERSION_MACRO __cplusplus
#else
#define CEU_CXX_STD_VERSION_MACRO (-2)
#endif

/*!
Latest supported C++ Standard Verison.
*/
#define CEU_CXX_STD_LATEST 23

#if CEU_CXX_STD_VERSION_MACRO == -2
#define CEU_CXX_STD (-2)
#elif CEU_CXX_STD_VERSION_MACRO < 199711L
#define CEU_CXX_STD 0
#elif CEU_CXX_STD_VERSION_MACRO >= 202100L
#define CEU_CXX_STD 23
#elif CEU_CXX_STD_VERSION_MACRO >= 202002L
#define CEU_CXX_STD 20
#elif CEU_CXX_STD_VERSION_MACRO >= 201703L
#define CEU_CXX_STD 17
#elif CEU_CXX_STD_VERSION_MACRO >= 201402L
#define CEU_CXX_STD 14
#elif CEU_CXX_STD_VERSION_MACRO >= 201103L
#define CEU_CXX_STD 11
#elif CEU_CXX_STD_VERSION_MACRO >= 199711L
#define CEU_CXX_STD 98
#endif


#define CEU_C_STD_LATEST 17

#if (!defined __STDC_VERSION__)
#define CEU_C_STD_MACRO 0
#else
#define CEU_C_STD_MACRO __STDC_VERSION__
#endif

#if  CEU_C_STD_MACRO < 199409L
#define CEU_C_STD "pre-94"
#elif CEU_C_STD_MACRO == 199409L
#define CEU_C_STD "94"
#elif CEU_C_STD_MACRO == 199901L
#define CEU_C_STD "99"
#elif CEU_C_STD_MACRO == 201112L
#define CEU_C_STD "11"
#elif CEU_C_STD_MACRO == 201710L
#define CEU_C_STD "17"
#else
#define CEU_C_STD "unknown"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Get compile-time C standard version number.
 */
char *ceu_interpret_c_std_version(void);

/*!
 * @brief Get a nicely formatted compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 1024 bytes long.
 */
char *ceu_check_get_c_std_info(void);

/*!
 * @fn interpret_cxx_version
 * @brief Get compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 256 bytes long.
 */
char *ceu_interpret_cxx_std_version(void);

/*!
 * @brief Get a nicely formatted compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 1024 bytes long.
 */
char *ceu_check_get_cxx_std_info(void);

#ifdef __cplusplus
}
#endif
#endif // CEU_CHECK_C_CXX_STD_H
