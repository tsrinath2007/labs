#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char line[500];

    // 1. Open the file in append mode
    // 'a' will create the file if it does not exist.
    fptr = fopen("output2.txt", "a");

    // 2. Check for error
    if (fptr == NULL) {
        printf("Error: Could not open or create file 'output2.txt'.\n");
        exit(1);
    }

    // 3. Get input from the user
    printf("Enter a line of text to write: ");
    fgets(line, sizeof(line), stdin);

    // 4. Write the line to the file
    fputs(line, fptr);
    
    // You could also add an extra newline to separate entries
    // fputs("\n", fptr); 

    printf("Successfully wrote to file 'output2.txt'.\n");

    // 5. Close the file
    fclose(fptr);

    return 0;
}