#include<stdio.h>
#include<math.h>

#define N 10
#define XMIN 1
#define XMAX 10

int main(void){
	int i;
	float x, y;
	for (i=0; i<N; i++){
		x = XMIN + ((XMAX-XMIN)/(N-1))* i;
		y = sin(x);
		printf("%f %f\n", x, y);
		}
	return 0;
	}

