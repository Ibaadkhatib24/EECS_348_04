#include <stdio.h>

void findCombinations(int score, int TD_2pt, int TD_FG, int TD, int FG, int safety) {
    if (score < 0) {
        return;
    }
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
               TD_2pt, TD_FG, TD, FG, safety);
        return;
    }

    // Try each scoring play and reduce the score accordingly
    findCombinations(score - 8, TD_2pt + 1, TD_FG, TD, FG, safety);    // TD + 2pt
    findCombinations(score - 7, TD_2pt, TD_FG + 1, TD, FG, safety);    // TD + FG
    findCombinations(score - 6, TD_2pt, TD_FG, TD + 1, FG, safety);    // TD
    findCombinations(score - 3, TD_2pt, TD_FG, TD, FG + 1, safety);    // FG
    findCombinations(score - 2, TD_2pt, TD_FG, TD, FG, safety + 1);    // Safety
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0);  // Start the recursion with all counts at 0
    }

    return 0;
}
