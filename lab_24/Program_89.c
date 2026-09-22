#include <stdio.h>

int linearSearch(int values[], int count, int target) {
    int i;

    for (i = 0; i < count; i++) {
        if (values[i] == target)
            return i;
    }

    return -1;
}

int main() {
    int values[100];
    int count;
    int target;
    int position;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &+values[i]);

    scanf("%d", &target);

    position = linearSearch(values, count, target);

    if (position == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", position);

    return 0;
}
