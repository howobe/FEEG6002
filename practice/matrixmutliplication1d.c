#include<stdio.h>
#include<stdlib.h>

void multiply(double *a, double *b, double *c, int n);
void power(double *a, int n, int p);
void print(double *a, int n);


int main(void)
{
    int i;
    double *a, double *b, double *c;
    

}

void multiply(double *a, double *b, double *c, int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i * n + j] = 0.0;
            for (k = 0; k < n; k++)
            {
                c[i * n + j] += a[i * n + k] * c[k * n + j];
            }
        }
    }
}

void power(double *a, int n, int p)
{
    int i, j, k;

    double *a0, *ai;

    a0 = (double *) malloc(sizeof(double) * n * n);
    ai = (double *) malloc(sizeof(double) * n * n);

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            a0[i*n+j] = a[i*n+j];
        }
    }

    for (k=0; k<p; k++)
    {
        multiply(a, a0, ai, n);

        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                a[i*n+j] = ai[i*n +j];
            }
        }
    }
    free((void *)a0);
    free((void *)ai);
}

void print(double*a, int n)
{
    int i,j;

    for (i=0; i<n; i++)
    {
        if (i==0)
        {
            printf("/");
        }
        else if(i==n-1)
        {
            printf("\\");
        }
        else
        {
            printf("|");
        }
        for (j=0; j<n; j++)
        {
            printf("%5d", a[i*n+j]);
        }
        if (i==0)
        {
            printf("\\\n");
        }
        else if(i==n-1)
        {
            printf("/\n");
        }
        else
        {
            printf("|\n");
        }
    }
}