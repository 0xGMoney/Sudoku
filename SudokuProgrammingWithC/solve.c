/* solve.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/count_candidates.h"
#include "headers/def.h"
#include "headers/display.h"
#include "headers/display_string.h"
#include "headers/execute_strategies.h"
#include "headers/keep_going.h"
#include "headers/solve.h"

void solve(void) {
#ifdef LOG_IN_OUT
    printf("--- solve >>>\n");
#endif

    if (!backtracking) n_strats_used = 0;
    int n_candidates = count_candidates();
    int n_candidates_old = n_candidates + 1;

    while (keep_going() && n_candidates < n_candidates_old) {
        n_candidates_old = n_candidates;
        if (keep_going() && !execute_strategies(0)) {
            if (keep_going() && !execute_strategies(1)) {
                if (keep_going() && !execute_strategies(2)) {
                    execute_strategies(3);
                }
            }
        }
        n_candidates = count_candidates();
    }
#ifdef LOG_IN_OUT
    printf("<<< solve ---\n");
#endif
}
