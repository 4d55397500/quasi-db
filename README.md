# db-models-c

Repository for exploring database concepts and structures in c, loosely exploring these [notes](https://www.redwrasse.io/notes/dbconcepts).


**Linked list- binary search tree model**

Database as a linked list and indices as (unbalanced) binary search trees (both in memory).
A binary search tree facilitates O(lg n) lookup of a key, with which a corresponding 'database row' is accessed directly by way of a pointer.

```c
Writing to database 10000 entries ...
Building index ...
Looking up key 'ff]69q' in index ...
Retrieved pointer 0x7f827df11200 from index to db row containing 'ff]69q'.

```

**To do**

- add support for multiple indices each as a separate binary search tree
- persist database and index to disk

### References

* [Databases notes](https://www.redwrasse.io/notes/dbconcepts)
* [Ref. Python implementation](https://github.com/redwrasse/dbpy)
