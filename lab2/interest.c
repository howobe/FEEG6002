#include <stdio.h>
/*
Calculates interest over 24 month period
*/

int main(void) {
	int s = 1000;
	float debt = s;
	float rate = 0.03;
	float total_interest;
	int month;
	for (month = 1; month <= 24; month++) {
		float interest = debt * rate;
		debt += interest;
		total_interest += interest;
		printf("month %2d: debt=%7.2f, ", month, debt);
		printf("interest=%5.2f, total_interest=%7.2f, ", interest, total_interest);
		printf("frac=%6.2f%%\n", total_interest * 100 / s);
	}
	return 0;
}
