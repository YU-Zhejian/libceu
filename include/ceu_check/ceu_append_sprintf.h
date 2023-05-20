#ifndef CEU_APPEND_SPRINTF_H
#define CEU_APPEND_SPRINTF_H

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int append_sprintf(char *buff, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
