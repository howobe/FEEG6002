#include<stdio.h>
#define N 3
/* Structure complex to represent a complex number */
/* Function init that to return a complex number
having real part x and imaginary part y */
/* Function add return a sum of two complex numbers a
and b */
/* Function conjugate to return a complex conjugate
of a complex number a */
/* Print a complex number c in the format x + yj*/

struct complex {
	double re;
	double im;
};

struct complex init(double x, double y) {
	struct complex comp;
	comp.re = x;
	comp.im = y;
	
	return comp;
}

struct complex add(struct complex a, struct complex b){
	struct complex compsum;
	
	compsum.re = a.re + b.re;
	compsum.im = a.im + b.im;
	
	return compsum;	   
}

struct complex conjugate(struct complex a){
	struct complex conj;
	
	conj.re = a.re;
	conj.im = a.re*-1;
		
	return conj;
}
	

void print(struct complex c)
{
	if (c.im >= 0.0)
		printf("%f+%fj\n", c.re, c.im);
	else
		printf("%f%fj\n", c.re, c.im);
}
int main()
{
	struct complex a[N], b[N], c[N];
	int i;
	
	a[0] = init(1,1);
	a[1] = init(2,4);
	a[2] = init(3,9);
	for (i = 0; i < N; i++)
	{
		b[i] = conjugate(a[i]);
		c[i] = add(a[i], b[i]);	   
		print(a[i]);
		print(c[i]);
	}
	return 0;
}

