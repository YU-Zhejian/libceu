#include <stdlib.h>

__attribute__((noreturn)) static int f(int i)
{
    exit(0);
}

__attribute__((unused)) static int g(int i)
{
    return 1;
}

int main(void)
{
    f(1);
    return 0;
}
