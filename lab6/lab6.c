#include<stdlib.h>
#include<stdio.h>

long * make_fib_array(long n);

long * make_long_array(long n);

void use_make_long_array(long n);

void use_fib_array(long N);

int main(void) {
	use_fib_array(10);
	return 0;
}

long * make_long_array(long n) {
	long *a;
	a = (long*)malloc(sizeof(long) * n);
	if (a == NULL) {
		printf("Memory allocation failed.\n");
		return NULL;
	}
	else {
		return a;
	}
}

void use_make_long_array(long n) {
	int i;
	long *p = make_long_array(n);
	printf("In use_make_long_array(%ld)\n", n);/* if p is not NULL, we could allocate memory, and we proceed
	with testing: */
	if (p != NULL) {
		/* write some data to the array -- if the allocated memory
		is too short, this might trigger a segfault */
		for (i = 0; i < n; i++) {
			p[i] = i + 42; /* just write some data */
		}
		/* free array -- if the allocated array is too short, we may
		have corrupted malloc/free metadata when writing the i+42 data
		above, and this may show when we call the free command: */
		free(p);
		/* if the program does not crash, it is a good sign [but
		no proof for correctness]. The other way round: if the
		program segfaults or crashes, this is not a good sign. */
	}
	else {
		/* we get here if memory allocation didn't work for
		some reason. */
		printf("Error - it seems that the memory allocation failed.\n");
	}
}

long * make_fib_array(long n) {
	int i;
	long *p = make_long_array(n);
	if (p != NULL) {

		p[0] = 0;
		p[1] = 1;
		for (i = 2; i < n; i++) {
			p[i] = p[i - 1] + p[i - 2];
		}
		return p;
	}
	else {
		return NULL;
	}

}

void use_fib_array(long N) {
	/* N is the maximum number for fibarray length */
	long n; /* counter for fibarray length */
	long i; /* counter for printing all elements of fibarray */
	long *fibarray; /* pointer to long -- pointer to the fibarray itself*/
	/* Print one line for each fibarray length n*/
	for (n = 2; n <= N; n++) {
		/* Obtain an array of longs with data */
		fibarray = make_fib_array(n);
		/* Print all elements in array */
		printf("fib(%2ld) : [", n);
		for (i = 0; i < n; i++) {
			printf(" %ld", fibarray[i]);
		}
		printf(" ]\n");
		/* free array memory */
		free(fibarray);
	}
}