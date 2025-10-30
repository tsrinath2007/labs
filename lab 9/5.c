#include <stdio.h>
#include <stdlib.h> // For malloc and free (a more dynamic approach)

// 1. Define the structure for a Product
struct Product {
    int productID;
    char name[50];
    float price;
};

int main() {
    int n;
    struct Product *ptr; // Pointer to struct Product

    printf("Enter the number of products: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // 2. Create an array of products using pointers
    // We dynamically allocate memory for 'n' products
    ptr = (struct Product *)malloc(n * sizeof(struct Product));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Input product details using the pointer
    printf("\n--- Enter Details for %d Products ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Product %d:\n", i + 1);
        
        printf("  Product ID: ");
        // Use (ptr + i) to get the address of the i-th struct
        // Use -> to access members from that address
        scanf("%d", &(ptr + i)->productID); 

        printf("  Name: ");
        scanf("%s", (ptr + i)->name);

        printf("  Price: ");
        scanf("%f", &(ptr + i)->price);
    }

    // 4. Display product details using the pointer
    printf("\n--- Displaying Product Details ---\n");
    printf("ID\tName\t\tPrice\n");
    printf("----------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n",
               (ptr + i)->productID,
               (ptr + i)->name,
               (ptr + i)->price);
    }

    // Don't forget to free the dynamically allocated memory
    free(ptr);

    return 0;
}