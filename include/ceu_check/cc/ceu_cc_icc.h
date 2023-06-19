/**
 * Old Intel C/C++ compiler called ICC/ICPC
 */

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define CEU_COMPILER_IS_ICC
#ifdef __llvm__
#define CEU_COMPILER_NAME "ICC"
#else
#define CEU_COMPILER_NAME "ICC with LLVM features"
#endif
#ifdef __INTEL_COMPILER_UPDATE
#define CEU_COMPILER_VERSION __ICC * 100 + __INTEL_COMPILER_UPDATE
#else
#define CEU_COMPILER_VERSION __ICC * 100
#endif
#endif
