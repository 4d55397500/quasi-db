#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "tnode.h"
#include "db.h"

struct tnode *talloc(void) {
    struct tnode *node = (struct tnode *) malloc(sizeof(struct tnode));
    node->value = NULL;
    node->rowptr = NULL;
    node->left = NULL;
    node->right = NULL;
}

/**
 * Add the database entry at the row given by `rowptr`, and
 * the column given by `col`, to the tree index given by the
 * passed pointer `p`.
 */
struct tnode *addnode(struct tnode *p, int col, struct db *rowptr) {
    p->rowptr = rowptr;
    // if database row is null assumed nothing to add, return
    if (rowptr == NULL) {
        printf("null database row pointer found, returning");
        return p;
    }
    char *s = rowptr->value[col];
    // if database entry is null or the empty string nothing to add,
    // return
    if (s == NULL || strcmp(s, "") == 0) {
        //printf("empty database entry found, returning");
        return p;
    }
    //printf("Entry to be added: %s\n", s);
    // if the current node is null, write the database entry here
    if (p->value == NULL) {
        p->value = s;
        p->left = p->right = NULL;
        printf("added %s to a null node\n", s);
    } else if ((strcmp(s, p->value)) < 0) {
        p->left = addnode(p->left, col, rowptr);
        printf("moved %s left\n", s);
    } else {
        p->right = addnode(p->right, col, rowptr);
        printf("moved %s right\n", s);
    }
    printf("current p value: %s\n", p->value);
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

