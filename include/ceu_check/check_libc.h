#ifndef CEU_CHECK_LIBC_H
#define CEU_CHECK_LIBC_H

#include <stdio.h>

// See <https://sourceforge.net/p/predef/wiki/Libraries/>

#if defined(__GNU_LIBRARY__)
// This should be sourced from <features.h> in <stdio.h>

// <features.h> is not POSIX

#include <features.h>
#include <gnu/libc-version.h>

#define CEU_LIBC_IS_GLIBC
#define CEU_LIBC_NAME_COMPILE_TIME "GLibC"
#define CEU_LIBC_VER_COMPILE_TIME __GLIBC__ * 100 + __GLIBC_MINOR__

const char *ceu_get_runtime_libc_version()
{
    return gnu_get_libc_version();
}
#else
#define CEU_LIBC_IS_UNKNOWN
#define CEU_LIBC_NAME_COMPILE_TIME "Unknown"
#define CEU_LIBC_VER_COMPILE_TIME -1
const char* ceu_get_runtime_libc_version(){
    return "";
}
#endif

#endif
