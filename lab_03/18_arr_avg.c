#include<Stdio.h>
void main()
{
    int n,sum = 0,avg;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers : ");
    for(int i = 0 ; i< n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int j = 0 ; j< n ;j++)    
    {
        sum = sum + arr[j];
    }
    avg = sum / n;
    printf(" avg is : %d ",avg);
} 