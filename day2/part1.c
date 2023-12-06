#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// * PART ONE
/*

    A - Rock
    B - Paper
    C - Scissors

    X - Rock
    Y - Paper
    Z - Scissors

    SCORE:

        1 - Rock
        2 - Paper
        3 - Scissors

        0 - Lose
        3 - Draw
        6 - Win
*/

typedef struct Scores{
    int rock;
    int paper;
    int scissors;
    int lose;
    int draw;
    int win;
}Scores;


int main(void) {

    FILE* input_file;
    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("error opening the file");
        exit(0);
    }

    char line[4];
    char player, opponent;
    int score = 0;
    Scores s;
    s.rock = 1;
    s.paper = 2;
    s.scissors = 3;
    s.lose = 0;
    s.draw = 3;
    s.win = 6;

    while(fgets(line, sizeof line, input_file)) {

        opponent = line[0];
        player = line[2];

        if (line[0] == '\n') {
            continue;
        }

        if (opponent == 'A') { // ! A = Rock
            switch (player) {
                case 'X':
                    score += s.draw;
                    score += s.rock;
                    break;
                case 'Y':
                    score += s.win;
                    score += s.paper;
                    break;
                case 'Z':
                    score += s.lose;
                    score += s.scissors;
                    break;
            }
        } else if (opponent == 'B') { // ! B = Paper
            switch (player) {
                case 'X':
                    score += s.lose;
                    score += s.rock;
                    break;
                case 'Y':
                    score += s.draw;
                    score += s.paper;
                    break;
                case 'Z':
                    score += s.win;
                    score += s.scissors;
                    break;
            }
        } else {
            switch (player) { // ! C = Scissors
                case 'X':
                    score += s.win;
                    score += s.rock;
                    break;
                case 'Y':
                    score += s.lose;
                    score += s.paper;
                    break;
                case 'Z':
                    score += s.draw;
                    score += s.scissors;
                    break;
            }
        }
    }

    printf("player's score: %d\n", score);
    fclose(input_file);

    return 0;
}
