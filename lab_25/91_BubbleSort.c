#include<stdio.h>

void BubbleSort(int val[], int n);

int main()
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

BubbleSort(val, n);

for (i = 0; i < n; i++)
{   
     printf("%d ", val[i]);

}
return 0;
}
void BubbleSort(int val[], int n)
{
int i,j,temp;

    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (val[j] > val[j + 1]) 
            {
                temp = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp;
            }
        }
    }

}
