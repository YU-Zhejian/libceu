/*
 * GNU GCC and G++
 */
#if defined(__GNUC__) && !defined(CEU_COMPILER_NAME)
#define CEU_COMPILER_IS_GCC
#define CEU_COMPILER_NAME "GCC"

#ifdef __GNUC_PATCHLEVEL__
#define CEU_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#else
#define CEU_COMPILER_VERSION __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__
#endif


#endif
