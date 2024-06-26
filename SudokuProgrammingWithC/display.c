/* display.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/display.h"

void display(void) {
    char *h =  "  ++---+---+---++---+---+---++---+---+---++";

    char *hh = "  ++===+===+===++===+===+===++===+===+===++";

    int jBase [] = {2,6,10,15,19,23,28,32,36};
    printf("     0   1   2   3   4   5   6   7   8\n");
    for (int k = 0; k < 9; k++) {
        if (k % 3 == 0) {
            printf("%s\n", hh);
        } else {
            printf("%s\n", h);
        }

        char top[42] = "||   |   |   ||   |   |   ||   |   |   ||";
        char mid[42] = "||   |   |   ||   |   |   ||   |   |   ||";
        char bot[42] = "||   |   |   ||   |   |   ||   |   |   ||";

        char *displ[42] = {top, mid, bot};

        for (int j = 0; j < 9; j++) {
            if (grid[k][j][0] == 1) {
                int i = 0;
                do { i++; } while (grid[k][j][i] == 0);
                mid[jBase[j]] = '(';
                mid[jBase[j]+1] = '0' + i;
                mid[jBase[j]+2] = ')';
            } else {
                for (int i = 0; i < 9; i++) {
                    if (grid[k][j][i+1] != 0) {
                        displ[i/3][jBase[j] + i%3] = '0' + (i+1);
                    }
                }   // for (int i..
            }   // else..
        }   // for (int j..
        printf("  %s\n", displ[0]);
        printf("%d %s\n", k, displ[1]);
        printf("  %s\n", displ[2]);
    }
    printf("%s\n", hh);
}
