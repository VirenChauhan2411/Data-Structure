#include<stdio.h>
void main()
{
     int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n],i,j,sum = 0;
    int *p = arr;
    printf("Enter the value of array : ");
    for (i=0; i<n; i++) {
        scanf("%d",(p+i));
        sum = sum + *(p+i);
    }
    printf("Sum is :%d",sum);


}