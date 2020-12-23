#ifndef INDEX_H_
#define INDEX_H_



struct tnode *buildindex(struct db *, int);
struct tnode **buildall(struct db *);
struct db *lookup(struct tnode *, char *);

#endif // INDEX_H_

