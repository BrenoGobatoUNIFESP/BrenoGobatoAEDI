#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int N, i, j;
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        char frase[201];
        fgets(frase, sizeof(frase), stdin); 
        int frequencia[26] = {0};
        for (j = 0; frase[j] != '\0'; j++) {
            if (isalpha(frase[j])) {
                char letra = tolower(frase[j]);
                frequencia[letra - 'a']++;
            }
        }
        int maior = 0;
        for (j = 0; j < 26; j++) {
            if (frequencia[j] > maior) {
                maior = frequencia[j];
            }
        }
        for (int j = 0; j < 26; j++) {
            if (frequencia[j] == maior) {
                printf("%c", 'a' + j);
            }
        }
        printf("\n");
    }
}
