#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    int ch; // Use 'int' to hold EOF

    // 1. Open the source file for reading
    sourceFile = fopen("source3.txt", "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file 'source3.txt'.\n");
        exit(1);
    }

    // 2. Open the destination file for writing
    // 'w' mode overwrites the file if it exists, or creates it.
    destFile = fopen("dest3.txt", "w");
    if (destFile == NULL) {
        printf("Error: Could not create destination file 'dest3.txt'.\n");
        fclose(sourceFile); // Close the first file
        exit(1);
    }

    // 3. Copy character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from 'source3.txt' to 'dest3.txt'.\n");

    // 4. Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}