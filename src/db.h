#ifndef DB_H_
#define DB_H_
#define MAXSTRINGLENGTH 100
#define NCOLUMNS 5

struct db {
    char value[NCOLUMNS][MAXSTRINGLENGTH];
    //char *value;
    // can add more items to database row ...
    struct db *next;
};

struct db *dballoc();
struct db *add(struct db *database, char *value, int columnindex);


#endif

