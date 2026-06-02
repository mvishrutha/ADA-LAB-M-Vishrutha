#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int indegree[2000] = {0};
    int graph[2000][2000] = {0};
    int visited[2000] = {0};

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][a] = 1;
        indegree[a]++;
    }

    int count = 0;

    while (count < numCourses) {
        int found = -1;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            return false;
        }

        visited[found] = 1;
        count++;

        for (int j = 0; j < numCourses; j++) {
            if (graph[found][j]) {
                indegree[j]--;
            }
        }
    }

    return true;
}
