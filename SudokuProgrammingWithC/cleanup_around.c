/* cleanup_around.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/cleanup_around.h"
#include "headers/cleanup_unit.h"
#include "headers/def.h"

void cleanup_around(int k, int j) {
#ifdef LOG_IN_OUT
    printf("--- cleanup_around(%d,%d) >>>\n", k, j);
#endif

    cleanup_unit("row", k, j, row[k]);
    if (!problem_found) cleanup_unit("column", k, j, col[j]);
    if (!problem_found) cleanup_unit("box", k, j, box[k/3*3+j/3]);

#ifdef LOG_IN_OUT
    printf("<<< cleanup_around(%d,%d) ---\n", k, j);
#endif
}
