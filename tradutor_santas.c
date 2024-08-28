#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PAISES 24

const char *paises[NUM_PAISES] = {
    "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", 
    "estados-unidos", "inglaterra", "australia", "portugal", "suecia", 
    "turquia", "argentina", "chile", "mexico", "antardida", "canada", 
    "irlanda", "belgica", "italia", "libia", "siria", "marrocos", "japao"
};

const char *saudacoes[NUM_PAISES] = {
    "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!", 
    "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", 
    "Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", 
    "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", 
    "Merry Christmas!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", "Buon Natale!", 
    "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"
};

typedef struct {
    char pais[50];
    char saudacao[100];
} Tradutor;

Tradutor traducao[NUM_PAISES];

void preencheTradutor();
bool pesquisaPais(const char *pais, unsigned short *posicao);

int main() {
    preencheTradutor();
    char pais[100];

    while (scanf("%99s", pais) != EOF) {
        unsigned short posicao;
        if (pesquisaPais(pais, &posicao))
            printf("%s\n", traducao[posicao].saudacao);
        else
            printf("--- NOT FOUND ---\n");
    }

    return 0;
}

void preencheTradutor() {
    for (unsigned short i = 0; i < NUM_PAISES; i++) {
        strncpy(traducao[i].pais, paises[i], sizeof(traducao[i].pais) - 1);
        strncpy(traducao[i].saudacao, saudacoes[i], sizeof(traducao[i].saudacao) - 1);
        traducao[i].pais[sizeof(traducao[i].pais) - 1] = '\0';
        traducao[i].saudacao[sizeof(traducao[i].saudacao) - 1] = '\0';
    }
}

bool pesquisaPais(const char *pais, unsigned short *posicao) {
    for (unsigned short i = 0; i < NUM_PAISES; i++) {
        if (strcmp(traducao[i].pais, pais) == 0) {
            *posicao = i;
            return true;
        }
    }
    return false;
}
