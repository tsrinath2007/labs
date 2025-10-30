#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isspace()

int main() {
    FILE *fptr;
    int ch;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    
    int inWord = 0; // State: 0 = in whitespace, 1 = in a word

    fptr = fopen("input5.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file 'input5.txt'.\n");
        exit(1);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        // 1. Character count
        charCount++;

        // 2. Line count
        if (ch == '\n') {
            lineCount++;
        }

        // 3. Word count logic
        if (isspace(ch)) { // 'isspace' checks for ' ', '\n', '\t', etc.
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1; // We've just entered a new word
            wordCount++;
        }
    }
    
    // Note: This logic counts 'lines' by counting newlines.
    // A file without a final newline (e.g., "hello") will show 0 lines.
    // To count the last line if it's not empty and lacks a newline:
    if (charCount > 0) {
        lineCount++; // Count the first line, or the last line if no \n
    }


    printf("--- File Statistics ('input5.txt') ---\n");
    printf("Characters: %d\n", charCount);
    printf("Words:      %d\n", wordCount);
    printf("Lines:      %d\n", lineCount);

    fclose(fptr);
    return 0;
}