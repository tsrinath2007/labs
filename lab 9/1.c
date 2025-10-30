#include <stdio.h>

int main() {
    int arr[100];
    int n, i;
    int *ptr; // Declare an integer pointer
    int max;

    // Get the size of the array
    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 1;
    }

    // Point 'ptr' to the first element of the array
    ptr = arr; // or ptr = &arr[0]

    // Read elements into the array using the pointer
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        // (ptr + i) is the address of the i-th element
        // *(ptr + i) is the value at that address
        scanf("%d", (ptr + i)); 
    }

    // Find the maximum element
    // Assume the first element is the max
    max = *ptr; // *ptr is the value at arr[0]

    // Loop from the second element (i=1)
    for (i = 1; i < n; i++) {
        // Compare max with the value at the i-th element
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    // Print the result
    printf("The maximum number in the array is: %d\n", max);

    return 0;
}