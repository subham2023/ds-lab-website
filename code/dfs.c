#include <stdio.h>
#define N 5

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

void dfsUtil(int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < N; i++) {
        if (graph[node][i] && !visited[i])
            dfsUtil(i, visited);
    }
}

void dfs(int start) {
    int visited[N] = {0};
    printf("DFS traversal: ");
    dfsUtil(start, visited);
    printf("\n");
}

int main() {
    dfs(0);
    return 0;
} 