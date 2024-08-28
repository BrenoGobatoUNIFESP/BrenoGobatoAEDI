#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int N;
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break; // Fim da entrada

        while (1) {
            int train[MAX];
            int i;

            // Ler a permutação desejada
            scanf("%d", &train[0]);
            if (train[0] == 0) break; // Fim do bloco

            for (i = 1; i < N; i++) {
                scanf("%d", &train[i]);
            }

            int stack[MAX];
            int top = -1;
            int current = 1; // O vagão esperado na ordem crescente

            int possible = 1; // Flag para verificar se é possível a permutação

            for (i = 0; i < N; i++) {
                while (current <= N && current != train[i]) {
                    stack[++top] = current++; // Empilhar os vagões
                }

                if (current == train[i]) {
                    current++; // Avança para o próximo vagão
                } else if (top >= 0 && stack[top] == train[i]) {
                    top--; // Desempilhar se o topo corresponde ao vagão desejado
                } else {
                    possible = 0; // Não é possível alcançar a permutação desejada
                    break;
                }
            }

            if (possible) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n"); // Linha em branco após cada bloco
    }

    return 0;
}
