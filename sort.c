#include <stdio.h>
#include <stdlib.h>

int M;  // Variável global para armazenar o valor de M

// Função de comparação personalizada
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    int mod1 = num1 % M;
    int mod2 = num2 % M;

    // Comparar pelos módulos
    if (mod1 != mod2) {
        return mod1 - mod2;
    }

    // Se os módulos são iguais, comparar ímpares e pares
    int isOdd1 = num1 % 2 != 0;
    int isOdd2 = num2 % 2 != 0;

    // Se um é ímpar e o outro é par, o ímpar vem primeiro
    if (isOdd1 != isOdd2) {
        return isOdd2 - isOdd1;
    }

    // Se ambos são ímpares, o maior ímpar vem primeiro
    if (isOdd1 && isOdd2) {
        return num2 - num1;
    }

    // Se ambos são pares, o menor par vem primeiro
    if (!isOdd1 && !isOdd2) {
        return num1 - num2;
    }

    return 0;
}

int main() {
    int N;

    while (1) {
        // Ler N e M
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            printf("0 0\n");
            break;
        }

        int numbers[N];

        // Ler os números
        for (int i = 0; i < N; i++) {
            scanf("%d", &numbers[i]);
        }

        // Ordenar os números usando a função de comparação personalizada
        qsort(numbers, N, sizeof(int), compare);

        // Imprimir o resultado
        printf("%d %d\n", N, M);
        for (int i = 0; i < N; i++) {
            printf("%d\n", numbers[i]);
        }
    }

    return 0;
}
