#include<stdio.h>
#include<math.h>

const int XMIN = 0, XMAX = 10, N = 100;

int main(void)
{
	int i;
	float x,y;
	
	for (i=0; i<N; i++)
	{
		x = XMIN + (XMAX - XMIN)*(double)i/(N-1);
		y = sin(x);
		printf("%f %f\n", x, y);
	}
	
	return 0;
}

