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
    printf("Enter the position to delete the number: ");
    scanf("%d",&pos-1);
    for (i = pos; i < n-1 ; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Array : ");
          for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
}