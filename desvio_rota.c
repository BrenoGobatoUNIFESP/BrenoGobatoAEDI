#include <stdio.h>
#include <limits.h>

#define MAXN 250
#define INF INT_MAX

// Estrutura para representar uma aresta no grafo
typedef struct {
    int v, p;
} Edge;

// Estrutura para o par de cidade e custo para a fila de prioridade
typedef struct {
    int city, cost;
} HeapNode;

// Estrutura da fila de prioridade (min-heap)
typedef struct {
    HeapNode heap[MAXN * MAXN];
    int size;
} PriorityQueue;

// Funções de manipulação da fila de prioridade
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue *pq, int city, int cost) {
    pq->heap[pq->size].city = city;
    pq->heap[pq->size].cost = cost;
    int i = pq->size;
    pq->size++;
    while (i > 0 && pq->heap[(i - 1) / 2].cost > pq->heap[i].cost) {
        swap(&pq->heap[(i - 1) / 2], &pq->heap[i]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(PriorityQueue *pq) {
    HeapNode minNode = pq->heap[0];
    pq->size--;
    pq->heap[0] = pq->heap[pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) {
        int smallest = i * 2 + 1;
        if (smallest + 1 < pq->size && pq->heap[smallest + 1].cost < pq->heap[smallest].cost) {
            smallest++;
        }
        if (pq->heap[i].cost <= pq->heap[smallest].cost) break;
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return minNode;
}

// Implementação do algoritmo de Dijkstra modificado
int dijkstra(int N, int M, int C, int K, Edge graph[MAXN][MAXN], int degree[MAXN]) {
    int dist[MAXN];
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[K] = 0;

    PriorityQueue pq;
    pq.size = 0;
    push(&pq, K, 0);

    while (pq.size > 0) {
        HeapNode node = pop(&pq);
        int u = node.city;
        int d = node.cost;

        if (d > dist[u]) continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i].v;
            int p = graph[u][i].p;
            int newDist = d + p;

            // Se estamos dentro da rota de serviço e indo para a próxima cidade na rota
            if (u < C - 1 && v == u + 1) {
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(&pq, v, newDist);
                }
            } 
            // Se estamos fora da rota de serviço ou já atingimos o fim da rota obrigatória
            else if (u >= C || v >= C) {
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(&pq, v, newDist);
                }
            }
        }
    }

    return dist[C - 1];
}

int main() {
    int N, M, C, K;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        Edge graph[MAXN][MAXN];
        int degree[MAXN] = {0};

        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            graph[U][degree[U]].v = V;
            graph[U][degree[U]].p = P;
            degree[U]++;
            graph[V][degree[V]].v = U;
            graph[V][degree[V]].p = P;
            degree[V]++;
        }

        int result = dijkstra(N, M, C, K, graph, degree);
        printf("%d\n", result);
    }

    return 0;
}
