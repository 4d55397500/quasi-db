#ifndef DB_H_
#define DB_H_
#define NCOLS 25

struct db {
    char *value[NCOLS];
    // can add more items to database row ...
    struct db *next;
};

struct db *dballoc();
struct db *add(struct db *, char *, int, int);
int dblen(struct db *);
void save(struct db *, char *);
struct db *load(char *);
void printdb(struct db *);

#endif

