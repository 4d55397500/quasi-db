# simple db with index

A pedagogical example of a simple database implemented as a linked list with a binary search tree serving as an index. Each node of the binary search tree holds a pointer to the corresponding 'row' of the database.

**Background**

A binary search tree facilitates O(lg n) lookup of a key, with which a corresponding database row is accessed directly by way of a pointer.

**To do**

- add support for multiple indices each as a separate binary search tree
- persist database and index to disk



