//
// Created by yuzj on 1/16/22.
//

#include <cstdio>
#include <cstring>
#include "ceu_check/check_all.h"

int main()
{
    char buff[40960];
    memset(buff, 0, sizeof(buff));
    get_full_info(buff);
    printf("%s", buff);
}
