#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[13];
    struct No* proximo;
} No;
No* criarNo(char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNo(No** cabeca, char* nome) {
    No* novoNo = criarNo(nome);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        novoNo->proximo = novoNo; 
    } else {
        No* temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
        novoNo->proximo = *cabeca;
    }
}
void liberarLista(No* cabeca) {
    if (cabeca == NULL) return;
    No* temp = cabeca;
    No* proximoNo;
    do {
        proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    } while (temp != cabeca);
}

int main() {
    int N;
    float L; 
    float Q;
    No* cabeca = NULL;
    scanf("%d", &N);
    scanf("%f %f", &L, &Q);
    
    for (int i = 0; i < N; i++) {
        char nome[13];
        scanf("%s", nome);
        inserirNo(&cabeca, nome);
    }
    No* atual = cabeca;
    while (L > Q) {
        L -= Q;
        atual = atual->proximo;
    }
    printf("%s %.1f\n", atual->nome, L);
    liberarLista(cabeca);

    return 0;
}
