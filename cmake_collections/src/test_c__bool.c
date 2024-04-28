int main(void)
{
    volatile _Bool t = 1;
    t = !t;
    return t;
}
