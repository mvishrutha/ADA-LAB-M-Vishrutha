
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX][MAX];

int isSafe(int row, int col, int n) {
    int i, j;

    // Check same column
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int solveNQueens(int row, int n) {
    if (row == n) {
        return 1;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;

            if (solveNQueens(row + 1, n)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input! Enter n between 1 and %d.\n", MAX);
        return 0;
    }

    if (solveNQueens(0, n)) {
        printf("\nSolution for %d-Queens Problem:\n\n", n);
        printBoard(n);
    } else {
        printf("\nNo solution exists for %d queens.\n", n);
    }

    return 0;
}
