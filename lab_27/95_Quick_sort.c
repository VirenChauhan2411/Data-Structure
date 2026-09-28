#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot;
    int smaller;
    int curr;
    int temp;

    pivot = arr[high];
    smaller = low - 1;

    for (curr = low; curr < high; curr++) {
        if (arr[curr] < pivot) {
            smaller++;

            temp = arr[smaller];
            arr[smaller] = arr[curr];
            arr[curr] = temp;
        }
    }

    temp = arr[smaller + 1];
    arr[smaller + 1] = arr[high];
    arr[high] = temp;

    return smaller + 1;
}

void quickSort(int arr[], int low, int high) {
    int pivotPosition;

    if (low >= high)
        return;

    pivotPosition = partition(arr, low, high);

    quickSort(arr, low, pivotPosition - 1);
    quickSort(arr, pivotPosition + 1, high);
}

int main() {
    int arr[100];
    int n;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
