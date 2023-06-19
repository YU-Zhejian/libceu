/*
 * Original LLVM Clang
 */
#if (defined(__clang__) || defined(__llvm__)) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_CLANG
#if defined(__INTEL_CLANG_COMPILER) || defined(__INTEL_LLVM_COMPILER)
#define CEU_COMPILER_NAME "Intel Clang"
#else
#define CEU_COMPILER_NAME "Clang"
#endif
#ifdef __clang_major__
#define CEU_COMPILER_VERSION __clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__
#else
#define CEU_COMPILER_VERSION 0
#endif
#endif
