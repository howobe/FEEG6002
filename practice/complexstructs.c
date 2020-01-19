#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct
{
    double re;
    double im;
} complex;

complex init(double x, double y);

complex add(complex a, complex b);

void conjugateptr(complex *a);

complex conjugate(complex a);

void print(complex c);

void printc(complex c);

complex * addp(complex *a, complex *b);

int main(void)
{
    int i;
    double im1 = 1.0, re1 = 2.0, im2 = 2.0, re2 = 2.0;
    complex comp1, comp2;
    complex sum;
    complex *ptr = &comp1;
    complex conj;
    complex a[N]={{1,1}, {2,4}, {3,9}}, b[N], c[N], d[1]={{-1.0,2.0}};
    complex *sump;
    

    print(d[0]);


    comp1 = init(re1, im1);

    printf("Num: %g + %gj\n", comp1.re, comp1.im);

    comp2 = init(re2, im2);

    sum = add(comp1, comp2);

    printf("sum: %g + %gj\n", sum.re, sum.im);

    conjugateptr(ptr);

    printf("conj: %g %gj\n", comp1);

    /*Return to normal state*/
    conjugateptr(ptr);

    conj = conjugate(comp1);

    printf("conj (no ptr): %g %gj\n", conj);

    
    /*
    a[0].re = 1;
    a[0].im = 1;
    a[1].re = 2;
    a[1].im = 4;
    a[2].re = 3;
    a[2].im = 9;
    */
    for (i=0; i<N; i++)
    {
        b[i] = conjugate(a[i]);
        c[i] = add(a[i], b[i]);
        printc(a[i]);
        printc(b[i]);
        printc(c[i]);
    }

    sump = addp(ptr, ptr);
    print(*ptr);
    print(*sump);

    return 0;
}

complex init(double x, double y)
{
    complex num;
    num.re = x;
    num.im = y;

    return num;
}

complex add(complex a, complex b)
{
    complex sum;

    sum.re = a.re + b.re;
    sum.im = a.im + b.im;

    return sum;
}

void conjugateptr(complex *a)
{
    a-> im *= -1;
}

complex conjugate(complex a)
{
    a.im *= -1;

    return a;
}

void print(complex c)
{
    if (c.im < 0.0)
    {
        printf("%g %gj\n", c.re, c.im);
    }
    else
    {
        printf("%g + %gj\n", c.re, c.im);
    }
}

void printc(complex c)
{
    printf("%g %s %gj\n", c.re, (c.im<0.0)? "-":"+", (c.im<0.0)? c.im*-1:c.im);
}

complex * addp(complex *a, complex *b)
{
    complex *ptr = malloc(sizeof(*ptr));

    ptr->re = a->re + b->re;
    ptr->im = a->im + b->im;

    return ptr;
}