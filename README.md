# db-models-c

Repository for exploring database concepts and structures in c, loosely exploring these [notes](https://www.redwrasse.io/notes/dbconcepts).


**Linked list- binary search tree model**

Database as a linked list and indices as (unbalanced) binary search trees (both in memory).
A binary search tree facilitates O(lg n) lookup of a key, with which a corresponding 'database row' is accessed directly by way of a pointer.

```c
Writing to an 100-column database 10000 entries ...
Successfully wrote 10000 entries.
Printing database ...
Building indices for all columns ...
Looking up key 'g7T=vb' in index for column '57' ...
Retrieved pointer 0x7f8b9bf47bf0 from index to db row containing 'g7T=vb'.

```

**To do**

- add support for multiple indices each as a separate binary search tree
- persist database and index to disk

### References

* [Databases notes](https://www.redwrasse.io/notes/dbconcepts)
* [Ref. Python implementation](https://github.com/redwrasse/dbpy)