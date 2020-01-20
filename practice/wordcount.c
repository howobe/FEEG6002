#include<stdio.h>
#define IN 1
#define OUT 0

int main(void)
{
    int nwords=0, nlines=1, c, state, nc=0;

    state = OUT;

    while((c=getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
            nlines++;
        else if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nwords++;
        }
    }

    printf("# words: %d; # lines: %d; # chars: %d\n", nwords, nlines, nc);

    return 0;
}