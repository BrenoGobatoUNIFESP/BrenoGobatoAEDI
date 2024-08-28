#include <stdio.h>

#define verdadeiro 1
#define falso 0

int main (int argc, char **argv)
{

    int n, m;
    scanf("%d %d", &n, &m);

    if (n > m || n == m)
    {

        if (m >= 97)
            printf("cheia\n");
        else if (m <= 96 && m >= 3)
            printf("minguante\n");
        else
            printf("nova\n");

    }
    else
    {

        if (m <= 2)
            printf("nova\n");
        else if (m <= 96)
            printf("crescente\n");
        else if (m <= 100)
            printf("cheia\n");

    }
    return 0;

}
