#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    FILE *fptr;
    int ch;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    int inWord = 0;
    fptr = fopen("input5.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file 'input5.txt'.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF) {
        charCount++;
        if (ch == '\n') {
            lineCount++;
        }
        if (isspace(ch)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            wordCount++;
        }
    }
    if (charCount > 0) {
        lineCount++;
    }
    printf("--- File Statistics ('input5.txt') ---\n");
    printf("Characters: %d\n", charCount);
    printf("Words:      %d\n", wordCount);
    printf("Lines:      %d\n", lineCount);
    fclose(fptr);
    return 0;
}