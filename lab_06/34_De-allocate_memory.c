#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *intptr = (int *)malloc(sizeof(int));
    char *charptr = (char *)malloc(sizeof(char));
    float *floatptr = (float *)malloc(sizeof(float));

            *intptr = 10;
            *charptr = 'P';
            *floatptr = 3.142872;

            printf("int: %d Char : %c float: %f",*intptr,*charptr,*floatptr);

            free(intptr);
            free(charptr);
            free(floatptr);
    
    return 0;
}