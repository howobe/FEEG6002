#include <stdio.h>

int find_greatest(int a, int b, int c);

int main(void)
{
	int a,b,c;
	a=10;
	b=8;
	c=2;
	printf("The largest of %d, %d and %d is: %d\n", a,
	b, c, find_greatest(a, b, c));
	return 0;
}

int find_greatest(int a, int b, int c)
{
	int max = a;
	
	if (b>max)
		max = b;
	else if (c>max)
		max = c;
	
	return max;
}

