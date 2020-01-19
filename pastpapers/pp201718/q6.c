#include<stdio.h>

const int columns = 3;
int main()
{
    int x = 1;

    while(x<=20)
    {
        if (x % columns == 0)
            printf("%d\n", x++);
        else
            printf("%d\t", x++);
    }

    return 0;
}