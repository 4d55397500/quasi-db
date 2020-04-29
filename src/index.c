#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "db.h"
#include "tnode.h"


struct tnode **buildindices(struct db *database) {
    struct tnode *indices[NCOLUMNS];
    for (int i = 0; i < NCOLUMNS; i++) {
        indices[i] = (struct tnode *) malloc(sizeof(struct tnode));
        struct tnode *index = NULL;
        while (database != NULL) {
            index = addtree(index, database);
            database = database->next;
        }
        indices[i] = index;
    }
    return indices;
    //return index;
}

struct db *lookup(struct tnode *index, char *value) {
    int cond;
    if (index == NULL) {
        return NULL;
    }
    if ((cond = strcmp(value, index->value)) == 0) {
        return index->rowptr;
    } else if (cond < 0) {
        return lookup(index->left, value);
    } else
        return lookup(index->right, value);
}

