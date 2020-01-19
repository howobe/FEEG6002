#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 4

void swap(int *a, int *b);

int main(void) 
{

    float values[] = {10.7, 13.4, 15.8, 19.2};
    float *valPtr[NUM], sum=0, product=1;
    int i, j, pos[] = {0, 1, 2, 3};
    srand((unsigned) time(NULL));

    /*Fisher Yates shuffle*/

    for(i=NUM-1; i>0; i--)
    {
        j = rand() % (i+1);
        swap(&pos[j], &pos[i]);
    }

    for (i=0; i<NUM; i++)
    {
        valPtr[i] = &values[pos[i]];
        sum += *(valPtr[i]);
        product *= **(valPtr +i);
        printf("sum: %.1f; prod: %.2f\n", sum, product);
    }

    printf("Total sum: %.1f; Total product: %.2f\n", sum, product);

return 0;
}

void swap(int*a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}