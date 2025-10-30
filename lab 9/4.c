#include <stdio.h>
#include <string.h>

// Helper function to clear the input buffer (e.g., leftover '\n')
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Define the nested structure for Address
struct Address {
    char street[100];
    char city[50];
    char zipCode[20];
};

// 2. Define the main structure for Student
struct Student {
    char name[50];
    int rollNumber;
    // Nest the Address structure inside Student
    struct Address addr; 
};

int main() {
    // 3. Create a single student variable
    struct Student s1;

    // --- Input Student Details ---
    printf("--- Enter Student Details ---\n");
    printf("Enter name: ");
    scanf("%s", s1.name);

    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);

    // Clear the input buffer before reading the street
    clear_input_buffer(); 
    
    printf("Enter street: ");
    fgets(s1.addr.street, 100, stdin);
    // Remove the newline character captured by fgets
    s1.addr.street[strcspn(s1.addr.street, "\n")] = 0; 

    printf("Enter city: ");
    scanf("%s", s1.addr.city);

    printf("Enter zip code: ");
    scanf("%s", s1.addr.zipCode);

    // --- Display Student Details ---
    printf("\n--- Displaying Student Details ---\n");
    printf("Name:         %s\n", s1.name);
    printf("Roll Number:  %d\n", s1.rollNumber);
    printf("Address:\n");
    printf("  Street:     %s\n", s1.addr.street);
    printf("  City:       %s\n", s1.addr.city);
    printf("  Zip Code:   %s\n", s1.addr.zipCode);

    return 0;
}