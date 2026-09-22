#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i< n ;i++)
    {
        scanf("%d",&arr[i]);// 1 2 3 4 5 
    }
      int sn=0,ln=0;
    int min=arr[0];
     for(int k = 0 ; k< n ;k++)
     {
        if(min>arr[k])
        {
         min = arr[k];
         sn  = k;

        }
     }
     int max = arr[0];
      for(int j = 0 ; j< n ;j++)
     {
        if(arr[j]>max)
        {
           max =arr[j];
           ln = j;
            
        }
     }
    printf("lowest location is : %d \n",sn+1);
     printf("bigger location is : %d",ln+1);
    
}     