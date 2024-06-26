/* execute_strategies.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/count_candidates.h"
#include "headers/count_solved.h"
#include "headers/def.h"
#include "headers/display.h"
#include "headers/display_string.h"
#include "headers/execute_strategies.h"
#include "headers/keep_going.h"
#include "headers/unique_loop.h"

/*
 * It returns TRUE when at least one candidate is removed.
 *
 * It goes through all the strategies of the level, but only as long as
 * no candidate is removed. When that happens, it aborts the loop and
 * returns.
 */

int execute_strategies(int level) {
#ifdef LOG_IN_OUT
    printf("--- execute_strategies >>>\n");
#endif

    f_ptr_t *strats = strat_all[level];
    char **strat_names = strat_all_names[level];
    int n_strat = n_strat_all[level];
    int n_candidates = count_candidates();
    int n_candidates_initial = n_candidates;

    for (   int k = 0;
            k < n_strat && keep_going() && n_candidates == n_candidates_initial;
            k++) {
        (void)strats[k]();
        n_candidates = count_candidates();
        if (n_candidates < n_candidates_initial) {
            if (!backtracking) {
                strats_used[n_strats_used] = level * 10 + k;
                n_strats_used++;
            }
            if (!silent) {
                printf("strategy: after '%s' the grid contains "
                        "%d solved cells\n\n", strat_names[k], count_solved());
            }
            if (!silent) { display(); display_string(); }
        }
    }
#ifdef LOG_IN_OUT
    printf("<<< execute_strategies ---\n");
#endif
    return (n_candidates < n_candidates_initial);
}
