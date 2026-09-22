#include<Stdio.h>
void main()
{
    int fn,ln,sum = 0;
    
    printf("Enter the first digit and last digit : ");
    scanf("%d %d",&fn,&ln);
    for(int i = fn ; i<= ln ; i++)
    {
        sum = sum + i;
    }
    printf("Sum is : %d",sum);
}