#include <stdio.h>

void main()
{
    int arr[100], n, num, pos, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);//{1,2,3,4,5}
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be inserted: ");// 
    scanf("%d", &num);
    printf("Enter the position to insert the number: ");
    scanf("%d", &pos);
    
    
    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = num;
    
    printf("Array : ");
    for (i = 0; i <= n; i++)
    {
        printf("%d ,", arr[i]);
    }
}