#ifndef INDEX_H_
#define INDEX_H_



struct tnode **buildindices(struct db *database);
struct db *lookup(struct tnode *, char *);

#endif // INDEX_H_

