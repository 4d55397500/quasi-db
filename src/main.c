#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include "db.h"
#include "index.h"

/*
 * Deallocate memory for database and indices objects
 * at end of main program.
 */
void cleanup(struct db *database, struct tnode **indices, const int *indexcolumns) {
    free(database);
    for (int i = 0; i < sizeof(indexcolumns)/sizeof(int); i++) {
        free(indices[indexcolumns[i]]);
    }
    free(indices);

}

int main() {

    // allocate memory for database and indices dynamic objects.
    struct db *database = dballoc();
    // add items to first column, incrementing row
    add(database, "foo", 0,0);
    add(database, "bar", 1, 0);
    add(database, "who", 2, 0);
    // add items to second column, incrementing row
    // from beginning
    add(database, "bicycle", 0, 1);
    add(database, "kite", 1, 1);
    add(database, "skateboard", 2, 1);
    printdb(database);

    int indexcolumns[] = {0, 1};
    // build indices
    struct tnode **indices = buildindices(database, indexcolumns);


//    struct tnode **indices = indicesalloc();
//
//    for (int i = 0; i < sizeof(indexcolumns)/sizeof(int); i++) {
//        indices[indexcolumns[i]] = talloc();
//        indices[indexcolumns[i]] = addnode(indices[indexcolumns[i]], indexcolumns[i], database);
//    }
    cleanup(database, indices, indexcolumns);
}


