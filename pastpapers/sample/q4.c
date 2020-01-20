#include <stdio.h>
#include <math.h>
double standard_deviation(double a, double b, double c, double d);
int main(void)
{
	double a, b, c, d, stddev;
	a = 16.3;
	b = 24.2;
	c = 733;
	d = 12.27;
	stddev = standard_deviation(a, b, c, d);
	printf("Standard deviation of %f, %f, %f, %f is %f\n", a, b, c, d, stddev);
	return 0;
}
double standard_deviation(double a, double b, double c, double d)
{
	double mu, sigma, xmm = 0;
	int N = 4, i;
	double *vals[4];
	vals[0] = &a;
	vals[1] = &b;
	vals[2] = &c;
	vals[3] = &d;
	mu = (double)1 / N * (a + b + c + d);
	printf("%f\n", mu);
	for (i = 0; i < N; i++)
	{
		xmm += pow(*(*vals + i) - mu, 2);
		printf("%f\n", xmm);
	}
	sigma = sqrt((double)1 / N * xmm);
	return sigma;
}

