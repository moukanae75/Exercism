#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

int board[N][N];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%s ", board[i][j] ? "Q" : ".");
        }
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    int i, j;

    // Check the row on the left
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool solveNQ() {
    if (solveNQUtil(0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution();
    return true;
}

int main() {
    solveNQ();
    return 0;
}
