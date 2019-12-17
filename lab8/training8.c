#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

Point makePoint(int xx, int yy){
    Point a;
    a.x = xx;
    a.y = yy;
    return a;
}

int main(void){
    Point myPoint2 = makePoint(3,5);

    printf("myPoint2.x = %d myPoint2.y = %d\n",myPoint2.x,myPoint2.y);

    return 0 ;
}
