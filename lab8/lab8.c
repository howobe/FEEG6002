#include<stdio.h>
#include<stdlib.h>

struct entry {
    char firstname[20];
    char lastname[20];
    char phone[10];
};

int main(void) {
    int i;
    struct entry list[4];


    for (i = 0; i < 4; i++) {
        printf("\nEnter first name: ");
        scanf("%s", list[i].firstname);
        printf("\nEnter last name: ");
        scanf("%s", list[i].lastname);
        printf("\nEnter phone in 123-4567 format: ");
        scanf("%s", list[i].phone);
    }

    for (i = 0; i < 4; i++) {
        printf("Name: %s %s     Phone: %s\n", list[i].firstname, list[i].lastname, list[i].phone);
    }

    return 0;
}