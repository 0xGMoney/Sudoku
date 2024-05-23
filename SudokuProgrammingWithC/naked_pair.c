/* naked_pair.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/naked_pair.h"
#include "headers/naked_pair_unit.h"

int naked_pair(void) {
#ifdef LOG_IN_OUT
    printf("--- naked_pair >>>\n");
#endif

    int result = FALSE;
    for (int k = 0; k < 9 && !result; k++) {
        if (   naked_pair_unit("row", row[k])
            || naked_pair_unit("column", col[k])
            || naked_pair_unit("box", box[k])) {
            result = TRUE;
        }
    }
#ifdef LOG_IN_OUT
    printf("<<< naked_pair ---\n");
#endif

    return result;
}
