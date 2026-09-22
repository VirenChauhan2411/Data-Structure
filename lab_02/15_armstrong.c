// WAP to print Armstrong nber from 1 to 1000

#include <stdio.h>
#include <math.h>

void main() 
{
    int n, temp, dig, sum;

    printf("Armstrong numbers between 1 and 1000 are: ");

    for (n = 1; n <= 1000; n++) 
    {
        
        temp = n;
        sum = 0;

        while (temp > 0) 
        {
            dig = temp % 10;
            sum = sum + (dig * dig * dig);  
            temp = temp / 10;
        }

        if (sum == n) 
        {
            printf("%d\n", n);
        }
    }
}
