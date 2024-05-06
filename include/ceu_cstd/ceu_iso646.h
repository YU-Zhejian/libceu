/*!
 * @file ceu_iso646.h
 * @author YU Zhejian
 * @brief POSIX-compiliant iso646.h
 * @version 0.1
 * @date 2024-05-06
 *
 * @see [cppreference description of `iso646.h`](https://en.cppreference.com/w/c/language/operator_alternative).
 * @see [POSIX.1 2018 description of `iso646.h`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/iso646.h.html).
 */

#ifndef CEU_ISO646_H
#define CEU_ISO646_H

#ifdef __cplusplus
#else
#define and &&
#define and_eq &=
#define bitand &
#define bitor |
#define compl ~
#define not !
#define not_eq !=
#define or ||
#define or_eq |=
#define xor ^
#define xor_eq ^=
#endif

#endif
