#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}


struct db *add(struct db *database,
        char *value, int row, int col) {
    if (database == NULL) {
        database = dballoc();
        database->next = NULL;
    }
    if (row == 0) {
        database->value[col] = strdup(value);
    } else {
        database->next = add(database->next, value, row - 1, col);
    }
    return database;
}


int dblen(struct db *database) {
    int n = 0;
    struct db *rowptr = database;
    while (rowptr != NULL) {
        rowptr = rowptr->next;
        n++;
    }
    return n;
}


void printdb(struct db *database) {
    printf("---------\n");
    struct db *rowptr = database;
    int row = 0;
    while (rowptr != NULL) {
        for (int col = 0; col < NCOLS; col++) {
           if (rowptr->value[col] != NULL) {
               printf("%s (row = %d, col = %d) ", rowptr->value[col], row, col);
               printf("\n");
           }
        }
        rowptr = rowptr->next;
        row++;
    }
    printf("---------\n");
}