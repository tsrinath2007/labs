#include <stdio.h>

// --- Constants ---
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// --- Function Prototype ---

/**
 * @brief (Problem 6) Finds and prints the name of the top-scoring student.
 * @param average_array The 1D array (AVERAGE) of student averages.
 * @param num_students The actual number of students (N).
 * @param names A 2D char array (STUDENTS_NAMES) storing student names.
 */
void Find_Topper(int average_array[], int num_students, char names[][MAX_NAME_LENGTH]);

// --- Main Function ---

int main() {
    // --- Hard-coded sample data ---
    // We assume the data from Lab 6 and Lab 7 has already been populated.
    
    // Total number of students
    int N = 4;

    // The AVERAGE array (from Problem 5)
    // Averages: {35, 82, 62, 90}
    int AVERAGE[MAX_STUDENTS] = {35, 82, 62, 90};

    // The STUDENTS_NAMES array (from Lab 7)
    // Names: {"Ravi", "Sita", "Gita", "Abhay"}
    char STUDENTS_NAMES[MAX_STUDENTS][MAX_NAME_LENGTH] = {
        "Ravi",
        "Sita",
        "Gita",
        "Abhay"  // "Abhay" has the highest average (90)
    };

    // --- Function Call ---
    printf("Finding topper from the pre-defined list...\n");
    printf("Sample Averages: {35, 82, 62, 90}\n");
    printf("Sample Names: {Ravi, Sita, Gita, Abhay}\n\n");
    
    // This is the specific output format requested
    printf("The topper is : ");
    Find_Topper(AVERAGE, N, STUDENTS_NAMES);
    printf("\n");

    return 0; // Indicates successful execution
}

// --- Function Definition ---

/**
 * (Problem 6)
 * This function finds the maximum value in the AVERAGE array
 * and prints the name corresponding to that index.
 */
void Find_Topper(int average_array[], int num_students, char names[][MAX_NAME_LENGTH]) {
    
    // Handle case with no students
    if (num_students <= 0) {
        printf("[No students to compare]");
        return;
    }

    // Assume the first student is the topper initially
    int max_average = average_array[0];
    int topper_index = 0;

    // Loop through the rest of the students (starting from index 1)
    for (int i = 1; i < num_students; i++) {
        // If we find a higher average
        if (average_array[i] > max_average) {
            max_average = average_array[i]; // Update the max average
            topper_index = i;             // Update the index of the topper
        }
    }
    
    // Print the name of the student at the final topper_index
    printf("%s", names[topper_index]);
}