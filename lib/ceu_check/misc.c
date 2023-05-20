#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "ceu_check/ceu_append_sprintf.h"


int append_sprintf(char *buff, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    size_t buff_len = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    char *newbuff = (char *) calloc(sizeof(char), buff_len);
    if (newbuff == NULL) {
        return 1;
    }
    memset(newbuff, 0, buff_len);
    va_start(args, format);
    int retv = vsnprintf(newbuff, buff_len, format, args);
    va_end(args);

    snprintf(buff, buff_len, "%s", newbuff);
    free(newbuff);
    return retv;
}
