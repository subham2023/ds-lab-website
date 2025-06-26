#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **a = (int **)malloc(rows * sizeof(int *));
    int **b = (int **)malloc(rows * sizeof(int *));
    int **c = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        a[i] = (int *)malloc(cols * sizeof(int));
        b[i] = (int *)malloc(cols * sizeof(int));
        c[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("Sum of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}