/*!
 * @brief Get compile-time C standard.
 */
#ifndef CEU_CHECK_C_STD_H
#define CEU_CHECK_C_STD_H

#define CEU_C_STD_LATEST 17

#if (!defined __STDC_VERSION__)
#define CEU_C_STD_MACRO 0
#else
#define CEU_C_STD_MACRO __STDC_VERSION__
#endif

#if  CEU_C_STD_MACRO < 199409L
#define CEU_C_STD "pre-94"
#elif CEU_C_STD_MACRO == 199409L
#define CEU_C_STD "94"
#elif CEU_C_STD_MACRO == 199901L
#define CEU_C_STD "99"
#elif CEU_C_STD_MACRO == 201112L
#define CEU_C_STD "11"
#elif CEU_C_STD_MACRO == 201710L
#define CEU_C_STD "17"
#else
#define CEU_C_STD "unknown"
#endif

/**
 * Get compile-time C standard version number.
 */
char* interpret_c_version(void);

/*!
 * @brief Get a nicely formatted compile-time C++ standard version number.
 * @param buff Buffer to write to. This should be at least 1024 bytes long.
 */
char* get_c_info(void);


#endif //CEU_CHECK_C_STD_H
