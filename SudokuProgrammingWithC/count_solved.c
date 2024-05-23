/* count_solved.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/count_solved.h"
#include "headers/def.h"

int count_solved(void) {
#ifdef LOG_IN_OUT
    printf("--- count_solved >>>\n");
#endif

    int result = 0;
    for (int k = 0; k < 9; k++) {
        for (int j = 0; j < 9; j++) {
            if (grid[k][j][0] == 1) result++;
        }
    }
#ifdef LOG_IN_OUT
    printf("<<< count_solved ---\n");
#endif

    return result;
}
