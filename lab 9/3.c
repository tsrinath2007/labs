#include <stdio.h>
struct Student {
    char name[100];
    int rollNumber;
    int marks[3];
    int total;
    float average;
};
#define NUM_STUDENTS 5
int main() {
    struct Student students[NUM_STUDENTS];
    printf("--- Enter Data for %d Students ---\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("  Name: ");
        scanf("%s", students[i].name);
        printf("  Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("  Enter 3 marks (e.g., 80 90 75): ");
        scanf("%d %d %d", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
    }
    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].total = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        students[i].average = (float)students[i].total / 3.0;
    }
    printf("\n\n--- Student Results ---\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("------------------------------\n");
        printf("Details for Student %d (Roll No: %d)\n", i + 1, students[i].rollNumber);
        printf("  Name:    %s\n", students[i].name);
        printf("  Marks:   %d, %d, %d\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("  Total:   %d\n", students[i].total);
        printf("  Average: %.2f\n", students[i].average);
    }
    printf("------------------------------\n");
    return 0;
}