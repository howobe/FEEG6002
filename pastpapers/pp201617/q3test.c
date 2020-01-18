#include<stdio.h>

int main(void)
{
    int product, c;

    product = c =1;
    while(c<=5)
    {
    product *= c;
    c++;
    printf("c=%d;prod=%d\n", c, product);
    }
}