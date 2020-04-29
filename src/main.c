#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include "db.h"
#include "index.h"



int main() {

    struct db *database = NULL;
    database = addstring(database, "foo");
    addstring(database, "bar");
    addstring(database, "who");

    struct tnode *index = NULL;
    index = buildindex(database);

    struct db *rowptr;

    char *key = "bar";
    rowptr = lookup(index, key);
    printf("Retrieved pointer %p from index "
           "pointing to row containing '%s'.\n", rowptr, key);

}