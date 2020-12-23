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
        for (int i = 0; i < NCOLS; i++){
            database->value[i] = NULL;
        }
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

void save(struct db *database, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp)
        perror("fopen");
    struct db *rowptr = database;
    while (rowptr) {
     fwrite(&rowptr->value, sizeof rowptr->value, 1, fp);
     rowptr = rowptr->next;
    }
    fclose(fp);
}

struct db *load(char *filename) {
    FILE *fp = fopen(filename, "rb");
    struct db *database = dballoc();
    database->next = NULL;
    char *value[NCOLS];
    int row = 0;
    while (fread(&value, sizeof value, 1, fp)) {
        for (int col = 0; col < NCOLS; col++) {
            if (value[col]) {
                add(database, value[col], row, col);
            }
        }
        row++;
    }
    return database;
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