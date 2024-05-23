/* sudoku_solver.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/backtrack.h"
#include "headers/box_line.h"
#include "headers/cleanup.h"
#include "headers/count_candidates.h"
#include "headers/count_solved.h"
#include "headers/def.h"
#include "headers/display.h"
#include "headers/display_strat_in_clear.h"
#include "headers/display_string.h"
#include "headers/hidden_pair.h"
#include "headers/hidden_triple.h"
#include "headers/incosistent_grid.h"
#include "headers/init.h"
#include "headers/lines_2.h"
#include "headers/lines_3.h"
#include "headers/lines_4.h"
#include "headers/naked_pair.h"
#include "headers/naked_triple.h"
#include "headers/pointing_line.h"
#include "headers/rectangle.h"
#include "headers/solve.h"
#include "headers/unique_loop.h"
#include "headers/xy_chain.h"
#include "headers/y_wing.h"

//#define USE_FILES
#define N_LEVELS 4

// Sudoku grid and Sudoku indexing arrays
char grid[9][9][10];
char  row[9][9][2];
char  col[9][9][2];
char  box[9][9][2];

// Unit names used for display in clear
char *unit_names[3] = {"row", "column", "box"};

// Easy strategies (level 1)
f_ptr_t strat1[] = {
    naked_pair,
    hidden_pair,
    box_line,
    pointing_line
};
char *strat1_names[] = {
    "naked-pair",
    "hidden-pair",
    "box-line",
    "pointing-line"
};
int n_strat1 = sizeof(strat1) / sizeof(f_ptr_t);

// Intermediate strategies (level 2)
f_ptr_t strat2[] = {
    naked_triple,
    hidden_triple,
    lines_2,
    naked_quad,
    y_wing
};
char *strat2_names[] = {
    "naked-triple",
    "hidden-triple",
    "lines-2",
    "naked-quad",
    "Y-wing",
// Warning: appended "XY-chain"
    "XY-chain"
};
int n_strat2 = sizeof(strat2) / sizeof(f_ptr_t);

// Complex strategies (level 3)
// WARNING: Keep XY-chain in the first position
//          because strategy() depends on it to 
//          set strats_used
f_ptr_t strat3[] = {
    xy_chain,
    rectangle,
    lines_3,
    lines_4
};
char *strat3_names[] = {
    "XY_chain",
    "rectangle",
    "lines-3",
    "lines-4"
};
int n_strat3 = sizeof(strat3) / sizeof(f_ptr_t);

// List of used strategies (never see more than 19)
int strats_used[50];
int n_strats_used;

// Global flags, to 'pop out' from nested calls
int problem_found = FALSE;
int silent = FALSE;

int main(int argc, char *argv[]) {
#ifdef USE_FILES
    return 0;
#else
    // Check for the presence of an input Sudoku string
    if (argc < 2) {
        puts("*** You need to provide a sudoku string ***");
        return EXIT_FAILURE;
    }

    // Check that the Sudoku string is 81-chars long
    if (strlen(argv[1] != 81)) {
        puts("*** The Sudoku string must be 81 characters long ***");
        return EXIT_FAILURE;
    }

    // Check that the Sudoku string consists of digits between 0 and 9
    for (int k = 0; k < 81; k++) {
        if (argv[1][k] < '0' || argv[1][k] > '9') {
            puts("*** The Sudoku string must only contain 0 to 9 digits ***");
            return EXIT_FAILURE;
        }
    }

    // Print the Sudoku string
    if (argc > 2) {
        printf("--- \"%s\"\n", argv[2]);
    }
    printf("--- \"%s\"\n", argv[1]);

    // Initialize the Sudoku arrays
    init(argv[1]);
    display();

    // Remove the impossible numbers with an initial cleanup without
    // displaying any logging messages
    printf("Sudoku: the initial grid contains %d solved cells\n",
            count_solved()
          );
    silent = TRUE;
    cleanup();
    silent = FALSE;
    printf("Sudoku: after initial cleanup, the grid"
            " contains %d solved cells\n", count_solved()
          );
    display();

    // Execute the strategies
    solve();

    // Backtrack if necessary
    if (count_solved() < 81) {
        backtracking = TRUE;
        backtrack(0);
        backtracking = FALSE;
    }

    // Check that everything is OK
    if (inconsistent_grid()) {
        printf("*** The grid is inconsistent ***\n");
    }

    printf("Sudoku: the final grid contains %d solved cells\n",
            count_solved()
          );
    display();
    display_string();
    printf("Strategies used %d: ", n_strats_used);
    /*
     * for (int k = 0; k < n_strats_used; k++) {
     *   printf(" %d\n", strats_used[k]);
     * };
     * printf("\n");
     */
    display_strats_in_clear();
#endif

    return EXIT_SUCCESS;
}
