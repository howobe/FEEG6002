#include<stdio.h>
#define N 3


int main(void)
{
    int i, j, k;

    int m[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int res[N][N] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                res[i][j] += m[i][k] * n[k][j];
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            printf("/");
        }
        else if (i == N - 1)
        {
            printf("\\");
        }
        else
        {
            printf("|");
        }
        for (j = 0; j < N; j++)
        {
            printf("%4d", res[i][j]);
        }
        if (i==0)
        {
            printf(" \\\n");
        }
        else if (i==N-1)
        {
            printf(" /\n");
        }
        else
        {
            printf(" |\n");    
        }
    }

    return 0;
}