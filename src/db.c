#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "db.h"


struct db *dballoc() {
    return (struct db *) malloc(sizeof(struct db));
}


struct db *add(struct db *database,
               char *value, int rowindex, int columnindex) {
    if (database == NULL) {
        database = dballoc();
        strcpy(database->value[columnindex], value);
        //database->value[columnindex] = (char *)malloc(sizeof(value));
        //database->value[columnindex] = strdup(value);
        database->next = NULL;
    } else if (rowindex == 0) {
        strcpy(database->value[columnindex], value);
    }
    else {
        database->next = add(database->next, value, rowindex - 1,
                columnindex);
    }
    return database;
}

void printdb(struct db *database) {
    printf("Printing database elements ...\n---\n");
    int row = 0;
    while (database != NULL) {
        printf("(row %d)|", row);
        for (int col = 0; col < NCOLUMNS; col++) {
            printf("%s|", database->value[col]);
        }
        printf("\n");
        database = database -> next;
        row++;
    }
    printf("---\n");
}