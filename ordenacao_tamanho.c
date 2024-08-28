#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 60
#define MAX_TEXTO 3000

typedef struct {
    char texto[MAX_TEXTO];
} String;

void ordenarPorTamanho(String palavras[], unsigned count);

int main() {
    unsigned short casos;
    char entrada[MAX_TEXTO];

    scanf("%hu", &casos);

    while (casos--) {
        String palavras[MAX_PALAVRAS];
        unsigned short i = 0, j = 0;

        memset(palavras, 0, sizeof(palavras));
        scanf(" %[^\n]", entrada);

        char *token = strtok(entrada, " ");
        while (token != NULL) {
            strncpy(palavras[i++].texto, token, sizeof(palavras[i].texto) - 1);
            token = strtok(NULL, " ");
        }

        ordenarPorTamanho(palavras, i);

        for (unsigned short k = 0; k < i; k++) {
            if (k > 0) {
                printf(" ");
            }
            printf("%s", palavras[k].texto);
        }
        printf("\n");
    }

    return 0;
}

void ordenarPorTamanho(String palavras[], unsigned count) {
    for (unsigned i = 0; i < count - 1; i++) {
        for (unsigned j = i + 1; j < count; j++) {
            if (strlen(palavras[i].texto) < strlen(palavras[j].texto)) {
                String temp = palavras[i];
                palavras[i] = palavras[j];
                palavras[j] = temp;
            }
        }
    }
}
