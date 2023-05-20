//
// Created by yuzj on 2/9/22.
//

#include "ceu_check/check_os.h"
#include "ceu_check/ceu_append_sprintf.h"

#ifndef LIBCEU_CHECK_RESOURCE_LIMIT_H
#define LIBCEU_CHECK_RESOURCE_LIMIT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CEU_ON_POSIX
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>


static inline void _ceu_format_posix_rlimit_return(
    char *buff,
    int rlimit_macro,
    const char *rlimit_name,
    const char *rlimit_explain
)
{

    struct rlimit rlimit_get;
    getrlimit(rlimit_macro, &rlimit_get);
    append_sprintf(
        buff,
        "%s\t%s: SOFT=%d, HARD=%d // %s\n",
        buff,
        rlimit_name,
        rlimit_get.rlim_cur,
        rlimit_get.rlim_max,
        rlimit_explain
    );
}

static inline void _ceu_format_posix_sysconf_return(
    char *buff,
    int posix_limit_macro,
    const char *posix_limit_name,
    const char *posix_limit_explain
)
{
    append_sprintf(
        buff,
        "%s\t%s=%d // %s\n",
        buff,
        posix_limit_name,
        sysconf(posix_limit_macro),
        posix_limit_explain
    );
}

#endif

static inline void get_rlimit_info(char *buff)
{
#ifdef CEU_ON_POSIX
    append_sprintf(
        buff,
        "%sRun-time System resource limits set by `ulimit` or getrlimit(2):\n",
        buff
    );
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_AS,
        "RLIMIT_AS",
        "The maximum size of the process's virtual memory (address space) in bytes."
    );
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_CORE,
        "RLIMIT_CORE",
        "Size limit of core dump files."
    );
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_CPU,
        "RLIMIT_CPU",
        "CPU time limit in seconds."
    );
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_DATA,
        "RLIMIT_DATA",
        "The maximum size of the process's data segment (initialized data, uninitialized data, and heap)."
    );
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_FSIZE,
        "RLIMIT_FSIZE",
        "Specifies a value one greater than the maximum file descriptor number that can be opened by this process. "
    );
#ifdef RLIMIT_NPROC
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_NPROC,
        "RLIMIT_NPROC",
        "The maximum number of processes (or, more precisely on Linux, threads) that can be created for the real user ID of the calling process."
    );
#endif
    _ceu_format_posix_rlimit_return(
        buff,
        RLIMIT_STACK,
        "RLIMIT_STACK",
        "The maximum size of the process stack, in bytes."
    );
#else
    append_sprintf(
        buff,
        "%sRun-time System resource limits set by `ulimit` or getrlimit(2):\n",
        buff
        );
#endif
}

static inline void get_runtime_posix_sysconf_limit_info(char *buff)
{
#ifdef CEU_ON_POSIX
    append_sprintf(buff, "%sRun-time POSIX sysconf(3) resource limits:\n", buff);
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_ARG_MAX,
        "ARG_MAX",
        "maximum length of the arguments to the exec(3) family of functions."
    );
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_CHILD_MAX,
        "CHILD_MAX",
        "The maximum number of simultaneous processes per user ID."
    );
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_OPEN_MAX,
        "OPEN_MAX",
        "The maximum number of files that a process can have open at any time."
    );
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_PAGESIZE,
        "PAGESIZE",
        "Size of a page in bytes."
    );
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_STREAM_MAX,
        "STREAM_MAX",
        "The maximum number of streams that a process can have open at any time."
    );
    _ceu_format_posix_sysconf_return(
        buff,
        _SC_VERSION,
        "POSIX_VERSION",
        "Version of POSIX standard"
    );
#else
    append_sprintf(buff, "%Run-time POSIX sysconf(3) resource limit not supported\n", buff);
#endif
}

