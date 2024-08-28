#include <stdio.h>

#define MAXSIZE 100100

unsigned vet[MAXSIZE];

int buscaBinaria(int chave, int tamanho);

int main()
{
    unsigned n, i, tmp, somaTotal;
    scanf("%u", &n);

    unsigned soma = 0;
    somaTotal = 0;
    scanf("%u", &vet[0]);
    somaTotal += vet[0];

    for (i = 1; i < n; ++i)
    {
        scanf("%u", &tmp);
        vet[i] = vet[i - 1] + tmp;
        somaTotal += tmp;
    }

    printf("%u\n", buscaBinaria(somaTotal / 2, n) + 1);

    return 0;
}

int buscaBinaria(int chave, int tamanho)
{
    int baixo = 0, alto = tamanho - 1, meio;

    while (alto > baixo)
    {
        meio = baixo + ((alto - baixo) / 2);
        if (vet[meio] < chave)
            baixo = meio + 1;
        else
            alto = meio;
    }

    return baixo;
}
