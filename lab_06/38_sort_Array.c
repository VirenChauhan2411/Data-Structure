#include <stdio.h>

int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n],i,j,temp = 0;
    int *p = arr;
    printf("Enter the value of array : ");
    for (i=0; i<n; i++)
    {
        scanf("%d",(p+i));
    }
     for (i=0; i<n-1; i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(*(p+j) > *(p+j+1))
            {
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }
    printf("Sorted array is : ");
    for (i=0; i<n; i++)
    {
        printf("%d ",*(p+i));
    }
    return 0;
}