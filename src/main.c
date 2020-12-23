#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include "db.h"
#include "index.h"



int main() {

    struct db *database = NULL;
    printf("Writing to database ...\n");
    database = add(database, "foo");
    add(database, "bar");
    add(database, "who");

    printf("Building index ...\n");
    struct tnode *index = NULL;
    index = buildindex(database);

    struct db *rowptr;

    char *key = "bar";
    printf("Looking up key '%s' in index ...\n", key);
    rowptr = lookup(index, key);
    printf("Retrieved pointer %p from index "
           "to db row containing '%s'.\n", rowptr, key);

}