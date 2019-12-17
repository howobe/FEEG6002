#include<stdio.h>

long string_length(char s[]);

int main(void)
{
    char s1[] = "Hello";
    printf("%d", string_length(s1));
    return 0;
}

long string_length(char s[])
{
    long nc = 0;
    while (s[nc] != '\0')
    {
        ++nc;
    }
    return nc;
}

