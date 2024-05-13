/*!
 * @file libceu_stddef_dispatcher.h
 * @author YU Zhejian
 * @brief Dispatcher for inclusion of correct build-system-created header files.
 * @version 0.1
 * @date 2024-05-13
 *
 * This header would include correct build-system-created header files for build systems like [CMake](https://cmake.org), [XMake](https://xmake.io) and [GNU Autotools](https://www.gnu.org/software/autoconf). If a build system is not detected, a default header file will be included.
 *
 */
#ifndef CEU_STDDEF_DISPATCHER_H
#define CEU_STDDEF_DISPATCHER_H

#if defined(CEU_CM_UNDER_CMAKE)
#include "ceu_basic/libceu_stddef_cmake.h"
#elif defined(CEU_CM_UNDER_XMAKE)
#include "ceu_basic/libceu_stddef_xmake.h"
#endif

#endif // CEU_STDDEF_DISPATCHER_H
