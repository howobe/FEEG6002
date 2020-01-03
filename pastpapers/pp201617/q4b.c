#include <stdio.h>

int sum_integers(void);

int main(void)
{
    printf("Sum = %d\n", sum_integers());
    return 0;
}

int sum_integers(void)
{
    int i=1, sum=0;

    while (i<=10)
        sum += i++;
    return sum;
}