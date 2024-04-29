/*!
 * @brief Original LLVM Clang
 */
#if (defined(__clang__) || defined(__llvm__))
#define CEU_COMPILER_IS_CLANG
#if !defined(CEU_COMPILER_NAME)
#if defined(__INTEL_CLANG_COMPILER) || defined(__INTEL_LLVM_COMPILER)
#define CEU_COMPILER_NAME "Intel Clang"
#else
#define CEU_COMPILER_NAME "Clang"
#endif
#endif
#endif
