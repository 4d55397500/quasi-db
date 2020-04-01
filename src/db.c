#include <stdlib.h>
#include <string.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}


struct db *add(struct db *database,
        char *value) {
    if (database == NULL) {
        database = dballoc();
        database->value = strdup(value);
        database->next = NULL;
    } else {
        database->next = add(database->next, value);
    }
    return database;
}

