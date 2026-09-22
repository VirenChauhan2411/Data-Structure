#include <stdio.h>

void insertionSort(int val[], int count) {
    int i;
    int j;
    int current;

    for (i = 1; i < count; i++) {
        current = val[i];
        j = i - 1;

        while (j >= 0 && val[j] > current) {
            val[j + 1] = val[j];
            j--;
        }

        val[j + 1] = current;
    }
}

int main() {
    int val[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &val[i]);

    insertionSort(val, count);

    for (i = 0; i < count; i++)
        printf("%d ", val[i]);

    return 0;
}
