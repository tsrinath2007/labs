#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    FILE *sourceFile, *destFile;
    int ch;
    sourceFile = fopen("source4.txt", "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file 'source4.txt'.\n");
        exit(1);
    }
    destFile = fopen("dest4_upper.txt", "w");
    if (destFile == NULL) {
        printf("Error: Could not create destination file 'dest4_upper.txt'.\n");
        fclose(sourceFile);
        exit(1);
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        ch = toupper(ch);
        fputc(ch, destFile);
    }
    printf("File converted to uppercase and copied successfully.\n");
    fclose(sourceFile);
    fclose(destFile);
    return 0;
}