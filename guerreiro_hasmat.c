#include <stdio.h>

int main() {
    unsigned int hashmat, opponent;

    // Enquanto for possível ler dois números, processamos
    while (scanf("%u %u", &hashmat, &opponent) != EOF) {
        // Calcula a diferença absoluta entre os dois números
        unsigned int difference;
        if (hashmat > opponent) {
            difference = hashmat - opponent;
        } else {
            difference = opponent - hashmat;
        }
        printf("%u\n", difference);
    }

    return 0;
}
