#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "tnode.h"
#include "db.h"

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/**
 * Add the database entry at the row given by `rowptr`, and
 * the column given by `col`, to the tree index given by the
 * passed pointer `p`.
 */
struct tnode *addnode(struct tnode *p, int col, struct db *rowptr) {
    printf("Building index over column %d of database...\n", col);
    p->rowptr = rowptr;
    // if database row is null assumed nothing to add, return
    if (rowptr == NULL) {
        return p;
    }
    char *s = rowptr->value[col];
    // if database entry is null or the empty string nothing to add,
    // return
    if (s == NULL || sizeof(s) == 0) {
        return p;
    }
    printf("Entry to be added: %s\n", s);
    return p;


//    char *s = rowptr->value[col];
//    if (p == NULL) {
//        p = talloc();
//        p->rowptr = rowptr;
//        //strcpy(p->value, s);
//        p->value = strdup(s);
//        //p->value = strdup(rowptr->value);
//        p->left = p->right = NULL;
//    } else if ((strcmp(s, p->value)) == 0) {
//        if (p->rowptr == NULL){ //currently only index the first occurrence of a value
//            p->rowptr = rowptr;
//        }
//    }
//    else if ((strcmp(s, p->value)) < 0)
//        p->left = addtree(p->left, col, rowptr);
//    else
//        p->right = addtree(p->right, col, rowptr);
//    return p;
}

void printnode(struct tnode *p) {
    printf("node: %s\n", p->value);
}

// depth-first traversal
void walk(struct tnode *p, void (*callback)(struct tnode *)) {
    if (p != NULL) {
        walk(p->left, callback);
        callback(p);
        walk(p->right, callback);
    }
}

void printwalk(struct tnode *p) {
    walk(p, printnode);
}

