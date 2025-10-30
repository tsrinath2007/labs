#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    char filename[100];
    int n, ch;
    long fileSize, startPos;
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter the value of n (last n characters): ");
    scanf("%d", &n);
    fptr = fopen(filename, "rb"); 
    if (fptr == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
    fseek(fptr, 0, SEEK_END);
    fileSize = ftell(fptr);
    if (n > fileSize) {
        n = fileSize;
    }
    startPos = fileSize - n;
    fseek(fptr, startPos, SEEK_SET);
    printf("--- Last %d characters of '%s' ---\n", n, filename);
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}