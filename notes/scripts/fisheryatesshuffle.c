#include<time.h>

void randomize ( int arr[], int n ) 
{ 
    /*Use a different seed value so that we don't get same 
     result each time we run this program*/
    srand ( time(NULL) ); 
  
    /*Start from the last element and swap one by one. We don't 
     need to run for the first element that's why i > 0*/
    for (int i = n-1; i > 0; i--) 
    { 
        /*Pick a random index from 0 to i */
        int j = rand() % (i+1); 
  
        /*Swap arr[i] with the element at random index*/
        swap(&arr[i], &arr[j]); 
    } 
}