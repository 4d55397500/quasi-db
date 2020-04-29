#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "tnode.h"
#include "db.h"

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, int col, struct db *rowptr) {
    int cond;
    char *s = rowptr->value[col];
    if (p == NULL) {
        p = talloc();
        p->rowptr = rowptr;
        //strcpy(p->value, s);
        p->value = strdup(s);
        //p->value = strdup(rowptr->value);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(s, p->value)) == 0) {
        if (p->rowptr == NULL){ //currently only index the first occurrence of a value
            p->rowptr = rowptr;
        }
    }
    else if ((cond = strcmp(s, p->value)) < 0)
        p->left = addtree(p->left, col, rowptr);
    else
        p->right = addtree(p->right, col, rowptr);
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

