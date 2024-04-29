#ifndef CEU_YSTRLIB_CONCAT_H
#define CEU_YSTRLIB_CONCAT_H
#include <ceu_ystrlib/ceu_ystrlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void ceu_ystr_cstr_concat_inplace(ceu_ystr_t* ystr, const char* cstr);

void ceu_ystr_concat_inplace(ceu_ystr_t* ystr, const ceu_ystr_t* ystr2);

ceu_ystr_t* ceu_ystr_cstr_concat_const(const ceu_ystr_t* ystr, const char* cstr);

ceu_ystr_t* ceu_ystr_concat_const(const ceu_ystr_t* ystr, const ceu_ystr_t* ystr2);

#ifdef __cplusplus
}
#endif
#endif // CEU_YSTRLIB_CONCAT_H
