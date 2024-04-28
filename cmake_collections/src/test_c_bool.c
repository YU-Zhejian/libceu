#include <stdbool.h>

int main(void)
{
    volatile bool t = true;
    t = !t;
    return t;
}
