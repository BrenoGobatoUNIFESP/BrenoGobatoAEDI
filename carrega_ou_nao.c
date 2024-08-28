#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0

char lerNumero(int *num);
void imprimirNumero(unsigned n);

int main()
{
    unsigned a, b;

    while (lerNumero(&a) != EOF)
    {
        lerNumero(&b);
        imprimirNumero(a ^ b);
    }

    return 0;
}

inline char lerNumero(int *num)
{
    register char c = 0;
    *num = 0;
    c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        *num = *num * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return c;
}

inline void imprimirNumero(unsigned n)
{
    char indice = 10;
    char bufferSaida[11];
    bufferSaida[10] = '\n';
    do
    {
        bufferSaida[--indice] = (n % 10) + '0';
        n /= 10;
    } while (n);

    do
    {
        putchar_unlocked(bufferSaida[indice]);
    } while (++indice < 11);
}
