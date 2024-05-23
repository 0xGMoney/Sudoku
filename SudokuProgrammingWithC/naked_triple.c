/* naked_triple.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/naked_triple.h"
#include "headers/naked_triple_unit.h"

int naked_triple(void) {
#ifdef LOG_IN_OUT
    printf("--- naked_triple >>>\n");
#endif

    int result = FALSE;
    for (int k = 0; k < 9 && !result; k++) {
        if (   naked_triple_unit("row", row[k])
            || naked_triple_unit("column", col[k])
            || naked_triple_unit("box", box[k])) {
            result = TRUE;
        }
    }

#ifdef LOG_IN_OUT
    printf("<<< naked_triple ---\n");
#endif

    return result;
}
