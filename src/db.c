#include <stdlib.h>
#include <string.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}


struct db *addstring(struct db *database,
                     char *value) {
    if (database == NULL) {
        database = dballoc();
        database->value = strdup(value);
        database->next = NULL;
    } else {
        database->next = addstring(database->next, value);
    }
    return database;
}

