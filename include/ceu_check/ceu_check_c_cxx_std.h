/*!
@file ceu_check_c_cxx_std.h
@brief Check Compile-Time C/C++ standard.
*/

/*!
@def CEU_CXX_STD
@brief The C++ Standard in a human-readable way.
*/

/*!
@def CEU_CXX_STD_VERSION_MACRO
@brief The C++ Standard version macro, should be equal to `_MSVC_LANG` or `__cplusplus__` or undefined.
*/

/*!
@def CEU_C_STD
@brief The C Standard in a human-readable way.
*/

/*!
@def CEU_C_STD_VERSION_MACRO
@brief The C Standard version macro, should be equal to `__STDC_VERSION__` or undefined.
*/

#ifndef CEU_CHECK_C_CXX_STD_H
#define CEU_CHECK_C_CXX_STD_H
#include "ceu_ystrlib/ceu_ystrlib.h"

#undef CEU_CXX_STD_VERSION_MACRO
#if defined(_MSVC_LANG)
#define CEU_CXX_STD_VERSION_MACRO _MSVC_LANG
#elif defined(__cplusplus)
#define CEU_CXX_STD_VERSION_MACRO __cplusplus
#endif

#ifndef CEU_CXX_STD_VERSION_MACRO
#define CEU_CXX_STD "UNDEFINED"
#elif CEU_CXX_STD_VERSION_MACRO == -2
#define CEU_CXX_STD "UNKNOWN"
#elif CEU_CXX_STD_VERSION_MACRO < 199711L
#define CEU_CXX_STD "pre-98"
#elif CEU_CXX_STD_VERSION_MACRO >= 202100L
#define CEU_CXX_STD "post-23"
#elif CEU_CXX_STD_VERSION_MACRO == 202100L
#define CEU_CXX_STD "23"
#elif CEU_CXX_STD_VERSION_MACRO == 202002L
#define CEU_CXX_STD "20"
#elif CEU_CXX_STD_VERSION_MACRO == 201703L
#define CEU_CXX_STD "17"
#elif CEU_CXX_STD_VERSION_MACRO == 201402L
#define CEU_CXX_STD "14"
#elif CEU_CXX_STD_VERSION_MACRO == 201103L
#define CEU_CXX_STD "11"
#elif CEU_CXX_STD_VERSION_MACRO == 199711L
#define CEU_CXX_STD "98"
#endif

#undef CEU_C_STD_MACRO
#if (!defined __STDC_VERSION__)
#else
#define CEU_C_STD_MACRO __STDC_VERSION__
#endif

#ifndef CEU_C_STD_MACRO
#define CEU_C_STD "UNDEFINED"
#elif CEU_C_STD_MACRO < 199409L
#define CEU_C_STD "pre-94"
#elif CEU_C_STD_MACRO == 199409L
#define CEU_C_STD "94"
#elif CEU_C_STD_MACRO == 199901L
#define CEU_C_STD "99"
#elif CEU_C_STD_MACRO == 201112L
#define CEU_C_STD "11"
#elif CEU_C_STD_MACRO == 201710L
#define CEU_C_STD "17"
#elif CEU_C_STD_MACRO > 201710L
#define CEU_C_STD "post-17"
#else
#define CEU_C_STD "unknown"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Get a nicely formatted compile-time C standard version number.
 */
ceu_ystr_t* ceu_interpret_c_std_version(void);
/*!
 * @brief Get a nicely formatted compile-time CXX standard version number.
 */
ceu_ystr_t* ceu_interpret_cxx_std_version(void);

#ifdef __cplusplus
}
#endif
#endif // CEU_CHECK_C_CXX_STD_H
