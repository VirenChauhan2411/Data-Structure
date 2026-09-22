#include<stdio.h>

int selectionSort(int val[],int n)
{
int i,j,min,temp;

for(i=0;i<n-1;i++)
{
    min = i;
    for(j=i+1;j<n;j++)
    {
        if(val[j] < val[min])
        min = j;
    }
    temp = val[i];
    val[i] = val[min];
    val[min]=temp;
}

}

int  main()
{
int val[100];
int n;
int i;

printf("Enter the Numbers of elemetns : ");
scanf("%d",&n);

printf("Enter the Value : ");
for(i=0;i<n;i++)
{
    scanf("%d",&val[i]);
}

selectionSort(val, n);

for (i = 0; i < n; i++)
{   
     printf("%d ", val[i]);

}
return 0;

}