#include <stdio.h>

// Define max size for the matrix
#define MAX_ROWS 10
#define MAX_COLS 10

/**
 * @brief Calculates the sum of the four corner elements of a matrix.
 * @param matrix The 2D array.
 * @param r The number of rows.
 * @param c The number of columns.
 * @return The sum of the corner elements.
 */
int CornerSum(int matrix[MAX_ROWS][MAX_COLS], int r, int c) {
    if (r <= 0 || c <= 0) {
        return 0; // Invalid dimensions
    }

    // Case 1: 1x1 matrix (only one corner)
    if (r == 1 && c == 1) {
        return matrix[0][0];
    }
    // Case 2: Row vector (1xN) (two corners)
    else if (r == 1) {
        return matrix[0][0] + matrix[0][c - 1];
    }
    // Case 3: Column vector (Nx1) (two corners)
    else if (c == 1) {
        return matrix[0][0] + matrix[r - 1][0];
    }
    // Case 4: General RxC matrix (four distinct corners)
    else {
        return matrix[0][0] + matrix[0][c - 1] + matrix[r - 1][0] + matrix[r - 1][c - 1];
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int r, c;

    printf("Enter number of rows (1 to %d): ", MAX_ROWS);
    scanf("%d", &r);
    printf("Enter number of columns (1 to %d): ", MAX_COLS);
    scanf("%d", &c);

    if (r <= 0 || c <= 0 || r > MAX_ROWS || c > MAX_COLS) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    // Read matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the corner sum
    int sum = CornerSum(matrix, r, c);
    printf("The sum of the corner elements is: %d\n", sum);

    return 0;
}