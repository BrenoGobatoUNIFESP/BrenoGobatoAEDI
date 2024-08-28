#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b);
bool binarySearch(unsigned *, unsigned, unsigned short);
int foundPosition;

void main ()
{
    unsigned short i, caseNumber = 0;
    unsigned short queryCount;
    unsigned marbleCount, targetNumber;

    while (true)
    {
        scanf("%u %hu", &marbleCount, &queryCount);

        if (queryCount == 0 && marbleCount == 0)
            break;

        unsigned marbles[marbleCount];

        for (i = 0; i < marbleCount; i++)
            scanf("%u", &marbles[i]);

        qsort(marbles, marbleCount, sizeof(unsigned), compare);

        printf("CASE# %u:\n", ++caseNumber);
        while (queryCount--)
        {
            scanf("%u", &targetNumber);

            if (binarySearch(marbles, targetNumber, marbleCount))
            {
                if (marbles[foundPosition - 1] == marbles[foundPosition])
                {
                    while (marbles[foundPosition - 1] == marbles[foundPosition])
                        foundPosition--;

                    printf("%u found at %u\n", targetNumber, foundPosition + 1);
                }
                else
                    printf("%u found at %u\n", targetNumber, foundPosition + 1);
            }
            else
                printf("%u not found\n", targetNumber);
        }
    }
}

int compare(const void *a, const void *b)
{
    return (*(unsigned*)a - *(unsigned*)b);
}

bool binarySearch(unsigned *marbles, unsigned target, unsigned short size)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (marbles[mid] < target)
            low = mid + 1;
        else if (marbles[mid] > target)
            high = mid - 1;
        else
        {
            foundPosition = mid;
            return true;
        }
    }

    return false;
}
