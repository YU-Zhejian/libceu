/*!
@file nvhpc.h
@brief For NVidia HPC (NVHPC) Toolkit NVC++
*/
#include <string.h>

#if defined(__NVCOMPILER_MAJOR__)
#define CEU_COMPILER_IS_NVHPC
#define CEU_COMPILER_NAME "NVidia High Performance Computing (NVHPC) Toolkit NVC++"
#endif
