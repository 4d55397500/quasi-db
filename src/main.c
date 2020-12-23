#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tnode.h"
#include "db.h"
#include "index.h"


int main() {

    srand(time(NULL));

    struct db *database = NULL;

    int n = 6;
    char *s = (char *) malloc(n);
    char *key = (char *) malloc(strlen(s));
    int m = 10000;
    int k = rand() % m;
    int col = 0;
    int lookupCol = 0;
    printf("Writing to an %d-column database %d entries ...\n", NCOLS, m);
    for (int row = 0; row < m; row++) {
        for (int j = 0; j < n; j++) {
            s[j] = 'a' + rand() % 20;
        }
        col = rand() % NCOLS;
        if (row == k) {
            strcpy(key, s);
            lookupCol = col;
        }
        if (row == 0) {
            database = add(database, s, row, col);
        } else {
            add(database, s, row, col);
        }
    }

    int nrows = dblen(database);
    printf("Successfully wrote %d entries.\n", nrows);

    char *filename = "db.bin";
    printf("Saving database to disk as %s ...\n", filename);
    save(database, filename);

    printf("Loading database from file %s ...\n", filename);
    database = load(filename);
//    printdb(database);

    printf("Building indices for all columns ...\n");
    struct tnode **indices = buildall(database);

    struct tnode *colindex = indices[lookupCol];
    struct db *rowptr;
    printf("Looking up key '%s' in index for column '%d' ...\n", key, lookupCol);
    rowptr = lookup(colindex, key);
    printf("Retrieved pointer %p from index "
           "to db row containing '%s'.\n", rowptr, key);


}

