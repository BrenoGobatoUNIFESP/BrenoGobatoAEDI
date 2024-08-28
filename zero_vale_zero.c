#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeZeros(char *str) {
  int i = 0, j = 0;

  while (str[i] != '\0') {
    if (str[i] != '0') {
      str[j++] = str[i];
    }
    i++;
  }
  str[j] = '\0';
}

int main() {
  while (1) {
    int M, N, soma;
    char somaStr[20];
    scanf("%d %d", &M, &N);
    if (M == 0 && N == 0) {
      break;
    }
    soma = M + N;
    sprintf(somaStr, "%d", soma);
    removeZeros(somaStr);
    printf("%s\n", somaStr);
  }

  return 0;
}
