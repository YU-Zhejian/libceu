#include "test_bool.h"
#include <stdbool.h>

#ifndef __bool_true_false_are_defined
#error "__bool_true_false_are_defined not defined!"
#endif

#if __bool_true_false_are_defined != 1
#error "__bool_true_false_are_defined != 1!"
#endif

void test1()
{
    TEST_BOOL_F(bool, true, false);
}
void test2()
{
    TEST_BOOL_F(bool, 1, 0);
}
void test3()
{
    TEST_BOOL_F(bool, 4, 0);
}
void test4()
{
    TEST_BOOL_F(bool, -4, 0);
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
}
