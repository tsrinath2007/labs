#include <stdio.h>

// Define the structure for student details
struct Student {
    char name[100];
    int rollNumber;
    int marks[3]; // Array for 3 subject marks
    int total;
    float average;
};

// Define the number of students
#define NUM_STUDENTS 5

int main() {
    // Create an array of 5 Student structures
    struct Student students[NUM_STUDENTS];

    // --- 1. Input Data ---
    printf("--- Enter Data for %d Students ---\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        
        printf("  Name: ");
        scanf("%s", students[i].name); // Note: stops at first space
        
        printf("  Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        
        printf("  Enter 3 marks (e.g., 80 90 75): ");
        scanf("%d %d %d", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
    }

    // --- 2. Calculate Total and Average ---
    for (int i = 0; i < NUM_STUDENTS; i++) {
        // Calculate total
        students[i].total = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        
        // Calculate average (use 3.0 for floating-point division)
        students[i].average = (float)students[i].total / 3.0;
    }

    // --- 3. Display Results ---
    printf("\n\n--- Student Results ---\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("------------------------------\n");
        printf("Details for Student %d (Roll No: %d)\n", i + 1, students[i].rollNumber);
        printf("  Name:    %s\n", students[i].name);
        printf("  Marks:   %d, %d, %d\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("  Total:   %d\n", students[i].total);
        printf("  Average: %.2f\n", students[i].average); // Format to 2 decimal places
    }
    printf("------------------------------\n");

    return 0;
}