#include <stdio.h>

void main() {
    int a, b, i, j, Prime;

    printf("Enter lower limit: ");
    scanf("%d", &a);
    printf("Enter upper limit: ");
    scanf("%d", &b);

    printf("Prime numbers between %d and %d are:\n", a, b);

    for (i = a; i <= b; i++) 
    {
        if (i < 2) 
        {
            continue; 
        }
        Prime = 1;

        for (j = 2; j * j <= i; j++) 
        {
            if (i % j == 0) 
            {
                Prime = 0;
                break;
            }
        }

        if (Prime) 
        {
            printf("%d ", i);
        }
    }

}
