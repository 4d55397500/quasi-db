#ifndef INDEX_H_
#define INDEX_H_

struct tnode **indicesalloc();
struct tnode **buildindices(struct db *, int *);
struct db *lookup(struct tnode *, char *);
void printindices(struct tnode **, int *);

#endif // INDEX_H_


