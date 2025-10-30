#include <stdio.h>
long long Fact(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}
int main() {
    int n, r;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);
    if (n < 0 || r < 0 || n < r) {
        printf("Invalid input. Requires n >= r >= 0.\n");
        return 1;
    }
    long long n_fact = Fact(n);
    long long r_fact = Fact(r);
    long long n_minus_r_fact = Fact(n - r);
    if (n_fact == -1 || r_fact == -1 || n_minus_r_fact == -1) {
        printf("Error in factorial calculation.\n");
    } else {
        long long nCr = n_fact / (r_fact * n_minus_r_fact);
        printf("%dC%d = %lld\n", n, r, nCr);
    }
    return 0;
}