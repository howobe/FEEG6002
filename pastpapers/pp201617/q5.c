
#include <stdio.h>

void grade(double score);

int main(void)
{
    grade(54.);
    grade(100.);
    return 0;
}

void grade(double score)
{
    if (score < 60)
        printf("F\n");
    else if (score >=60 && score<70)
        printf("D\n");
    else if (score >=70 && score<80)
        printf("C\n");
    else if (score >=80 && score<90)
        printf("B\n");
    else
        printf("A\n");
}