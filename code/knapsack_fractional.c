#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, weight;
    double ratio;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;
    return (r1 < r2) ? 1 : (r1 > r2) ? -1 : 0;
}

double knapsack_fractional(int W, int wt[], int val[], int n) {
    Item *items = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
        items[i].ratio = (double)val[i] / wt[i];
    }
    qsort(items, n, sizeof(Item), cmp);
    double totalValue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].ratio * W;
            W = 0;
        }
    }
    free(items);
    return totalValue;
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
    double result = knapsack_fractional(W, wt, val, n);
    printf("Max value in fractional knapsack: %.2lf\n", result);
    free(val);
    free(wt);
    return 0;
} 