//
// Created by yuzj on 1/15/22.
//

#ifndef CPPTETGS_EXPERIMENTAL_UTILS_H
#define CPPTETGS_EXPERIMENTAL_UTILS_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ceu_check/ceu_c_utils.h"
#include "ceu_check/ceu_check_os.h"
#include "ceu_check/ceu_check_cc.h"
#include "ceu_check/ceu_check_ctypes_limit.h"

#ifdef __cplusplus
#include "ceu_check/ceu_check_cxx_std.hpp"
#else

#include "ceu_check/ceu_check_c_std.h"

#endif


// #include "ceu_check/ceu_check_resource_limit.h"


static inline char* get_full_info()
{
	char* compiler_info_buff = get_compiler_info();
#ifdef __cplusplus
	char* c_cxx_info_buff = get_cxx_info();
#else
	char* c_cxx_info_buff = get_c_info();
#endif
	char* compile_time_os_info = get_compile_time_os_info();
	char* run_time_os_info = get_run_time_os_info();
	char* compile_time_ctypes_info = get_ctypes_limit_info();
	char* retbuff = ceu_str_join_with_sep(
			"\n",
			CEU_STR_JOIN_SKIP,
			5,
			compiler_info_buff,
			c_cxx_info_buff,
			compile_time_os_info,
			run_time_os_info,
			compile_time_ctypes_info
	);
	ceu_free_non_null(compiler_info_buff);
	ceu_free_non_null(c_cxx_info_buff);
	ceu_free_non_null(compile_time_os_info);
	ceu_free_non_null(run_time_os_info);
	ceu_free_non_null(compile_time_ctypes_info);
	return retbuff;
}

#ifdef __cplusplus
}
#endif
#endif //CPPTETGS_EXPERIMENTAL_UTILS_H
