#include <stdio.h>

void merge(int val[], int l, int m, int right) {
    int temp[100];
    int f;
    int s;
    int pos;
    int i;

    f = l;
    s = m + 1;
    pos = 0;

    while (f <= m && s <= right) {
        if (val[f] <= val[s])
            temp[pos++] = val[f++];
        else
            temp[pos++] = val[s++];
    }

    while (f <= m)
        temp[pos++] = val[f++];

    while (s <= right)
        temp[pos++] = val[s++];

    for (i = 0; i < pos; i++)
        val[l + i] = temp[i];
}

void mergeSort(int val[], int l, int right) {
    int m;

    if (l >= right)
        return;

    m = (l + right) / 2;

    mergeSort(val, l, m);
    mergeSort(val, m + 1, right);

    merge(val, l, m, right);
}

int main() {
    int val[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &val[i]);

    mergeSort(val, 0, count - 1);

    for (i = 0; i < count; i++)
        printf("%d ", val[i]);

    return 0;
}
