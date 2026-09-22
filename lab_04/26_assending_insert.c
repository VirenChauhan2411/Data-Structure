#include <stdio.h>

void main() {
    int n, num, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n+1];  

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    pos = n;
    
    for (i = 0; i < n; i++) 
    {
        if (num < arr[i]) 
        {
            pos = i;
            break;
        }
    }

    for (i = n; i > pos; i--) 
    {
        arr[i] = arr[i-1];
    }

    arr[pos] = num;
    n++;

    printf("Array :");

    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
}
