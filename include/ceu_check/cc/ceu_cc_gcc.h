/*!
 * @brief GNU GCC and G++
 */
#if defined(__GNUC__)
#define CEU_COMPILER_IS_GCC
#if !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_NAME "GCC"
#endif
#endif
