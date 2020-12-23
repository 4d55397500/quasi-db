#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "tnode.h"
#include "db.h"

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, struct db *rowptr, int col) {
    if (rowptr->value[col] == NULL) {
        return NULL;
    }
    int cond;
    if (p == NULL) {
        p = talloc();
        p->rowptr = rowptr;
        p->value = strdup(rowptr->value[col]);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(rowptr->value[col], p->value)) == 0) {
        if (p->rowptr == NULL){ //currently only index the first occurrence of a value
            p->rowptr = rowptr;
        }
    }
    else if (cond < 0)
        p->left = addtree(p->left, rowptr, col);
    else
        p->right = addtree(p->right, rowptr, col);
    return p;
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

