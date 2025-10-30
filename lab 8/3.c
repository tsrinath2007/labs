#include <stdio.h>
#include <stdlib.h>
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);
    int result = GCD(abs(num1), abs(num2));
    printf("GCD of %d and %d is %d.\n", num1, num2, result);
    return 0;
} 