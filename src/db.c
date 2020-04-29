#include <stdlib.h>
#include <string.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}


struct db *add(struct db *database,
               char *value, int columnindex) {
    if (database == NULL) {
        database = dballoc();
        strcpy(database->value[columnindex], value);
        //database->value[columnindex] = (char *)malloc(sizeof(value));
        //database->value[columnindex] = strdup(value);
        database->next = NULL;
    } else {
        database->next = add(database->next, value, columnindex);
    }
    return database;
}

