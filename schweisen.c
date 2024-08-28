#include <stdio.h>
#include <string.h>

#define MAX 1000

int prefix_sum[MAX + 1][MAX + 1];

// Função para atualizar a matriz de prefixo
void update_prefix_sum(int x, int y, int value, int width, int height) {
    for (int i = x; i <= width; i++) {
        for (int j = y; j <= height; j++) {
            prefix_sum[i + 1][j + 1] += value;
        }
    }
}

// Função para consultar a soma de uma submatriz
int query_sum(int x1, int y1, int x2, int y2) {
    return prefix_sum[x2 + 1][y2 + 1]
         - prefix_sum[x1][y2 + 1]
         - prefix_sum[x2 + 1][y1]
         + prefix_sum[x1][y1];
}

int main() {
    int width, height, price;
    
    while (1) {
        scanf("%d %d %d", &width, &height, &price);
        if (width == 0 && height == 0 && price == 0) break;

        // Inicializa a matriz de prefixo
        memset(prefix_sum, 0, sizeof(prefix_sum));

        int queries;
        scanf("%d", &queries);

        for (int i = 0; i < queries; i++) {
            char type;
            scanf(" %c", &type);
            if (type == 'A') {
                int n, x, y;
                scanf("%d %d %d", &n, &x, &y);
                update_prefix_sum(x, y, n, width - 1, height - 1);
            } else if (type == 'P') {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int total_schweisen = query_sum(x1, y1, x2, y2);
                printf("%d\n", total_schweisen * price);
            }
        }
        
        printf("\n"); // Linha em branco após cada caso de teste
    }
    
    return 0;
}
