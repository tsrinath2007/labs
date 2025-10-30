#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *fptr;
    char sentence[1000];

    // 1. Open the file in read mode
    fptr = fopen("input1.txt", "r");

    // 2. Check if the file was opened successfully
    if (fptr == NULL) {
        printf("Error: Could not open file 'input1.txt'.\n");
        exit(1);
    }

    // 3. Read a line (up to 999 chars or a newline)
    if (fgets(sentence, sizeof(sentence), fptr) != NULL) {
        // 4. Display the sentence on the console
        printf("The sentence from the file is:\n%s", sentence);
    } else {
        printf("File is empty or could not be read.\n");
    }

    // 5. Close the file
    fclose(fptr);

    return 0;
}