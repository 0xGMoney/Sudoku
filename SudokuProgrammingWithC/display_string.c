/* display_string.c */

#include <stdio.h>
#include <stdlib.h>
#include "headers/def.h"
#include "headers/display_string.h"

void display_string(void) {
    printf("****** ");
    for (int k = 0; k < 9; k++) {
        for (int j = 0; j < 9; j++) {
            char *elem = grid[k][j];
            if (elem[0] > 1) {
                printf("0");
            } else {
                int i = 0;
                do { i++; } while (!elem[i]);
                printf("%d", i);
            }
        }
    }
    printf("\n");
}
