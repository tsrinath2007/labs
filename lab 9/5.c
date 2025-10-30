#include <stdio.h>
#include <stdlib.h>
struct Product {
    int productID;
    char name[50];
    float price;
};
int main() {
    int n;
    struct Product *ptr;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }
    ptr = (struct Product *)malloc(n * sizeof(struct Product));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("\n--- Enter Details for %d Products ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Product %d:\n", i + 1);
        printf("  Product ID: ");
        scanf("%d", &(ptr + i)->productID); 
        printf("  Name: ");
        scanf("%s", (ptr + i)->name);
        printf("  Price: ");
        scanf("%f", &(ptr + i)->price);
    }
    printf("\n--- Displaying Product Details ---\n");
    printf("ID\tName\t\tPrice\n");
    printf("----------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n",
               (ptr + i)->productID,
               (ptr + i)->name,
               (ptr + i)->price);
    }
    free(ptr);
    return 0;
}