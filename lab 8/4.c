#include <stdio.h>

/**
 * @brief Finds the nth term of the Fibonacci sequence recursively.
 * Uses 0-based indexing (0th term = 0, 1st term = 1).
 * @param n The index of the term to find (n >= 0).
 * @return The nth Fibonacci number.
 */
long long FIB(int n) {
    // Base case 1: 0th term
    if (n <= 0) {
        return 0;
    }
    // Base case 2: 1st term
    else if (n == 1) {
        return 1;
    }
    // Recursive step: F(n) = F(n-1) + F(n-2)
    else {
        return FIB(n - 1) + FIB(n - 2);
    }
}

int main() {
    int N;
    printf("Enter the number of Fibonacci terms (N) to print: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    printf("The first %d Fibonacci terms are:\n", N);
    
    // Loop from 0 to N-1 to print the first N terms
    for (int i = 0; i < N; i++) {
        printf("%lld ", FIB(i));
    }
    printf("\n");

    return 0;
}