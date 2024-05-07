/*!
 * @file ceu_check_c_cxx_std.h
 * @brief Check Compile-Time C/C++ standard.
 */

/*!
 * @def CEU_CXX_STD
 * @brief The C++ Standard in a human-readable way. This macro is always defined.
 */

/*!
 * @def CEU_CXX_STD_VERSION_MACRO
 * @brief The C++ Standard version macro, should be equal to `_MSVC_LANG` or `__cplusplus__` or undefined.
 */

/*!
 * @def CEU_C_STD
 * @brief The C Standard in a human-readable way. This macro is always defined.
 */

/*!
 * @def CEU_C_STD_VERSION_MACRO
 * @brief The C Standard version macro, should be equal to `__STDC_VERSION__` or undefined.
 */

#ifndef CEU_CHECK_C_CXX_STD_H
#define CEU_CHECK_C_CXX_STD_H
#include <ceu_ystrlib/ceu_ystrlib.h>
#include <ceu_check/ceu_check_c_cxx_std_macro.h>
#include <ceu_basic/ceu_fast_macros.h>

CEU_BEGIN_C_DECLS
/*!
 * @brief Get a nicely formatted compile-time C standard version number.
 */
ceu_ystr_t* ceu_interpret_c_std_version CEU_PARAMS((void));
/*!
 * @brief Get a nicely formatted compile-time CXX standard version number.
 */
ceu_ystr_t* ceu_interpret_cxx_std_version CEU_PARAMS((void));

CEU_END_C_DECLS
#endif // CEU_CHECK_C_CXX_STD_H
