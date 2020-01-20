#include<stdio.h>
#define SIZE 5

void addarrays(double *arr1, double *arr2, double *res)
{
	int i;
	
	for (i=0; i< SIZE; i++)
	{
		res[i] = arr1[i] + arr2[i];
	}
	
}
main()
{
	double arr1[SIZE] = {1,2,3,4,5}, arr2[SIZE] = {1,2,3,4,5};	  
	double res[SIZE];
	int i;
	
	addarrays(arr1, arr2, res);
	
	for (i=0; i<SIZE; i++)
	{
		printf("i: %d; sum: %f\n", i, res[i]);
	}
	
	return 0;
}

