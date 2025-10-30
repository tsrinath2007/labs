#include <stdio.h>
#include <stdlib.h> // For abs()

/**
 * @brief Finds the GCD of two numbers using the recursive Euclidean algorithm.
 * @param a The first number.
 * @param b The second number.
 * @return The Greatest Common Divisor (GCD) of a and b.
 */
int GCD(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    // Recursive step
    return GCD(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    // GCD is usually defined for positive integers.
    // We use abs() to handle any negative inputs correctly.
    int result = GCD(abs(num1), abs(num2));

    printf("GCD of %d and %d is %d.\n", num1, num2, result);
    
    // Test with the example from the prompt
    printf("Ex: GCD of 9 and 24 is %d\n", GCD(9, 24));

    return 0;
}