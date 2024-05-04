#ifndef CEU_CHECK_HELPERS_H
#define CEU_CHECK_HELPERS_H
#include "ceu_cstd/ceu_stdint.h"
#include "ceu_ystrlib/ceu_ystrlib.h"

ceu_ystr_t* convert_version_to_ystr3(ceu_uint64_t ver1, ceu_uint64_t ver2, ceu_uint64_t ver3);
ceu_ystr_t* convert_version_to_ystr2(ceu_uint64_t ver1, ceu_uint64_t ver2);
#endif
