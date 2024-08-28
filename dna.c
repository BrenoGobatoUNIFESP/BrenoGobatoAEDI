#include <stdio.h>
#include <string.h>

#define MAX 300

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char rna[MAX + 1];
    int dp[MAX][MAX];
    
    while (scanf("%s", rna) != EOF) {
        int n = strlen(rna);

        // Inicializar a matriz DP
        memset(dp, 0, sizeof(dp));

        // Preencher a matriz DP
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;

                // Caso onde a fita não se dobra neste intervalo
                dp[i][j] = dp[i][j - 1];

                // Verificar se a base atual (rna[j]) pode formar um par com alguma base anterior (rna[k])
                for (int k = i; k < j; k++) {
                    if ((rna[k] == 'B' && rna[j] == 'S') || (rna[k] == 'S' && rna[j] == 'B') ||
                        (rna[k] == 'C' && rna[j] == 'F') || (rna[k] == 'F' && rna[j] == 'C')) {
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j - 1] + 1);
                    }
                }
            }
        }

        // O resultado para a sequência inteira está armazenado em dp[0][n-1]
        printf("%d\n", dp[0][n - 1]);
    }

    return 0;
}
