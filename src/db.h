#ifndef DB_H_
#define DB_H_
#define NCOLS 100

struct db {
    char *value[NCOLS];
    // can add more items to database row ...
    struct db *next;
};

struct db *dballoc();
struct db *add(struct db *, char *, int, int);
int dblen(struct db *);
void printdb(struct db *);

#endif

