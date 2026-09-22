#include<stdio.h>
void main(){
      int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n],i,j;
    int *p = arr;
    printf("Enter the value of array : ");
    for (i=0; i<n; i++) {
        scanf("%d",(p+i));
    }
     int max = arr[0];
      for(int i = 0 ; i< n ;i++)
     {
        if(*(p+i)>max)
        {
           max =*(p+i);     
        }
     }
     printf("Max element is : %d",max);
}