/*!
 * @file libceu.h
 * @author YU Zhejian
 * @brief Compile- and run-timer version detection macros.
 * @version 0.1
 * @date 2024-05-02
 */
#ifndef LIBCEU_CEU_H
#define LIBCEU_CEU_H

/*!
 * @def CEU_LIB_CTIME_VERSION
 * @brief Compile time LibCEU version.
 */
#define CEU_LIB_CTIME_VERSION "0.1"

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <ceu_ystrlib/ceu_ystrlib.h>

/*!
 * @brief Get runtime LiBCEU version.
 * @param  Not accepting any parameters.
 * @return A string with the runtime version. User should free it after use.
 */
ceu_ystr_t* ceu_lib_rtime_version(void);
#ifdef __cplusplus
}
#endif
#endif // LIBCEU_CEU_H
