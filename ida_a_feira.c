#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    double preco;
} Produto;

// Função que calcula o custo total das compras
double calcular_custo(Produto produtos[], int num_produtos, Produto compras[], int num_compras) {
    double custo_total = 0.0;
    for (int i = 0; i < num_compras; i++) {
        for (int j = 0; j < num_produtos; j++) {
            if (strcmp(compras[i].nome, produtos[j].nome) == 0) {
                custo_total += produtos[j].preco * compras[i].preco;
            }
        }
    }
    return custo_total;
}

int main() {
    int N; 
    scanf("%d", &N);
    while (N--) {
        int M; 
        scanf("%d", &M);
        Produto produtos[M];
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }
        int P; 
        scanf("%d", &P);
        Produto compras[P];
        for (int i = 0; i < P; i++) {
            scanf("%s %lf", compras[i].nome, &compras[i].preco);
        }
        double custo = calcular_custo(produtos, M, compras, P);
        printf("R$ %.2f\n", custo);
    }
    return 0;
}
