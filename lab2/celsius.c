#include <stdio.h>
/*
Returns a list of temperatures in degC and degF ranging
between -30 and 30 (degC).
*/
int main(void) {
	int celsius;
	float fahr;
	for (celsius=-30; celsius <= 30; celsius+=2) {
		fahr = celsius * 9 / 5. + 32;
		printf("%3d = %5.1f\n", celsius, fahr);
	}
	return 0;
}
