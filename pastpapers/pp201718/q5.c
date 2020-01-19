#include<stdio.h>

/*Assuming they are not in array, as it does not explicitly state this*/

float maximum(float a,  float b, float c, float d)
{
    float max = a;
    if (b>max)
        max = b;
    else if (c>max)
        max = c;
    else if (d>max)
        max = d;

    return max;
}


int main(void)
{
    float a=10.5, b=20.2, c=19.9, d=5.9;

    printf("max: %.1f\n", maximum(a,b,c,d));

    return 0;
}