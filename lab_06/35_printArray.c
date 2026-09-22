#include<stdio.h>
void main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n],i,j;
    int *p = arr;
    printf("Enter the value of array : ");
    for (i=0; i<n; i++) {
        scanf("%d",(p+i));
    }
      for (i=0; i<n; i++) {
        printf("%d",*(p+i));
    }
    
}