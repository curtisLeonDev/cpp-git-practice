# Implementing Hash Tables

## Implementing the Hash Function. 
For this hashing function, we will start by add all the numbers together. 

```c++
int hashFunction(int key, int tableSize) {
int count = 0;
int keyCount = key;
while(keyCount != 0){
keyCount /= 10;
++count;
}

int addHash = 0;
for(int i = 0; i < count; i++){
addHash += key % 10;
key /= 10;
}
return addHash %= tableSize;
}
```
When running this program, it creates a hash by using += to addHash buy taking the modulus of the number by 10, and then you need to remove that previous digit by dividing the key each time until you get to 0. 

Finally, after adding the item, i return the addHash % 10; to get the hash number. Doing the % 10 means you will not get a number larger than 10 for the index.

for the items: 


Key	Digit       Sum	Table Index
555223		       2
555980		       2
555000		       5
555890	         2

There were two collisions with the original (555223) that occupied that space in memory. 

Increasing the size of the table does help by using the 0.7 rule; but it can never guarantee that no collisions occur. When adding the hash, different digits in a number, from two different numbers of keys, can add to the same sum index and then and return the same modulus. 

The complete code for this part is: 
```c++
#include <iostream>
#include <vector>

using namespace std;



int hashFunction(int key, int tableSize);




int main(){
    
vector<int> hashTable(10);
    
int tableSize = 10;
    
    
    
    cout << hashFunction(555223, tableSize) << endl;
    cout << hashFunction(555980, tableSize) << endl;
    cout << hashFunction(555000, tableSize) << endl;
    cout << hashFunction(555890, tableSize) << endl;
    
    
    return 0;
}
//hashing function
int hashFunction(int key, int tableSize) {
int count = 0;
int keyCount = key;
while(keyCount != 0){
keyCount /= 10;
++count;
}

int addHash = 0;
for(int i = 0; i < count; i++){
addHash += key % 10;
key /= 10;
}
return addHash %= tableSize;
}
```
