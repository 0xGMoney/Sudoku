/* unique.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/unique.h"
#include "headers/unique_unit.h"

int unique(void) {
#ifdef LOG_IN_OUT
    printf("--- unique >>>\n");
#endif

    int result = FALSE;
    for (int k = 0; k < 9; k++) {
        result |= unique_unit("row", row[k]);
        result |= unique_unit("column", col[k]);
        result |= unique_unit("box", box[k]);
    }

#ifdef LOG_IN_OUT
    printf("<<< unique ---\n");
#endif

    return result;
}
