#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    int **a = (int **)malloc(r1 * sizeof(int *));
    int **b = (int **)malloc(r2 * sizeof(int *));
    int **c = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        a[i] = (int *)malloc(c1 * sizeof(int));
        c[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r2; i++) {
        b[i] = (int *)malloc(c2 * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Initialize result matrix
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            c[i][j] = 0;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];

    printf("Product of matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    for (int i = 0; i < r1; i++) {
        free(a[i]);
        free(c[i]);
    }
    for (int i = 0; i < r2; i++) {
        free(b[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}