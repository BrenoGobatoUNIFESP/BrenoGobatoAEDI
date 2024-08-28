#include <stdio.h>

int main(void)
{
    int n, bonus;

    scanf("%i", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%i", &bonus);

        int a1, d1, b1, a2, d2, b2;
        scanf("%i %i %i %i %i %i", &a1, &d1, &b1, &a2, &d2, &b2);

        int v1 = (a1 + d1) / 2 + (b1 % 2 == 0 ? bonus : 0);
        int v2 = (a2 + d2) / 2 + (b2 % 2 == 0 ? bonus : 0);

        if (v1 == v2)
            printf("Empate\n");
        else if (v1 > v2)
            printf("Dabriel\n");
        else
            printf("Guarte\n");
    }

    return 0;
}
