#include <stdio.h>
/* A normal function with an int parameter
and void return type*/
void fun(int a)
{
    printf("Value of a is %d\n", a);
}

void add(int a, int b)
{
    printf("Addition is %d\n", a + b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a - b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a * b);
}

int main()
{
    /* fun_ptr is a pointer to function fun() */
    void (*fun_ptr)(int) = &fun;
    void (*fun_ptr2)(int) = fun;
    void (*fun_ptrarr[])() = {add, subtract, multiply};

    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun;
    */

    /*Invoking fun() using fun_ptr*/
    (*fun_ptr)(10);

    /*Can also be invoked in this way*/
    fun_ptr2(10);

    (*fun_ptrarr[2])(1, 2);

    return 0;
}

/*
Output:
Value of a is 10
Value of a is 10
Multiplication is 2
*/