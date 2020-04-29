#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include "db.h"
#include "index.h"

int main() {

    struct db *database = NULL;

    // add items to first column, incrementing row
    database = add(database, "foo", 0, 0);
    add(database, "bar", 1, 0);
    add(database, "who", 2, 0);

    // add items to second column, incrementing row
    // from beginning
    add(database, "bicycle", 0, 1);
    add(database, "kite", 1, 1);

    printdb(database);


    struct tnode **indices;
    indices = buildindices(indices, database);
    //printwalk(indices[0]);
//    for (int indexcol = 0; indexcol < 2; indexcol++) {
//        printwalk(indices[indexcol]);
//    }

//    struct db *rowptr;
//    char *key = "bar";
//    rowptr = lookup(indices[0], key);
//    printf("Retrieved pointer %p from index "
//           "pointing to row containing '%s'.\n", rowptr, rowptr->value[0]);

    struct db *rowptr2;
    char *key2 = "kite";
    //rowptr2 = lookup(indices[0], key2);


}