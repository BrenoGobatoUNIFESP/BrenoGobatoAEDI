#include <stdio.h>

#define TRUE 1
#define FALSE 0

int countUniqueDigitNumbers(int start, int end);

int main() {
    int start, end;

    while (scanf("%d %d", &start, &end) != EOF) {
        printf("%d\n", countUniqueDigitNumbers(start, end));
    }

    return 0;
}

int countUniqueDigitNumbers(int start, int end) {
    unsigned short i, current;
    unsigned short uniqueCount = 0;

    for (i = start; i <= end; ++i) {
        current = i;
        _Bool digits[10] = { FALSE };
        while (current) {
            if (digits[current % 10]) {
                break;
            }
            digits[current % 10] = TRUE;
            current /= 10;
        }

        if (current == 0) {
            ++uniqueCount;
        }
    }

    return uniqueCount;
}
