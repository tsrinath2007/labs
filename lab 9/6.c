#include <stdio.h>
struct CricketPlayer {
    char playerName[50];
    char teamName[50];
    float battingAverage;
};
int main() {
    int n;
    struct CricketPlayer players[100];
    struct CricketPlayer temp;
    printf("Enter the number of players (up to 100): ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid number.\n");
        return 1;
    }
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
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (players[j].battingAverage < players[j + 1].battingAverage) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
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