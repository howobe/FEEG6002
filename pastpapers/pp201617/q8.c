#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * center(char *s, int n);

int main(void)
{
    char s[] = "cat";
    char *ret;

    ret = center(s, 5);
    printf("%s\n", ret);
    free(ret);

    ret = center(s, 6);
    printf("%s\n", ret);
    free(ret);

    ret = center(s, 7);
    printf("%s\n", ret);
    free(center);

    return 0;
}

char * center(char *s, int n)
{
    int len, i, num, lside, rside;
    char *newArray;
    newArray = (char *)malloc(sizeof(char) * (n + 1));
    if (newArray == NULL)
    {
        printf("Unable to allocate memory.\n");
        return NULL;
    }
    len = strlen(s);
    num = n - len;
    
    if (num % 2)
    {
        lside = num / 2 + 1;
        rside = num / 2;
        printf("Odd; lside = %d; rside = %d\n", lside, rside);
    }
    else
    {
        lside = rside = num / 2;
        printf("Even; lside = rside = %d\n", lside);
    }

    for (i = 0; i < n; i++)
    {
        if (i < lside)
        {
            newArray[i] = '-';
        }

        else if ((i >= lside) && (i < (lside + len)))
        {
            newArray[i] = s[i - lside];
        }
        else
        {
            newArray[i] = '-';
        }
    }
    newArray[n] = '\0';

    return newArray;
}
