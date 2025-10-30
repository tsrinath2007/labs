#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *sourceFile, *destFile;
    int ch;
    sourceFile = fopen("source3.txt", "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file 'source3.txt'.\n");
        exit(1);
    }
    destFile = fopen("dest3.txt", "w");
    if (destFile == NULL) {
        printf("Error: Could not create destination file 'dest3.txt'.\n");
        fclose(sourceFile);
        exit(1);
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("File copied successfully from 'source3.txt' to 'dest3.txt'.\n");
    fclose(sourceFile);
    fclose(destFile);
    return 0;
}