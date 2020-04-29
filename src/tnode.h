#ifndef TNODE_H_
#define TNODE_H_


struct tnode {
    char *value;
    struct db *rowptr;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, int col, struct db *);
void printnode(struct tnode *);
void walk(struct tnode *, void (*)(struct tnode *));
void printwalk(struct tnode *);


#endif // TNODE_H_


