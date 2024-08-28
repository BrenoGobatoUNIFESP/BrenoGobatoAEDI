#include <stdio.h>
#include <stdbool.h>

bool checarOrdemCrescente(short *, unsigned short);
bool checarOrdemDecrescente(short *, unsigned short);

int main(void) {
    short sequencia[5];
    unsigned short indice;

    for (indice = 0; indice < 5; indice++)
        scanf("%hd", &sequencia[indice]);

    if (checarOrdemCrescente(sequencia, 5))
        printf("C\n");
    else if (checarOrdemDecrescente(sequencia, 5))
        printf("D\n");
    else
        printf("N\n");

    return 0;
}

bool checarOrdemCrescente(short *array, unsigned short tamanho) {
    unsigned short j;
    bool crescente = true;

    for (j = 1; j < tamanho; j++)
        if (array[j] < array[j - 1]) {
            crescente = false;
            break;
        }

    return crescente;
}

bool checarOrdemDecrescente(short *array, unsigned short tamanho) {
    unsigned short j;
    bool decrescente = true;

    for (j = 1; j < tamanho; j++)
        if (array[j] > array[j - 1]) {
            decrescente = false;
            break;
        }

    return decrescente;
}
