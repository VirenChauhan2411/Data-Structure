// WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n)


#include <stdio.h>

void main() {
    int n, i, j;
    int sum = 0, inSum;

    printf("Enter value of term n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
    {
        inSum = 0;
        for (j = 1; j <= i; j++) 
        {
            inSum = inSum + j;  
        }
        sum = sum + inSum;    
    }

    printf("Sum = %d", sum);
   
}
