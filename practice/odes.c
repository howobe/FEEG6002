#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Ti 0.0
#define Tf 2.0
#define dT 0.4
#define Y0 0.0

#define num(x) (sizeof(x)/sizeof(*x))

void euler(double *t, double *y, double y0, double (*func)(), int n)
{
    double dt = t[1] - t[0];
    int i;

    y[0] = y0;

    for (i=0; i<n; i++)
    {
        y[i+1] = y[i] + dt*func(t[i], y[i]);
    }
}

void rk2(double *t, double *y, double y0, double (*func)(), int n)
{
    int i;

    double dt = t[1] - t[0], k1, k2;

    y[0] = y0;

    for (i=0; i<n; i++)
    {
        k1 = dt*func(t[i], y[i]);
        k2 = dt*func(t[i]+0.5*dt, y[i]+0.5*k1);
        y[i+1] = y[i] + k2;
    }
}

double fode(double t, double y)
{
    double f;

    f = -t* (1.0+y)*(1.0+y);

    return f;
}

int write_to_file(char *fout, double *t, double *ye, double *yrk, int n)
{
    FILE *fw;
    int i;

    if ((fw = fopen(fout, "w")) == NULL)
    {
        printf("Unable to open file for write.\n");
        return -1;
    }

    for (i=0; i<=n; i++)
    {
        fprintf(fw, "%lf %lf %lf\n", t[i], ye[i], yrk[i]);
    }

    if (fclose(fw) == EOF)
    {
        printf("Unable to close file.\n");
    }

    return 0;
}

int main(void)
{
    int i;
    double *t, *ye, *yrk;
    char fout[] = "dataout.txt";
    int N = (int) (Tf - Ti)/dT;
    printf("N: %d\n", N);

    t = (double *)malloc(sizeof(double)*(N+1));
    ye = (double *)malloc(sizeof(double)*(N+1));
    yrk = (double *)malloc(sizeof(double)*(N+1));

    for (i=0; i<=N; i++)
    {
        t[i] = Ti + dT*i;
    }

    euler(t, ye, Y0, fode, N);
    rk2(t, yrk, Y0, fode, N);

    write_to_file(fout, t, ye, yrk, N);

    free((void *)t);
    free((void *)ye);
    free((void *)yrk);

    return 0;
}