#include "ceu_check/ceu_check_cc.h"

#if !(defined(CEU_COMPILER_IS_GCC) || defined(CEU_COMPILER_IS_CLANG))
#define __attribute__(x)
#endif
