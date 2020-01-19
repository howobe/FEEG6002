#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char *string1, *string2;
    int len;
    string1= "Hu";
    len = strlen(string1);
    printf("%d\n", len);
    string2 = (char *) malloc(sizeof(char)*(len+1));
    printf("%s\n", string1);
    strcpy(string2, string1);
    printf("%s\n", string2);
    

    free(string2);

    return 0;
}