static inline void get_compiletime_posix_standard(char *buff)
{
#ifdef CEU_ON_POSIX
    append_sprintf(buff, "%sCompile-time POSIX version:\n", buff);
#ifdef _POSIX_VERSION
    append_sprintf(buff, "%s\tSystem POSIX.1 Version (_POSIX_VERSION): %ld\n", buff, _POSIX_VERSION);
#endif
#ifdef _POSIX2_VERSION
    append_sprintf(buff, "%s\tPOSIX.2 Utility Version (_POSIX2_VERSION): %ld\n", buff, _POSIX2_VERSION);
#endif
#ifdef _XOPEN_UNIX
    append_sprintf(buff, "%sCompile-time Single UNIX Specification (SUS) version: ", buff);
#ifdef _XOPEN_VERSION
    switch (_XOPEN_VERSION) {
        case 4:
            append_sprintf(buff, "%sv1\n", buff);
            break;
        case 500:
            append_sprintf(buff, "%sv2\n", buff);
            break;
        case 600:
            append_sprintf(buff, "%sv3\n", buff);
            break;
        case 700:
            append_sprintf(buff, "%sv4\n", buff);
            break;
        default:
            append_sprintf(buff, "%sUnknown (%d)\n", buff, _XOPEN_VERSION);
            break;
    }
#else
    append_sprintf(buff, "%sUnknown (NULL)\n", buff);
#endif
#else
    append_sprintf(buff, "%sCompile-time Single UNIX Specification (SUS) version not available.\n", buff);
#endif
#else
    append_sprintf(buff, "%Compile-time POSIX version not available.\n", buff);
#endif
}

static inline void get_ctypes_limit_info(char *buff)
{
    append_sprintf(buff, "%sCompile-time C Types max, min, etc. limits:\n", buff);
    append_sprintf(
        buff,
        "%s\tCHAR_BIT=%d, CHAR_MIN=%d, CHAR_MAX=%d, sizeof=%d; ",
        buff,
        CHAR_BIT,
        CHAR_MIN,
        CHAR_MAX,
        sizeof(char)
    );
    append_sprintf(
        buff,
        "%sSCHAR_MIN=%d, SCHAR_MAX=%d, sizeof=%d; ",
        buff,
        SCHAR_MIN,
        SCHAR_MAX,
        sizeof(signed char)
    );
    append_sprintf(
        buff,
        "%sUCHAR_MAX=%d, sizeof=%d; ",
        buff,
        UCHAR_MAX,
        sizeof(unsigned char)
    );
    append_sprintf(
        buff,
        "%ssizeof wchar_t=%d, sizeof size_t=%d\n",
        buff,
        sizeof(wchar_t),
        sizeof(size_t)
    );
    append_sprintf(
        buff,
        "%s\tSHRT_MIN=%d, SHRT_MAX=%d, sizeof=%d; ",
        buff,
        SHRT_MIN,
        SHRT_MAX,
        sizeof(short)
    );
    append_sprintf(
        buff,
        "%sUSHRT_MAX=%d, sizeof=%d\n",
        buff,
        USHRT_MAX,
        sizeof(unsigned short)
    );
    append_sprintf(
        buff,
        "%s\tINT_MIN=%d, INT_MAX=%d, sizeof=%d; ",
        buff,
        INT_MIN,
        INT_MAX,
        sizeof(int)
    );
    append_sprintf(
        buff,
        "%sUINT_MAX=%ld, sizeof=%d\n",
        buff,
        UINT_MAX,
        sizeof(unsigned int)
    );
    append_sprintf(
        buff,
        "%s\tLONG_MIN=%ld, LONG_MAX=%ld, sizeof=%d; ",
        buff,
        LONG_MIN,
        LONG_MAX,
        sizeof(long)
    );
    append_sprintf(
        buff, "%sULONG_MAX=%ld, sizeof=%d\n",
        buff,
        ULONG_MAX,
        sizeof(unsigned long)
    );
    append_sprintf(
        buff,
        "%s\tLLONG_MIN=%ld, LLONG_MAX=%ld, sizeof=%d; ",
        buff,
        LLONG_MIN,
        LLONG_MAX,
        sizeof(long long)
    );
    append_sprintf(
        buff,
        "%sULLONG_MAX=%ld, sizeof=%d\n",
        buff,
        ULLONG_MAX,
        sizeof(unsigned long long)
    );
}

#ifdef __cplusplus
}
#endif

#endif //LIBCEU_CHECK_RESOURCE_LIMIT_H
