/*
 * cleanup.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "cleanup.h"
#include "cleanup_around.h"
#include "def.h"

void cleanup(void) {
#ifdef LOG_IN_OUT
	printf("--- cleanup >>>\n");
#endif

	for (int k = 0; k < 9 && !problem_found; k++) {
		for (int j = 0; j < 9 && !problem_found; j++) {
			if (grid[k][j][0] == 1) cleanup_around(k, j);
		}
	}

#ifdef LOG_IN_OUT
	printf("<<< cleanup ---\n");
#endif
}
