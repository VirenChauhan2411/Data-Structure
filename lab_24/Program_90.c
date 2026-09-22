#include <stdio.h>

int binarySearchIterative(int values[], int count, int target) {
    int left;
    int right;
    int middle;

    left = 0;
    right = count - 1;

    while (left <= right) {
        middle = (left + right) / 2;

        if (values[middle] == target)
            return middle;

        if (target < values[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}

int binarySearchRecursive(int values[], int left,
                          int right, int target) {
    int middle;

    if (left > right)
        return -1;

    middle = (left + right) / 2;

    if (values[middle] == target)
        return middle;

    if (target < values[middle])
        return binarySearchRecursive(
            values, left, middle - 1, target);

    return binarySearchRecursive(
        values, middle + 1, right, target);
}

int main() {
    int values[100];
    int count;
    int target;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &values[i]);

    scanf("%d", &target);

    printf("Iterative = %d\n",
           binarySearchIterative(values, count, target));

    printf("Recursive = %d\n",
           binarySearchRecursive(values, 0, count - 1, target));

    return 0;
}
