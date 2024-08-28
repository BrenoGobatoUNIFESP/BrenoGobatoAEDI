#include <stdio.h>

int main(void) {
    unsigned int satisfeitos = 0, insatisfeitos = 0;
    unsigned int totalCidadaos, index, feedback;

    scanf("%u", &totalCidadaos);

    for (index = 0; index < totalCidadaos; index++) {
        scanf("%u", &feedback);

        if (feedback == 0) {
            satisfeitos++;
        } else {
            insatisfeitos++;
        }
    }

    if (satisfeitos > insatisfeitos) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
