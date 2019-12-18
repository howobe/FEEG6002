#include<stdio.h>
#include<math.h>

#define N 10
#define XMIN 1.0
#define XMAX 10.0

int main(void) {
	int i;
	double x, y1, y2;
	for (i = 0; i < N; i++) {
		x = XMIN + ((XMAX - XMIN) / (N - 1)) * i;
		y1 = sin(x);
		y2 = cos(x);
		printf("%f %f %f\n", x, y1, y2);
	}
	return 0;
}

