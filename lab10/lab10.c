#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x);

double trapez(double (*func)(double), double a, double b, int n);

double fint_an(double a, double b);

double error_trapez(double (*func)(double), double (*Func)(double, double), double a, double b, int n);

double qgaus(double (*func)(double), double a, double b);

double error_qgaus(double (*func)(double), double (*Func)(double, double), double a, double b);
/*
int main(void)
{
    double A, trapzerror, qgausans, qgauserror;
    A = trapez(f, 1.0, 10.0, 100);
    printf("Numerical approximation of f(x) using trapez: %g\n", A);

    trapzerror = error_trapez(f, fint_an, -1, 2, 21);
    printf("Error (trapz method): %f\n", trapzerror);

    qgausans = qgaus(f, 1, 10);
    printf("Numerical approximation of f(x) using qgaus: %g\n", qgausans);

    qgauserror = error_qgaus(f, fint_an, -1, 2);
    printf("Error (qgaus method): %g\n", qgauserror);

    return 0;
}
*/



/*
double f(double x)
{
    return x * x;
}
double If_an(double a, double b)
{
    return b * b * b / 3.0 - a * a * a / 3.0;
}
*/


int main(void)
{


    double a, b, A, diff;
    int n;

    a = -1.0;
    b = 2.0;
    n = 10;

    A = trapez(f, a, b, n);
    printf("A_trapez = %f\n", A);

    A = qgaus(f, a, b);
    printf("A_qgaus = %f\n", A);

    diff = error_trapez(f, fint_an, a, b, n);
    printf("diff_trapez = %f\n", diff);

    diff = error_qgaus(f, fint_an, a, b);
    printf("diff_qgaus = %f\n", diff);

    return 0;
}


double f(double x)
{
    return x * x;
}

double trapez(double (*func)(double), double a, double b, int n)
{
    /*Function for evaluating integral using composite trapezium method.
    That is: I = int_{a}^{b}{f(x) dx} ~ A,
    where A = (h/2) * (f(a) + f(b) + 2*sum_{i=1}^{n-1}{f(x_i)}
    h = (b-a)/n; x_{i} = a + i*h
    */

    int i;
    double h, leval, heval, x, sumof = 0, A;

    /*Calculating space between interval points*/
    h = (b - a) / n;
    printf("Integrating f(x) between %g and %g over %d steps.\n", a, b, n);

    /*Evaluating function at lower and upper limits*/
    leval = (*func)(a);
    heval = (*func)(b);
    printf("h: %g; leval: %g; heval: %g\n", h, leval, heval);

    /*Evaluating sum of middle sections*/
    for (i = 1; i < n - 1 ; i++)
    {
        x = a + i * h;
        sumof += (*func)(x);
        printf("x_%d: %g; sumof: %g\n", i, x, sumof);
    }

    /*Bringing all elements together*/
    A = h / 2.0 * (leval + heval + 2.0 * sumof);

    return A;
}

double fint_an(double a, double b)
{
    return (b * b * b - a * a * a) / 3.0;
}

double error_trapez(double (*func)(double), double (*Func)(double, double), double a, double b, int n)
{
    /*Function that calculates error between analytical and numerical solution*/
    double approx, exact, error;

    /*Calculating approx and exact solutions*/
    approx = trapez(f, a, b, n);
    exact = Func(a, b);
    printf("Approximate val: %g; Exact val: %g\n", approx, exact);

    /*Error is difference between solutions*/
    error = approx - exact;

    return error;
}

double qgaus(double (*func)(double), double a, double b)
{
    /*qgaus was adopted from the Numerical recipes in
    C book (2nd edition Cambridge University press 1992, page 148)*/
    int j;
    double xr, xm, dx, s;
    double x[] = {0.0, 0.1488743389, 0.4333953941,
                  0.6794095682, 0.8650633666, 0.9739065285
                 };
    double w[] = {0.0, 0.2955242247, 0.2692667193,
                  0.2190863625, 0.1494513491, 0.0666713443
                 };
    /* The first value of arrays x, w is not used. */

    xm = 0.5 * (b + a);
    xr = 0.5 * (b - a);
    s = 0;
    for (j = 1; j <= 5; j++)
    {
        dx = xr * x[j];
        s += w[j] * ((*func)(xm + dx) + (*func)(xm - dx));
    }
    return s *= xr;

}

double error_qgaus(double (*func)(double), double (*Funco)(double, double), double a, double b)
{
    /*Calculates error between qgaus numerical approximation and exact solution*/
    double approx, exact, error;

    approx = qgaus(f, a, b);
    exact = fint_an(a, b);

    error = approx - exact;

    return error;
}