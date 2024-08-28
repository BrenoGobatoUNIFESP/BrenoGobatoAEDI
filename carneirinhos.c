#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void quickSort(long long *array, unsigned size);
void quickSortInternal(long long *array, long start, long end);

int main() {
    unsigned testCases, i;
    unsigned sheepsCount;
    unsigned seenCount;

    scanf("%u", &testCases);

    while (testCases--) {
        scanf("%u", &sheepsCount);
        long long sheeps[sheepsCount];

        for (i = 0; i < sheepsCount; i++)
            scanf("%lld", &sheeps[i]);

        quickSort(sheeps, sheepsCount);

        seenCount = 0;
        for (i = 0; i < sheepsCount; i++)
            if (sheeps[i + 1] != sheeps[i])
                seenCount++;

        printf("%u\n", seenCount);
    }

    return 0;
}

void quickSortInternal(long long *array, long start, long end) {
    long long pivot, temp;
    long i, j;

    if (end - start > 0) {
        i = start;
        j = end;
        pivot = array[(i + j) / 2];

        do {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;

            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);

        quickSortInternal(array, start, j);
        quickSortInternal(array, i, end);
    }
}

void quickSort(long long *array, unsigned size) {
    quickSortInternal(array, 0, size - 1);
}
