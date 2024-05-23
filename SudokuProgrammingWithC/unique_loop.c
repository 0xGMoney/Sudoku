/* unique_loop.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/unique.h"
#include "headers/unique_loop.h"

int unique_loop(void) {
#ifdef LOG_IN_OUT
    printf("--- unique_loop >>>\n");
#endif

    int found;
    int something = FALSE;
    do {
        found = unique();
        something |= found;
    } while (found && !problem_found);

#ifdef LOG_IN_OUT
    printf("<<< unique_loop ---\n");
#endif

    return something;
}
