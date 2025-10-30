#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100];
    int n, ch;
    long fileSize, startPos;

    // 1. Get input from user
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter the value of n (last n characters): ");
    scanf("%d", &n);

    // 2. Open in binary read mode ('rb')
    // 'rb' is best for fseek and ftell
    fptr = fopen(filename, "rb"); 
    if (fptr == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    // 3. Go to the end of the file
    fseek(fptr, 0, SEEK_END);

    // 4. Get the size of the file
    fileSize = ftell(fptr);

    // 5. Check if n is larger than the file
    if (n > fileSize) {
        n = fileSize; // Just print the whole file
    }

    // 6. Calculate starting position (go back 'n' bytes)
    startPos = fileSize - n;
    
    // 7. Seek to that position from the beginning
    fseek(fptr, startPos, SEEK_SET); 
    // Or: fseek(fptr, (long)(-n), SEEK_END);

    // 8. Read and print from this position to the end
    printf("--- Last %d characters of '%s' ---\n", n, filename);
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    printf("\n");

    // 9. Close the file
    fclose(fptr);

    return 0;
}