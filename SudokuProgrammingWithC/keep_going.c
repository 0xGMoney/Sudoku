/* keep_going.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/count_solved.h"
#include "headers/def.h"

int keep_going(void) {
    return (count_solved() < 81 && !problem_found);
}
