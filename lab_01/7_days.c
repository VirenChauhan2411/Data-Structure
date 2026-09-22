#include <stdio.h>

void main() {
    int td;
    int y, w, d;

    printf("Enter total number of days: ");
    scanf("%d", &td);

    y = td / 365;           
    w = y / 7;       
    d = y % 7;        

   printf("days  :%d weeks : %d years : %d",d,w,y);

}
