#include <ceu_basic/libceu.h>
#include <ceu_ystrlib/ceu_ystrlib_all.h>

ceu_ystr_t* ceu_lib_rtime_version(void)
{
    return ceu_ystr_create_from_cstr(CEU_LIB_CTIME_VERSION);
}
