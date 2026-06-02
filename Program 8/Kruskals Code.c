#include <stdio.h>

#define MAX 20

// Structure to store edges
struct Edge
{
    int src, dest, weight;
};

// Structure for Disjoint Set
struct Subset
{
    int parent;
};

// Find function
int find(struct Subset subsets[], int i)
{
    while (subsets[i].parent != i)
    {
        i = subsets[i].parent;
    }
    return i;
}

// Union function
void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    subsets[xroot].parent = yroot;
}

// Sort edges by weight
void sortEdges(struct Edge edges[], int e)
{
    struct Edge temp;

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm
void kruskalMST(struct Edge edges[], int V, int E)
{
    struct Edge result[MAX];
    struct Subset subsets[MAX];

    int e = 0;
    int i = 0;
    int totalCost = 0;

    // Initialize subsets
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
    }

    // Sort edges
    sortEdges(edges, E);

    // Process edges
    while (e < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Include edge if it does not form a cycle
        if (x != y)
        {
            result[e++] = nextEdge;
            totalCost += nextEdge.weight;

            Union(subsets, x, y);
        }
    }

    // Print MST
    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e; i++)
    {
        printf("%d -- %d == %d\n",
               result[i].src,
               result[i].dest,
               result[i].weight);
    }

    printf("\nMinimum Cost = %d\n", totalCost);
}

int main()
{
    int V, E;

    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter source destination weight for each edge:\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    printf("\nKruskal's Algorithm - Minimum Cost Spanning Tree\n");

    kruskalMST(edges, V, E);

    return 0;
}

