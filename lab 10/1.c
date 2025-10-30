#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    char sentence[1000];
    fptr = fopen("input1.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file 'input1.txt'.\n");
        exit(1);
    }
    if (fgets(sentence, sizeof(sentence), fptr) != NULL) {
        printf("The sentence from the file is:\n%s", sentence);
    } else {
        printf("File is empty or could not be read.\n");
    }
    fclose(fptr);
    return 0;
}