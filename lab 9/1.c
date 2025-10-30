#include <stdio.h>
int main() {
    int arr[100];
    int n, i;
    int *ptr;
    int max;
    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 1;
    }
    ptr = arr;
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (ptr + i)); 
    }
    max = *ptr;
    for (i = 1; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
    printf("The maximum number in the array is: %d\n", max);
    return 0;
}