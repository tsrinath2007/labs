#include <stdio.h>

// --- Constants ---
// Define the number of marks per student (from the image)
#define NUM_SUBJECTS 3
// Define a maximum number of students
#define MAX_STUDENTS 100

// --- Function Prototype ---

/**
 * @brief (Problem 5) Calculates the integer average mark for each student.
 * @param marks A 2D array (STUDENTS_MARKS) of size [NUM_SUBJECTS][MAX_STUDENTS].
 * @param num_students The actual number of students (N).
 * @param average_array A 1D array (AVERAGE) to store the computed averages.
 */
void Calculate_Average(int marks[NUM_SUBJECTS][MAX_STUDENTS], int num_students, int average_array[]);

// --- Main Function ---

int main() {
    int N; // Number of students

    // --- Array Declarations ---
    // 2D array for marks, indexed as [subject_index][student_index]
    int STUDENTS_MARKS[NUM_SUBJECTS][MAX_STUDENTS];
    // 1D array to store the calculated average for each student
    int AVERAGE[MAX_STUDENTS];

    // --- Input Section ---
    printf("Enter the number of students (N): ");
    scanf("%d", &N);

    // Validate input
    if (N <= 0 || N > MAX_STUDENTS) {
        printf("Invalid number of students. Must be between 1 and %d.\n", MAX_STUDENTS);
        return 1; // Exit with an error
    }

    // Loop to get data for each student
    for (int j = 0; j < N; j++) { // 'j' is the student index
        printf("\n--- Entering data for Student %d ---\n", j + 1);
        
        printf("Enter %d marks: ", NUM_SUBJECTS);
        for (int i = 0; i < NUM_SUBJECTS; i++) { // 'i' is the subject index
            scanf("%d", &STUDENTS_MARKS[i][j]);
        }
    }

    // --- Function Call ---
    // This call populates the 'AVERAGE' array
    Calculate_Average(STUDENTS_MARKS, N, AVERAGE);

    // --- Output Section ---
    printf("\n--- Calculated Student Averages ---\n");
    for (int j = 0; j < N; j++) {
        printf("Average for Student %d: %d\n", j + 1, AVERAGE[j]);
    }

    return 0; // Indicates successful execution
}

// --- Function Definition ---

/**
 * (Problem 5)
 * This function loops through each student (columns) and sums their
 * marks (rows), then calculates and stores the integer average.
 */
void Calculate_Average(int marks[NUM_SUBJECTS][MAX_STUDENTS], int num_students, int average_array[]) {
    
    // Loop through each student (j = student index)
    for (int j = 0; j < num_students; j++) {
        int sum = 0;
        
        // Loop through all marks for the current student (i = subject index)
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            sum += marks[i][j];
        }
        
        // Calculate and store the integer average, as implied by the sample
        average_array[j] = sum / NUM_SUBJECTS;
    }
}