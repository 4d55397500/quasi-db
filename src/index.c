#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include "db.h"
#include "tnode.h"



struct tnode **indicesalloc(const int *columns) {
    struct tnode **indices = malloc(NCOLUMNS * sizeof(struct tnode));
    int ncolumns = sizeof(columns)/sizeof(int);
    for (int i = 0; i < ncolumns; i++) {
        indices[i] = talloc();
    }
    return indices;
}

/**
 * Build indices over the specified columns of the
 * database
 */
struct tnode **buildindices(struct db *database,
        const int *columns) {
    struct tnode *indices = malloc(sizeof(struct tnode *) * NCOLUMNS);
    for (int i = 0; i < sizeof(columns)/sizeof(int); i++) {
        indices[i] = *(struct tnode *)malloc(sizeof (struct tnode));//*talloc();
    }
    printf("Writing indices...\n");
    while (database != NULL) {
        for (int i = 0; i < sizeof(columns)/sizeof(int); i++) {
            if (indices[i].value != NULL) {
                char *t = indices[i].value;
                printf("Found %s\n", t);
            }
            //indices[i]->value = NULL;
            addnode(&indices[i], columns[i], database);
        }
        database = database->next;
    }
    printf("Finished writing indices.\n");
    return &indices;
}

void printindices(struct tnode **indices, const int *columns) {
    for (int i = 0; i < sizeof(columns)/sizeof(int); i++){
        printwalk(indices[i]);
    }
    printf("tbd: print all indices");
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
