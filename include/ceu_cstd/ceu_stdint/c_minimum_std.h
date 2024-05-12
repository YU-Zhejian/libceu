#ifndef CEU_C_MINIMUM_STD_H
#define CEU_C_MINIMUM_STD_H

#ifndef CEU_STDINT_H
#error "Do not include this file, include <ceu_check/ceu_stdint.h> instead!"
#endif

#if defined(CEU_CM_TYPE_C_SIZE) && defined(CEU_CM_TYPE_SH_SIZE) && defined(CEU_CM_TYPE_I_SIZE) && defined(CEU_CM_TYPE_L_SIZE) && defined(CEU_CM_TYPE_LL_SIZE)
// Comfort C minimum std
#else
#error "Requires definition of CEU_CM_TYPE_C_SIZE, CEU_CM_TYPE_SH_SIZE, CEU_CM_TYPE_I_SIZE, CEU_CM_TYPE_L_SIZE, CEU_CM_TYPE_LL_SIZE cmake/xmake/autotools systems."
#endif

#if (CEU_CM_TYPE_C_SIZE <= CEU_CM_TYPE_SH_SIZE && CEU_CM_TYPE_SH_SIZE <= CEU_CM_TYPE_I_SIZE && CEU_CM_TYPE_I_SIZE <= CEU_CM_TYPE_L_SIZE && CEU_CM_TYPE_L_SIZE <= CEU_CM_TYPE_LL_SIZE)
// Comfort C minimum std
#else
#error "The current C/C++ compiler does not follow basic C standard! Requrie: sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)"
#endif

#if (1 <= CEU_CM_TYPE_C_SIZE && 2 <= CEU_CM_TYPE_SH_SIZE && 2 <= CEU_CM_TYPE_I_SIZE && 4 <= CEU_CM_TYPE_L_SIZE && 8 <= CEU_CM_TYPE_LL_SIZE)
// Comfort C minimum std
#else
#error "The current C/C++ compiler does not follow basic C standard! Requrie: 1 <= sizeof(char); 2 <= sizeof(short); 2 <= sizeof(int); 4 <= sizeof(long); 8 <= sizeof(long long)"
#endif

#endif //CEU_C_MINIMUM_STD_H
