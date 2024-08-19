#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v1, v2, peso;
} Itinerario;

int compararItinerarios(const void *a, const void *b){
    return((Itinerario *)a)->peso - ((Itinerario *)b)->peso;
}

int find(int parent[], int i){
    if (parent[i] == i)
        return i;
        return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y){
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if(rank[rootX] < rank[rootY]){
        parent[rootX] = rootY;
    }else if(rank[rootX] > rank[rootY]){
        parent[rootY] = rootX;
    }else{
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int kruskal(Itinerario itinerarios[], int m, int n){
    qsort(itinerarios, n, sizeof(Itinerario), compararItinerarios);
    
    int *parent = (int *)malloc(m * sizeof(int));
    int *rank = (int *)malloc(m * sizeof(int));
    
    for (int i = 0; i<m; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    
    int minPeso = 0;
    int arestasUsadas = 0;
    
    for (int i =0; i < n && arestasUsadas < m - 1; i++){
        int v1 = find(parent, itinerarios[i].v1);
        int v2 = find(parent, itinerarios[i].v2);
        
        if(v1 != v2){
            minPeso += itinerarios[i].peso;
            unionSets(parent, rank, v1, v2);
            arestasUsadas++;
        }
    }
    
   free(parent);
   free(rank);
   
   return minPeso;
}

int main(){
    int m, n;
    
    while(1){
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0)
            break;
            
            Itinerario *itinerarios = (Itinerario *)malloc(n * sizeof(Itinerario));
            
            for (int i = 0; i < n; i++){
                scanf(" %d %d %d", &itinerarios[i].v1, &itinerarios[i].v2, &itinerarios[i].peso);
            }
            
            int result = kruskal(itinerarios, m, n);
            printf("%d\n", result);
    }
    
    return 0;
}




