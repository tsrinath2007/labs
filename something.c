#include <stdio.h>
#include <string.h>
int main() {
    char* person1 = "Krishna";
    char* person2 = "Nithya";
    char* person3 = "Srinath";
    char* person4 = "justin";
    int len1= strlen(person1);
    int len2 = strlen(person2);
    int len3 = strlen(person3);
    int len4 = strlen(person4);
    int matrix[2][2] = {
        {len1, len2},
        {len3, len4}
    };
    printf("Names: %s, %s, %s, %s\n", person1, person2, person3, person4);
    printf("Lengths: %d, %d, %d, %d\n\n", len1, len2, len3, len4);
    printf("Resulting 2x2 Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    printf("\nDeterminant (ad - bc): %d\n", det);
    printf("Thank you and dengay!!!!");
    return 0;