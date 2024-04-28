//
// Created by yuzj on 24-4-28.
//

#ifndef CEU_YSTRLIB_CONCAT_H
#define CEU_YSTRLIB_CONCAT_H
#include <ceu_ystrlib/ceu_ystrlib.h>

void ceu_ystr_cstr_concat_inplace(ceu_ystr_t* ystr, const char* cstr);

void ceu_ystr_concat_inplace(ceu_ystr_t* ystr, const ceu_ystr_t* ystr2);

ceu_ystr_t* ceu_ystr_cstr_concat_const(const ceu_ystr_t* ystr, const char* cstr);

ceu_ystr_t* ceu_ystr_concat_const(const ceu_ystr_t* ystr, const ceu_ystr_t* ystr2);

#endif // CEU_YSTRLIB_CONCAT_H
