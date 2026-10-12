# Liked Lists

## Part 1 - Understanding Nodes and Pointers

```c++
struct Node {
int data;
Node* next;
};
```
```
 head(the reference pointer to the first linked item, stores the memory address)  
 ↓
+----+------+    +----+------+    +----+------+    +----+---------+
| 10 | add2 | -> | 20 | add3 | -> | 30 | add4 | -> | 40 | nullptr |
+----+------+    +----+------+    +----+------+    +----+---------+
```
1. Head does not contail the value 8.
2. Head stores only the memory address for the first linked element in the list.
3. first->next contains the data in int format and the memory address in next (which is of type pointer). 
4. third->net contains the value ```c++ nullptr```
5. If you lose the value of head, there is no way to know what the beginning address of the list is.

## Part 2 - 
