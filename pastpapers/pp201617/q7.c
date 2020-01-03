#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n);

int * zero_array(int n);

void delete_array(int *a);

int main() {
    int n = 5;
    int* a = zero_array(n);
    print(a, n);
    delete_array(a);
    return 0;
}

void print(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int * zero_array(int n)
{
    int *array, i;

    array = (int *) malloc(n*sizeof(int));

    if (array == NULL)
    {
        printf("Unable to allocate memory.");
        return NULL;
    }
   
   for (i=0; i<n; i++)
   {
        *(array+i) = 0;
   }
    return array;
}

void delete_array(int *a)
{
    free(a);
}