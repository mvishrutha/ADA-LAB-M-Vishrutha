#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int solutionCount = 0;

int isSafe(int row, int col, int n) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

void printBoard(int n) {
    printf("\nSolution %d:\n", ++solutionCount);

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

void solveNQueens(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;

            solveNQueens(row + 1, n);

            board[row][col] = 0;   // backtrack
        }
    }
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input!\n");
        return 0;
    }

    solveNQueens(0, n);

    if (solutionCount == 0)
        printf("\nNo solution exists.\n");
    else
        printf("\nTotal Solutions = %d\n", solutionCount);

    return 0;
}
