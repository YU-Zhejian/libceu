#include "test_bool.h"

void test2()
{
    TEST_BOOL_F(_Bool, 1, 0);
}
void test3()
{
    TEST_BOOL_F(_Bool, 4, 0);
}
void test4()
{
    TEST_BOOL_F(_Bool, -4, 0);
}

int main(void)
{
    test2();
    test3();
    test4();
}
