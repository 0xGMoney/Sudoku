/* remove_candidate.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/remove_candidate.h"

void remove_candidate(*caller, int i, int k, int j) {
    grid[k][j][i] = FALSE;
    grid[k][k][0]--;
#ifdef LOG_REMOVE_CANDIDATE
    if (!silent) {
        printf("%s: removed %d from (%d,%d)\n", caller, i, k, j);
    }
#endif

    if (grid[k][j][0] < 1) {
        if (!silent) {
            printf("*** No candidates left in (%d,%d)\n", k, j);
        }
        problem_found = TRUE;
    }
}
