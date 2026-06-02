#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

void topologicalSort() {
    int front = 0, rear = 0;
    int count = 0;
    int i, j;

    // Calculate indegree of each vertex
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++) {
            indegree[i] += graph[j][i];
        }
    }

    // Insert all vertices with indegree 0 into queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("\nTopological Ordering: ");

    while(front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        count++;

        // Update indegrees of adjacent vertices
        for(i = 0; i < n; i++) {
            if(graph[vertex][i] == 1) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != n) {
        printf("\nGraph contains a cycle. Topological sorting not possible.");
    }

    printf("\n");
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
