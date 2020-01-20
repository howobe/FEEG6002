#include<stdio.h>
#include<stdlib.h>
#define NLEN 10
#define CLEN 26

int sum(int *arr, int len)
{
    int i, sum=0;

    for (i=0; i< len; i++)
        sum += arr[i];

    return sum;
}

int main(void)
{
    int ndigit[NLEN], nws=0, nchar[CLEN], nother=0, i;
    char c, *spc, cref='a', nref='0';

    for (i=0; i<NLEN; i++)
    {
        ndigit[i] = 0;
    }

    i=0;
    while(i<CLEN)
    {
        nchar[i++] = 0;
    }

    while ((c=getchar()) != EOF)
    {
        if (c == '\t' || c == '\n' || c == ' ')
        {
            nws++;
        }

        else if (c >= nref && c<= '9')
        {
            ++ndigit[c - nref];
        }
        else if (c>= cref && c<= 'z')
        {
            ++nchar[c - cref];
        }
        else
        {
            nother++;
        } 
    }

    printf("Summary:\n");
    printf("# of chars: %d; # of digits: %d; # of white space: %d; other: %d\n",
        sum(nchar, CLEN), sum(ndigit, NLEN), nws,  nother);

    printf("Letters:\n");

    for (i=0; i<CLEN; i++)
    {
        spc = (i==CLEN-1) ? "":" ";
        printf("%c: %d%s", cref+i, nchar[i], spc);
    }
    printf("\n\n");

    printf("Numbers:\n");

    for (i=0; i<NLEN; i++)
    {
        spc = (i==NLEN-1) ? "":" ";
        printf("%d: %d;%s", 0+i, ndigit[i], spc);
    }

    return 0;

}
