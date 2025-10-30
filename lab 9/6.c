#include <stdio.h>

// 1. Define the structure for a Cricket Player
struct CricketPlayer {
    char playerName[50];
    char teamName[50];
    float battingAverage;
};

int main() {
    int n;
    struct CricketPlayer players[100]; // Array of structures
    struct CricketPlayer temp;         // Temp struct for swapping

    printf("Enter the number of players (up to 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number.\n");
        return 1;
    }

    // 2. Input data for multiple players
    printf("\n--- Enter Player Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("Player %d:\n", i + 1);
        printf("  Name: ");
        scanf("%s", players[i].playerName);
        printf("  Team: ");
        scanf("%s", players[i].teamName);
        printf("  Batting Average: ");
        scanf("%f", &players[i].battingAverage);
    }

    // 3. Sort them by batting average (Descending Order using Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // If the current player's avg is less than the next player's
            if (players[j].battingAverage < players[j + 1].battingAverage) {
                // Swap the entire structures
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // 4. Display the sorted list of players
    printf("\n--- Players Sorted by Batting Average (High to Low) ---\n");
    printf("Rank\tPlayer\t\tTeam\t\tAverage\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%-15s\t%.2f\n",
               i + 1,
               players[i].playerName,
               players[i].teamName,
               players[i].battingAverage);
    }

    return 0;
}