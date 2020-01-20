#include<stdio.h>
#include<stdlib.h>

/* function multiplying two matrices */
/* function to compute p-th power of a matrix */
/* print a formatted matrix */

void multiply(double *a, double *b, double *c, int n)
{
	int i,j,k;
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			c[i*n+j] = 0.0;
			for (k=0; k<n; k++)
			{
				c[i*n+j] += a[i*n+k] * b[k*n+j];
			}
		}
	}
}

void power(double *a, int n, int p)
{
	double *a0, *ai;
	int i,j,k;
	
	a0 = (double *) malloc(sizeof(double)*n*n);
	ai = (double *) malloc(sizeof(double)*n*n);
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			a0[i*n+j] = a[i*n+j];
		}
	}
	
	for (k=1; k<p; k++)
	{
		multiply(a, a0, ai, n);
		
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				a[i*n+j] = ai[i*n+j];
			}
		}
	}
	
	free((void *) a0);
	free((void *) ai);
}
			

void print(double *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("|");
		for (j = 0; j < n; j++)
		{
			printf("%f ", a[i*n+j]);
		}
		printf("|\n");
	}
	printf("\n");
}


int main()
{
	double *a, *b, *c;
	int N=2;
	a = (double *) malloc(sizeof(double)*N*N);
	b = (double *) malloc(sizeof(double)*N*N);
	c = (double *) malloc(sizeof(double)*N*N);
	
	/* dynamic allocation of arrays*/
	a[0*N+0] = 1.0;
	a[0*N+1] = -1.0;
	a[1*N+0] = 1.0;
	a[1*N+1] = 1.0;
	b[0*N+0] = 0.5;
	b[0*N+1] = 0.5;
	b[1*N+0] = -0.5;
	b[1*N+1] = 0.5;
	multiply(a, b, c, N);
	print(c, N);
	a[0*N+0] = 1.0;
	a[0*N+1] = 1.0;
	a[1*N+0] = 1.0;
	a[1*N+1] = 1.0;
	power(a, N, 3);
	print(a, N);
	
	free((void *) a);
	free((void *) b);
	free((void *) c);
	
	return 0;
}

