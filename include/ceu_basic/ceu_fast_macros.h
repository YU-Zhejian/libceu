/*!
 * @file ceu_fast_macros.h
 * @author YU Zhejian
 * @brief Macro functions and constants defined for convenience.
 * @version 0.1
 * @date 2024-05-02
 *
 */
#ifndef CEU_FAST_MACROS_H
#define CEU_FAST_MACROS_H

#define CEU_MAX(a, b) ((a) > (b) ? (a) : (b))
#define CEU_MIN(a, b) ((a) < (b) ? (a) : (b))
#define CEU_STRING_ENDING '\0'

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#endif // CEU_FAST_MACROS_H
