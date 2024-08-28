#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta no grafo
typedef struct {
    int v, w, p;
} Edge;

// Função de comparação usada para ordenar as arestas pelo custo
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->p - edgeB->p;
}

// Funções para encontrar e unir conjuntos (usadas na Union-Find)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    Edge edges[C];
    
    // Leitura das arestas
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &edges[i].v, &edges[i].w, &edges[i].p);
    }

    // Ordena as arestas pelo custo
    qsort(edges, C, sizeof(Edge), compareEdges);

    // Estruturas auxiliares para o Union-Find
    int parent[R + 1];
    int rank[R + 1];

    for (int i = 1; i <= R; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    int edgesUsed = 0;

    // Itera sobre as arestas ordenadas
    for (int i = 0; i < C && edgesUsed < R - 1; i++) {
        int v = edges[i].v;
        int w = edges[i].w;
        int p = edges[i].p;

        if (find(parent, v) != find(parent, w)) {
            unionSets(parent, rank, v, w);
            totalCost += p;
            edgesUsed++;
        }
    }

    printf("%d\n", totalCost);
    return 0;
}
