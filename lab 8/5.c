#include <stdio.h>
#define NUM_SUBJECTS 3
#define MAX_STUDENTS 100
void Calculate_Average(int marks[NUM_SUBJECTS][MAX_STUDENTS], int num_students, int average_array[]);
int main() {
    int N;
    int STUDENTS_MARKS[NUM_SUBJECTS][MAX_STUDENTS];
    int AVERAGE[MAX_STUDENTS];
    printf("Enter the number of students (N): ");
    scanf("%d", &N);
    if (N <= 0 || N > MAX_STUDENTS) {
        printf("Invalid number of students. Must be between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }
    for (int j = 0; j < N; j++) {
        printf("\n--- Entering data for Student %d ---\n", j + 1);
        printf("Enter %d marks: ", NUM_SUBJECTS);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            scanf("%d", &STUDENTS_MARKS[i][j]);
        }
    }
    Calculate_Average(STUDENTS_MARKS, N, AVERAGE);
    printf("\n--- Calculated Student Averages ---\n"); 
    for (int j = 0; j < N; j++) {
        printf("Average for Student %d: %d\n", j + 1, AVERAGE[j]);
    }
    return 0;
}
void Calculate_Average(int marks[NUM_SUBJECTS][MAX_STUDENTS], int num_students, int average_array[]) {
    for (int j = 0; j < num_students; j++) {
        int sum = 0;
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            sum += marks[i][j];
        }
        average_array[j] = sum / NUM_SUBJECTS;
    }
}