#include <stdio.h>
#include <stdlib.h>

void populate_array(long *arr, long n);

int main(void)
{
	long size = 10;
	long i;
	long *array = malloc(sizeof(long) * size);
	populate_array(array, size);
	for (i = 0; i < size; i++)
	{
		printf("array[%04ld] = %ld\n", i, array[i]);
	}
	free(array);
	return 0;
}

void populate_array(long *arr, long n)
{
	int i;
	for (i=0; i<n; i++)
	{
		*(arr + i) = i*2+2;
	}
}
	

