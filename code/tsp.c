#include <stdio.h>
#include <stdbool.h>
#define N 4
#define INF 99999

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[N];

int tsp(int currPos, int n, int count, int cost, int ans) {
    if (count == n && graph[currPos][0]) {
        if (cost + graph[currPos][0] < ans)
            ans = cost + graph[currPos][0];
        return ans;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            ans = tsp(i, n, count + 1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    for (int i = 0; i < N; i++) visited[i] = false;
    visited[0] = true;
    int ans = tsp(0, N, 1, 0, INF);
    printf("Minimum cost of TSP: %d\n", ans);
    return 0;
} 