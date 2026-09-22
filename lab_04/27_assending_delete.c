#include <stdio.h>

void main() {
    int n, i, num, pos = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the numbers:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to delete: ");
    scanf("%d", &num);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == num) 
        {
            pos = i;
            break;
        }
    }

        for (i = pos; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("Array : ");
        for (i = 0; i < n; i++) 
        {
            printf("%d ", arr[i]);
        }
    

    
}
