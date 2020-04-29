#ifndef DB_H_
#define DB_H_

struct db {
    char *value;
    // can add more items to database row ...
    struct db *next;
};

struct db *dballoc();
struct db *addstring(struct db *database, char *value);


#endif

