#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
int CornerSum(int matrix[MAX_ROWS][MAX_COLS], int r, int c) {
    if (r <= 0 || c <= 0) {
        return 0;
    }
    if (r == 1 && c == 1) {
        return matrix[0][0];
    }
    else if (r == 1) {
        return matrix[0][0] + matrix[0][c - 1];
    }
    else if (c == 1) {
        return matrix[0][0] + matrix[r - 1][0];
    }
    else {
        return matrix[0][0] + matrix[0][c - 1] + matrix[r - 1][0] + matrix[r - 1][c - 1];
    }
}
int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int r, c;
    printf("Enter number of rows and cols (1 to %d): ", MAX_ROWS);
    scanf("%d %d", &r,&c);
    if (r <= 0 || c <= 0 || r > MAX_ROWS || c > MAX_COLS) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int sum = CornerSum(matrix, r, c);
    printf("The sum of the corner elements is: %d\n", sum);
    return 0;
}