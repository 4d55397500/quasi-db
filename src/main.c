#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tnode.h"
#include "db.h"
#include "index.h"



int main() {

    srand(time(NULL));

    struct db *database = NULL;

    int n = 6;
    char s[n];
    char *key;
    int m = 10000;
    int k = rand() % m;

    printf("Writing to database %d entries ...\n", m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            s[j] = '0' + rand() % 72;
        }
        if (i == k) {
            key = s;
        }
        database = add(database, s);
    }

    printf("Building index ...\n");
    struct tnode *index = NULL;
    index = buildindex(database);

    struct db *rowptr;
    printf("Looking up key '%s' in index ...\n", key);
    rowptr = lookup(index, key);
    printf("Retrieved pointer %p from index "
           "to db row containing '%s'.\n", rowptr, key);

}