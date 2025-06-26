#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int **board, int N, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQUtil(int **board, int N, int col) {
    if (col == N) {
        printSolution(board, N);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, N, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, N, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQ(int N) {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)calloc(N, sizeof(int));
    if (!solveNQUtil(board, N, 0))
        printf("Solution does not exist\n");
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
} 