#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/libceu.h"
#include "ceu_check/ceu_check_c_cxx_std.h"
#include "ceu_check/ceu_check_cc.h"
#include "ceu_check/ceu_check_ctypes_limit.h"
#include "ceu_check/ceu_check_os.h"
#include "ceu_ystrlib/ceu_ystrlib_all.h"

ceu_ystr_t* ceu_lib_ver(void)
{
    ceu_ystr_t* rets = ceu_ystr_create_from_cstr_guarantee("LibCEU: ", 128);
    ceu_ystr_t* libceu_rtime_version_buff = ceu_lib_rtime_version();
    ceu_ystr_cstr_concat_inplace(rets, CEU_LIB_CTIME_VERSION);
    ceu_ystr_cstr_concat_inplace(rets, " (compile time) ");
    ceu_ystr_concat_inplace(rets, libceu_rtime_version_buff);
    ceu_ystr_destroy(libceu_rtime_version_buff);
    ceu_ystr_cstr_concat_inplace(rets, " (run time)");
    return rets;
}

ceu_ystr_t* ceu_check_get_full_info(void)
{
    ceu_ystr_t* libceu_version_buff = ceu_lib_ver();
    ceu_ystr_t* c_info_buff = ceu_interpret_c_std_version();
    ceu_ystr_t* cxx_info_buff = ceu_interpret_cxx_std_version();
    ceu_ystr_t* compiler_info_buff = ceu_check_get_compiler_info();
    ceu_ystr_t* compile_time_os_info = ceu_check_get_compile_time_os_info();
    ceu_ystr_t* run_time_os_info = ceu_check_get_run_time_os_info();
    ceu_ystr_t* compile_time_ctypes_info = ceu_check_get_ctypes_limit_info();
    ceu_ystr_t* sep = ceu_ystr_create_from_cstr("\n");

    ceu_ystr_t* retbuff = ceu_ystr_join(sep, ceu_true, 7, libceu_version_buff, compiler_info_buff, c_info_buff,
        cxx_info_buff, compile_time_os_info, run_time_os_info, compile_time_ctypes_info);
    ceu_ystr_destroy(libceu_version_buff);
    ceu_ystr_destroy(compiler_info_buff);
    ceu_ystr_destroy(c_info_buff);
    ceu_ystr_destroy(cxx_info_buff);
    ceu_ystr_destroy(compile_time_os_info);
    ceu_ystr_destroy(run_time_os_info);
    ceu_ystr_destroy(compile_time_ctypes_info);
    return retbuff;
}
