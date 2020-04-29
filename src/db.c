#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}

/*
 * Add a string entry to the database at the specified column
 * and row. Pass a pointer to the start of the database;
 * the returned database pointer does not change.
 */
struct db *add(struct db *database,
               char *value, int rowindex, int columnindex) {
    // allocate memory if not yet allocated
    if (database == NULL) {
        database = dballoc();
    }
    // copy the passed string to the appropriate row and column
    if (rowindex == 0) {
        strcpy(database->value[columnindex], value);
    } else {
        database->next = add(database->next, value, rowindex - 1,
                columnindex);
    }
    return database;
}

void printdb(struct db *database) {
    printf("Printing database elements ...\n---\n");
    int row = 0;
    while (database != NULL) {
        printf("(row %d)\t|", row);
        for (int col = 0; col < NCOLUMNS; col++) {
            printf("%s|", database->value[col]);
        }
        printf("\n");
        database = database -> next;
        row++;
    }
    printf("---\n");
}