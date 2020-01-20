#include<stdio.h>
#include<string.h>

typedef union Book {
    int pages;
    float price;
    char *name;
}Book;

int main()
{
    union Book index;

    index.pages = 750;
    index.price = 125.50;
    index.name= "Handbook of C";

    printf("Name of Book: %s\n", index.name);
    printf("No. of Pages: %d\n", index.pages);
    printf("Price       : %f\n", index.price);

    return 0;
}