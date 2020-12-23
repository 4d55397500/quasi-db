#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tnode.h"
#include "db.h"
#include "index.h"



int main() {

    srand(time(NULL));

    struct db *database = NULL;

    int n = 6;
    char s[n];
    char *key;
    int m = 10;
    int k = rand() % m;
    int col = 0;

    printf("Writing to an %d-column database %d entries ...\n", NCOLS, m);
    for (int row = 0; row < m; row++) {
        for (int j = 0; j < n; j++) {
            s[j] = '0' + rand() % 72;
        }
        if (row == k) {
            key = s;
        }
        col = rand() % NCOLS;
        if (row == 0) {
            database = add(database, s, row, col);
        } else {
            add(database, s, row, col);
        }
    }

    int nrows = dblen(database);
    printf("Successfully wrote %d entries.\n", nrows);
    printf("Printing database ...\n");
    printdb(database);

    int lookupCol = rand() % NCOLS;
    printf("Building index for column %d ...\n", lookupCol);
    struct tnode *colindex = NULL;
    colindex = buildindex(database, lookupCol);

    struct db *rowptr;
    printf("Looking up key '%s' in index ...\n", key);
    rowptr = lookup(colindex, key);
    printf("Retrieved pointer %p from index "
           "to db row containing '%s'.\n", rowptr, key);

}