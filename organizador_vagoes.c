#include <stdio.h>

unsigned countOptimalSwaps(int arr[], unsigned size);

int main(void) {
    unsigned numCases, trainSize;
    unsigned i;

    scanf("%u", &numCases);

    while (numCases--) {
        scanf("%u", &trainSize);
        int wagons[trainSize];

        for (i = 0; i < trainSize; i++) {
            scanf("%d", &wagons[i]);
        }

        printf("Optimal train swapping takes %u swaps.\n", countOptimalSwaps(wagons, trainSize));
    }

    return 0;
}

unsigned countOptimalSwaps(int arr[], unsigned size) {
    unsigned i, j, swapCount = 0, temp;

    while (size--) {
        for (i = 0, j = 1; i < size; i++, j++) {
            if (arr[i] > arr[j]) {
                swapCount++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return swapCount;
}
