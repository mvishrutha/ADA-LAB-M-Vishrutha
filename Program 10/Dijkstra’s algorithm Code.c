#include <stdio.h>

#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int visited[MAX];
int dist[MAX];

void dijkstra(int n, int source) {
    int i, j, u, min;

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] &&
               graph[u][j] != 0 &&
               dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int n, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
