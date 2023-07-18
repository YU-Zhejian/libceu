// ORPHAN
#include "ceu_check/ceu_check_os.h"
#include "ceu_check/ceu_check_utils.h"

#ifndef LIBCEU_CHECK_RESOURCE_LIMIT_H
#define LIBCEU_CHECK_RESOURCE_LIMIT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CEU_ON_POSIX

#include <limits.h>
#include <sys/resource.h>
#include <unistd.h>

inline void _ceu_format_posix_rlimit_return(char* buff, int rlimit_macro, const char* rlimit_name,
    const char* rlimit_explain)
{

    struct rlimit rlimit_get;
    getrlimit(rlimit_macro, &rlimit_get);
    append_sprintf(buff, "%s\t%s: SOFT=%d, HARD=%d // %s\n", buff, rlimit_name, rlimit_get.rlim_cur,
        rlimit_get.rlim_max, rlimit_explain);
}

inline void _ceu_format_posix_sysconf_return(char* buff, int posix_limit_macro, const char* posix_limit_name,
    const char* posix_limit_explain)
{
    append_sprintf(buff, "%s\t%s=%d // %s\n", buff, posix_limit_name, sysconf(posix_limit_macro),
        posix_limit_explain);
}

#endif

inline void get_rlimit_info(char* buff)
{
#ifdef CEU_ON_POSIX
    append_sprintf(buff, "%sRun-time System resource limits set by `ulimit` or getrlimit(2):\n", buff);
    _ceu_format_posix_rlimit_return(buff, RLIMIT_AS, "RLIMIT_AS",
        "The maximum size of the process's virtual "
        "memory (address space) in bytes.");
    _ceu_format_posix_rlimit_return(buff, RLIMIT_CORE, "RLIMIT_CORE", "Size limit of core dump files.");
    _ceu_format_posix_rlimit_return(buff, RLIMIT_CPU, "RLIMIT_CPU", "CPU time limit in seconds.");
    _ceu_format_posix_rlimit_return(buff, RLIMIT_DATA, "RLIMIT_DATA",
        "The maximum size of the process's data segment (initialized data, "
        "uninitialized data, and heap).");
    _ceu_format_posix_rlimit_return(buff, RLIMIT_FSIZE, "RLIMIT_FSIZE",
        "Specifies a value one greater than the maximum file descriptor number "
        "that can be opened by this process. ");
#ifdef RLIMIT_NPROC
    _ceu_format_posix_rlimit_return(buff, RLIMIT_NPROC, "RLIMIT_NPROC",
        "The maximum number of processes (or, more precisely on Linux, threads) "
        "that can be created for the real user ID of the calling process.");
#endif
    _ceu_format_posix_rlimit_return(buff, RLIMIT_STACK, "RLIMIT_STACK",
        "The maximum size of the process stack, in bytes.");
#else
    append_sprintf(buff, "%sRun-time System resource limits set by `ulimit` or getrlimit(2):\n", buff);
#endif
}

inline void get_runtime_posix_sysconf_limit_info(char* buff)
{
#ifdef CEU_ON_POSIX
    append_sprintf(buff, "%sRun-time POSIX sysconf(3) resource limits:\n", buff);
    _ceu_format_posix_sysconf_return(buff, _SC_ARG_MAX, "ARG_MAX",
        "maximum length of the arguments to the exec(3) family of functions.");
    _ceu_format_posix_sysconf_return(buff, _SC_CHILD_MAX, "CHILD_MAX",
        "The maximum number of simultaneous processes per user ID.");
    _ceu_format_posix_sysconf_return(buff, _SC_OPEN_MAX, "OPEN_MAX",
        "The maximum number of files that a process can have open at any time.");
    _ceu_format_posix_sysconf_return(buff, _SC_PAGESIZE, "PAGESIZE", "Size of a page in bytes.");
    _ceu_format_posix_sysconf_return(buff, _SC_STREAM_MAX, "STREAM_MAX",
        "The maximum number of streams that a "
        "process can have open at any time.");
    _ceu_format_posix_sysconf_return(buff, _SC_VERSION, "POSIX_VERSION", "Version of POSIX standard");
#else
    append_sprintf(buff, "%sRun-time POSIX sysconf(3) resource limit not supported\n", buff);
#endif
}

#ifdef __cplusplus
}
#endif

#endif // LIBCEU_CHECK_RESOURCE_LIMIT_H
