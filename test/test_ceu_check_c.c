//
// Created by yuzj on 1/16/22.
//
#include <stdio.h>
#include <string.h>
#include "ceu_check/check_all.h"

int main(void)
{
    char buff[40960];
    memset(buff, 0, sizeof(buff));
    get_full_info(buff);
    printf("%s", buff);
}
