#include "ceu_basic/ceu_c_utils.h"
#include "ceu_check/ceu_check_c_cxx_std.h"
#include "ceu_check/ceu_check_cc.h"
#include "ceu_check/ceu_check_ctypes_limit.h"
#include "ceu_check/ceu_check_os.h"
#include "ceu_check/ceu_check_utils.h"
#include "ceu_cstd/ceu_stdio.h"
#include "ceu_basic/libceu.h"

char* ceu_lib_rtime_version(void)
{
    return CEU_LIB_CTIME_VERSION;
}

char* ceu_check_get_full_info(void)
{
    char* libceu_version_buff = (char*)ceu_scalloc(256, sizeof(char));
    char* c_info_buff = ceu_check_get_c_std_info();
    char* cxx_info_buff = ceu_check_get_cxx_std_info();
    char* compiler_info_buff = ceu_check_get_compiler_info();
    char* compile_time_os_info = ceu_check_get_compile_time_os_info();
    char* run_time_os_info = ceu_check_get_run_time_os_info();
    char* compile_time_ctypes_info = ceu_check_get_ctypes_limit_info();
    char* retbuff;

    ceu_snprintf(libceu_version_buff, 256, "LibCEU: %s (compile-time) %s (run-time)", CEU_LIB_CTIME_VERSION,
        ceu_lib_rtime_version());
    retbuff = ceu_str_join_with_sep("\n", CEU_STR_JOIN_SKIP, 7, libceu_version_buff, compiler_info_buff, c_info_buff,
        cxx_info_buff, compile_time_os_info, run_time_os_info, compile_time_ctypes_info);
    ceu_free_non_null(libceu_version_buff);
    ceu_free_non_null(compiler_info_buff);
    ceu_free_non_null(c_info_buff);
    ceu_free_non_null(cxx_info_buff);
    ceu_free_non_null(compile_time_os_info);
    ceu_free_non_null(run_time_os_info);
    ceu_free_non_null(compile_time_ctypes_info);
    return retbuff;
}
