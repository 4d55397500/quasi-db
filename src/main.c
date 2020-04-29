#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include "db.h"
#include "index.h"

int main() {

    struct db *database = NULL;

    database = add(database, "foo", 0);
    add(database, "bar", 0);
    add(database, "who", 0);

    add(database, "bicycle", 1);
    add(database, "kite", 1);

    struct tnode **indices = NULL;
    indices = buildindices(database);

    struct db *rowptr;
    char *key = "bar";
    rowptr = lookup(indices[0], key);
    printf("Retrieved pointer %p from index "
           "pointing to row containing '%s'.\n", rowptr, key);

    struct db *rowptr2;
    char *key2 = "kite";
//    rowptr2 = lookup(indices[1], key2);


}