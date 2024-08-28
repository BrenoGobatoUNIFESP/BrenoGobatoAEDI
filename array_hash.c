#include <stdio.h>
#include <string.h>

int main() {
    int n;  // Número de casos de teste
    scanf("%d", &n);

    while (n--) {
        int l;  // Número de linhas em cada caso de teste
        scanf("%d", &l);

        int hash_value = 0;  // Variável para armazenar o valor de hash

        for (int i = 0; i < l; i++) {
            char str[51];  // Buffer para a string (máximo 50 caracteres)
            scanf("%s", str);
            
            int length = strlen(str);

            for (int j = 0; j < length; j++) {
                // Calcula o valor do caractere e o adiciona ao hash_value
                int char_value = (str[j] - 'A') + i + j;
                hash_value += char_value;
            }
        }

        // Imprime o valor do hash para o caso de teste atual
        printf("%d\n", hash_value);
    }

    return 0;
}
