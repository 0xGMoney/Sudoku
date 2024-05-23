/* inconsistent_grid.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/inconsistent_grid.h"
#include "headers/inconsistent_unit.h"

int consistent_grid(void) {
    int result = FALSE;
    for (int k = 0; k < 9 && !result; k++) {
        result |= inconsistent_unit("row", k, row[k]);
        if (!result) {
            result |= inconsistent_unit("column", k, col[k]);
            if (!result) {
                result |= inconsistent_unit("box", k, box[k]);
            }
        }
    } // for (int k...
    return result;
}
