#include <stdio.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
void Find_Topper(int average_array[], int num_students, char names[][MAX_NAME_LENGTH]);
int main() {
    int N = 4;
    int AVERAGE[MAX_STUDENTS] = {35, 82, 62, 90};
    char STUDENTS_NAMES[MAX_STUDENTS][MAX_NAME_LENGTH] = {
        "Arya",
        "Anvith",
        "shashank",
        "srinath"
    };
    printf("Finding topper from the pre-defined list...\n");
    printf("Sample Averages: {35, 82, 62, 90}\n");
    printf("Sample Names: {Arya, Anvith, shashank, srinath}\n\n");
    printf("The topper is : ");
    Find_Topper(AVERAGE, N, STUDENTS_NAMES);
    printf("\n");
    return 0;
}
void Find_Topper(int average_array[], int num_students, char names[][MAX_NAME_LENGTH]) {
    if (num_students <= 0) {
        printf("[No students to compare]");
        return;
    }
    int max_average = average_array[0];
    int topper_index = 0;
    for (int i = 1; i < num_students; i++) {
        if (average_array[i] > max_average) {
            max_average = average_array[i]; 
            topper_index = i;     
        }
    }
    printf("%s", names[topper_index]);
}