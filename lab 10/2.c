#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    char line[500];
    fptr = fopen("output2.txt", "a");
    if (fptr == NULL) {
        printf("Error: Could not open or create file 'output2.txt'.\n");
        exit(1);
    }
    printf("Enter a line of text to write: ");
    fgets(line, sizeof(line), stdin);
    fputs(line, fptr);
    printf("Successfully wrote to file 'output2.txt'.\n");
    fclose(fptr);
    return 0;
}