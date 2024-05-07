#ifndef CEU_YSTRLIB_CONCAT_H
#define CEU_YSTRLIB_CONCAT_H
#include <ceu_cstd/ceu_stdbool.h>
#include <ceu_ystrlib/ceu_ystrlib.h>
#include <ceu_basic/ceu_fast_macros.h>

CEU_BEGIN_C_DECLS

void ceu_ystr_cstr_concat_inplace CEU_PARAMS((ceu_ystr_t* ystr, const char* cstr));

void ceu_ystr_concat_inplace CEU_PARAMS((ceu_ystr_t* ystr, const ceu_ystr_t* ystr2));

ceu_ystr_t* ceu_ystr_cstr_concat_const CEU_PARAMS((const ceu_ystr_t* ystr, const char* cstr));

ceu_ystr_t* ceu_ystr_concat_const CEU_PARAMS((const ceu_ystr_t* ystr, const ceu_ystr_t* ystr2));

ceu_ystr_t* ceu_ystr_join CEU_PARAMS((const ceu_ystr_t* sep, bool skip_null, ceu_size_t count, ...));
ceu_ystr_t* ceu_ystr_cstr_join CEU_PARAMS((const char* sep, bool skip_null, ceu_size_t count, ...));

CEU_END_C_DECLS

#endif // CEU_YSTRLIB_CONCAT_H
