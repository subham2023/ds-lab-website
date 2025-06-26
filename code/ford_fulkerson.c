#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// BFS to find if there is a path from source to sink
bool bfs(int **rGraph, int s, int t, int parent[], int V) {
    bool *visited = (bool *)calloc(V, sizeof(bool));
    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    bool found = visited[t];
    free(visited);
    free(queue);
    return found;
}

int fordFulkerson(int **graph, int s, int t, int V) {
    int **rGraph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        rGraph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];
    }
    int *parent = (int *)malloc(V * sizeof(int));
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent, V)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    for (int i = 0; i < V; i++)
        free(rGraph[i]);
    free(rGraph);
    free(parent);
    return max_flow;
}

int main() {
    int V, s, t;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter source vertex (0 to %d): ", V-1);
    scanf("%d", &s);
    printf("Enter sink vertex (0 to %d): ", V-1);
    scanf("%d", &t);
    int **graph = (int **)malloc(V * sizeof(int *));
    printf("Enter the capacity matrix (row-wise):\n");
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    }
    int max_flow = fordFulkerson(graph, s, t, V);
    printf("The maximum possible flow is %d\n", max_flow);
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);
    return 0;
} 