#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tnode.h"
#include "db.h"
#include "index.h"


struct db *buildRandomDb() {

    srand(time(NULL));

    struct db *database = NULL;

    int n = 6;
    char s[n];
    char *key;
    int m = 10000;
    int k = rand() % m;
    int col = 0;

    printf("Writing %d entries to an %d-column database  ...\n", m, NCOLS);
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
    return database;
}


int main() {

    struct db *database = buildRandomDb();

    char *key = "foo";
    int lookupCol = 32;
    add(database, key, 2301, lookupCol);

    char *filename = "db.bin";
    printf("Saving database to disk as %s ...\n", filename);
    save(database, filename);

    printf("Loading database from file %s ...\n", filename);
    database = load(filename);

    printf("Building indices for all columns ...\n");
    struct tnode **indices = buildall(database);

    printf("Looking up key '%s' in index for column '%d' ...\n", key, lookupCol);
    struct tnode *colindex = indices[lookupCol];
    struct db *rowptr;
    rowptr = lookup(colindex, key);
    printf("Retrieved pointer %p from index "
           "to db row containing '%s'.\n", rowptr, key);

}

