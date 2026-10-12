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

## Part 2 - Trace a linked list

```c++
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

int main(){

Node *first = new Node{10, nullptr};
Node *second = new Node{20, nullptr};
Node *third = new Node{30, nullptr};
Node *four = new Node{40, nullptr};

Node* temp = first;

first->next = second;
second->next = third;
third->next = four;
four->next = nullptr;

while(temp != nullptr){
    cout << temp->data << '\n';
    temp = temp->next;
}


}
```
The tracing stops because the linked list reaches the next of the forth element in the list that has the value of nullptr, that was instructed in the while loop.
The big O complexity is O(n). The linked list traverses the entire list up to the point of the nullptr value in the final next variable. in this instance the worst case is O(4), best case O(1). 

