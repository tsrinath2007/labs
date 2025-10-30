#include <stdio.h>
#include <string.h>
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
struct Address {
    char street[100];
    char city[50];
    char zipCode[20];
};
struct Student {
    char name[50];
    int rollNumber;
    struct Address addr; 
};

int main() {
    struct Student s1;
    printf("--- Enter Student Details ---\n");
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);
    clear_input_buffer(); 
    printf("Enter street: ");
    fgets(s1.addr.street, 100, stdin);
    s1.addr.street[strcspn(s1.addr.street, "\n")] = 0; 
    printf("Enter city: ");
    scanf("%s", s1.addr.city);
    printf("Enter zip code: ");
    scanf("%s", s1.addr.zipCode);
    printf("\n--- Displaying Student Details ---\n");
    printf("Name:         %s\n", s1.name);
    printf("Roll Number:  %d\n", s1.rollNumber);
    printf("Address:\n");
    printf("  Street:     %s\n", s1.addr.street);
    printf("  City:       %s\n", s1.addr.city);
    printf("  Zip Code:   %s\n", s1.addr.zipCode);
    return 0;
}