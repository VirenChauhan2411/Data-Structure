#include<Stdio.h>
void main()
{
    int n,temp ,n1,n2,i;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : ");
    for(int i = 0 ; i< n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the two numbers for the replace : ");
    scanf("%d %d",&n1,&n2);
    for(i=0;i<n;i++)
    {
            if(arr[i]==n1)
            {
                arr[i] = n2;
                printf("Index of array is : %d \n", i);
                temp++;
            }
            
    }
    if(temp == 0)
    {
        printf("Nmber is not in Array : ");
    }
    printf("FInal array is : ");
    
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
   
}