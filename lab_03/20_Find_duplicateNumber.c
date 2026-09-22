#include <stdio.h>

void main() {
    int n, i, j, temp = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) {
                temp = 1;
                break;
            }
        }
        if (temp == 1) 
        {
            break;
        }
    }

    if (temp == 1) 
    {
        printf("Array contains duplicate numbers");
    }
     else 
    {
        printf("Array does not contain duplicate numbers");
    }

    
}
