#include <stdlib.h>
#include <stdio.h>
#include "strings.h"

#define COLS 5
#define CELL 100
#define ROWS 1000

struct row {
    char *key;
    char data[COLS][CELL];
};

struct db {
    struct row rows[ROWS];
    int tail;
};

struct keyindex {
    
};

struct db* dballoc() {
    struct db* database = (struct db*) malloc(sizeof(struct db));
    database->tail = 0;
    return database;
}

struct db* insertrow(struct db* database, struct row* r) {
    if (database->tail < ROWS) {
        database->rows[database->tail] = *r;
        (database->tail)++;
    }
    return database;
}

// example: SELECT * FROM db WHERE col3 = 'foo'
// a 'dumb' full scan of all the rows for one with the
// specified string in the specified column.
struct row* dbfind(struct db* database, const char *s, int col) {
    char* entry;
    for (int i = 0; i < database->tail; i++) {
        entry = database->rows[i].data[col];
        if (strcmp(entry, s) == 0) {
            return &database->rows[i];
        }
    }
    return NULL;
}

struct row* rowalloc(char *key) {
  struct row* r = (struct row*) malloc(sizeof(struct row));
  r->key = key;
  return r;
};

struct row* insert(struct row* r, int col, char* s) {
    strcpy(r->data[col], s);
    return r;
}

void printrow(struct row* r) {
    printf("[%s] |", r->key);
    for (int i = 0; i < COLS; i++) {
        if (strlen(r->data[i]) > 0) {
            printf("%s|", r->data[i]);
        } else {
            printf("(empty)|");
        }

    }
    printf("\n");
}

void printdb(struct db* database) {
    for (int i = 0; i < database->tail; i++) {
        printrow(&(database->rows)[i]);
    }
}

int main() {
    struct row* r = rowalloc("key1");
    r = insert(r, 0, "foo");
    r = insert(r, 3, "bar");
    struct row* r2 = rowalloc("key2");
    r2 = insert(r2, 1, "car");
    r2 = insert(r2, 4, "abc");
    //printrow(r);
    struct db* database = dballoc();
    insertrow(database, r);
    insertrow(database, r2);
    printdb(database);
    struct row* r3 = dbfind(database, "car", 1);
    printf("Found %s in row %s\n", "car", r3->key);
    free(database);
}

