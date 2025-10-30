#include <stdio.h>

/**
 * @brief Swaps the values of two integers using pointers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    int temp;
    
    // 1. Store the value at address 'a' in temp
    temp = *a;
    
    // 2. Store the value at address 'b' into address 'a'
    *a = *b;
    
    // 3. Store the value from temp into address 'b'
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nBefore swap: num1 = %d, num2 = %d\n", num1, num2);

    // Pass the addresses of num1 and num2 to the swap function
    swap(&num1, &num2);

    printf("After swap:  num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}