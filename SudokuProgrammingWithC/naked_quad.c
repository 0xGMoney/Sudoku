/* naked_quad.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/naked_quad.h"
#include "headers/naked_quad_unit.h"

int naked_quad(void) {
#ifdef LOG_IN_OUT
    printf("--- naked_quad >>>\n");
#endif

    int result = FALSE;
    for (int k = 0; k < 9 && !result; k++) {
        if (   naked_quad_unit("row", row[k])
            || naked_quad_unit("column", col[k])
            || naked_quad_unit("box", box[k])) {
            result = TRUE;
        }
    }

#ifdef LOG_INT_OUT
    printf("<<< naked_quad ---\n");
#endif

    return result;
}
