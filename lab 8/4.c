#include <stdio.h>
long long FIB(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
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
    for (int i = 0; i < N; i++) {
        printf("%lld ", FIB(i));
    }
    printf("\n");
    return 0;
}