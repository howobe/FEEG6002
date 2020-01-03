#include <stdio.h>

int product(int a, int b, int c);

int main(void)
{
    printf("Result = %d\n", product(1, 2, 3));
    return 0;
}

int product(int a, int b, int c)
{
    return a*b*c;
}