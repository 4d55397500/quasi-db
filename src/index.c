#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include "db.h"
#include "tnode.h"


struct tnode **indicesalloc() {
    return (struct tnode **) malloc(NCOLUMNS * sizeof(struct tnode));
}

/**
 * Build indices over the specified columns of the
 * database
 */
struct tnode **buildindices(struct db *database,
        const int *columns) {
    struct tnode **indices = indicesalloc();
    return indices;

}

//
//// build indices over the specified columns
//struct tnode **buildindices(struct tnode **indices, struct db *database) {
//    indices = indicesalloc();
//    for (int i = 0; i < 1; i++) {
//        indices[i] = (struct tnode *) malloc(sizeof(struct tnode));
//    }
//    while (database != NULL) {
//        for (int i = 0; i < 1; i++) {
//            indices[i] = addtree(indices[i], i, database);
//        }
//        database = database-> next;
//    }
//    return indices;
//}

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
