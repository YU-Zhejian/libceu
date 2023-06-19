/**
 * Old Intel C/C++ compiler called ICC/ICPC
 */

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define CEU_COMPILER_IS_ICC
#ifdef __llvm__
#define CEU_COMPILER_NAME "ICC with LLVM features"
#else
#define CEU_COMPILER_NAME "ICC"
#endif
#endif
