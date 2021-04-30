# db-models-c

Repository for exploring database concepts and structures in c.


**Linked list- binary search tree model**
(This is hardly a database)
Database as a linked list and indices as (unbalanced) binary search trees (both in memory).
A binary search tree facilitates O(lg n) lookup of a key, with which a corresponding 'database row' is accessed directly by way of a pointer.

The linked list can be saved to disk. Upon loading, indices are rebuilt.

```c
Writing to an 25-column database 10000 entries ...
Successfully wrote 10000 entries.
Saving database to disk as db.bin ...
Loading database from file db.bin ...
Building indices for all columns ...
Looking up key 'ofcbnm' in index for column '19' ...
Retrieved pointer 0x7fac4342a3b0 from index to db row containing 'ofcbnm'.

```


### References

* [Databases notes](https://www.redwrasse.io/notes/dbconcepts)

