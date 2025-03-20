#include <stdio.h>
#define V 4

void warshall(int graph[V][V]) {
    int reach[V][V], i, j, k;
    // Initialize reachability matrix
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            reach[i][j] = graph[i][j];
    for(k = 0; k < V; k++) {
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(reach[i][j] == 0 && (reach[i][k] && reach[k][j]))
                    reach[i][j] = 1;
            }
        }
    }
    printf("Transitive closure of the given graph:\\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++)
            printf("%d ", reach[i][j]);
        printf("\\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 1}
    };
    warshall(graph);
    return 0;
}
