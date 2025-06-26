#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack_01(int W, int wt[], int val[], int n) {
    int **K = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        K[i] = (int *)malloc((W+1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    int result = K[n][W];
    for (int i = 0; i <= n; i++)
        free(K[i]);
    free(K);
    return result;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));
    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int result = knapsack_01(W, wt, val, n);
    printf("Max value in 0/1 knapsack: %d\n", result);
    free(val);
    free(wt);
    return 0;
} 