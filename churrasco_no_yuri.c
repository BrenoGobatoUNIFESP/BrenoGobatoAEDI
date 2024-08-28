#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 21
#define MAX_PECA 10

typedef struct {
    char nome[MAX_NOME];
    int validade;
} Peca;

// A função comparar agora usa diretamente ponteiros para Peca
int comparar(Peca* a, Peca* b) {
    return a->validade - b->validade;
}

// Função de comparação adaptada para qsort
int comparar_wrapper(const void *a, const void *b) {
    return comparar((Peca*)a, (Peca*)b);
}


int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        Peca pecas[MAX_PECA];
        for (int i = 0; i < N; ++i) {
            scanf("%s %d", pecas[i].nome, &pecas[i].validade);
        }
        qsort(pecas, N, sizeof(Peca), comparar_wrapper);
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                printf(" ");
            }
            printf("%s", pecas[i].nome);
        }
        printf("\n");
    }
    return 0;
}
