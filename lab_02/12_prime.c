// prime number : 13

#include <stdio.h>
void main()
{
    int i = 2, n, flag = 1;
    printf("enter the number: ");
    scanf("%d", &n);
    while (i < n)
    {
        if (n % i == 0)
        {
            flag = 0;
        }
        i++;
    }
    if (flag == 1)
    {
        printf("prime");
    }
    else
    {
        printf("not prime number: ");
    }
}