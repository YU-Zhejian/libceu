inline static int f(i)
{
    return i - 1;
}

int main(void)
{
    volatile j = f(1);
    return j;
}
