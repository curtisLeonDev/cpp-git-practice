# Implementing Hash Tables

## Part 1 — Understanding Hash Functions & Part 2. 
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
## Part 3 — Linear Probing
for the hash table implement a struct of type Record, and then generate a vector array with 11 slots. 
```c++
struct Record {
    int key;
    string value;
};

  int tableSize = 11; 
  
   vector<Record> record(tableSize);
    
   for(int i = 0; i < tableSize; i++){

    record[i].key = i;
    record[i].value = "EMPTY";

   }
for(int i = 0; i < tableSize; i++){
    cout << record[i].key << '\t' << record[i].value << endl;
}
```
This will automatically assign the EMPTY so all elements are marked as empty to each slots value. After generating the hash table, we will print it: 

key    value
------------
0       EMPTY

1       EMPTY

2       EMPTY

3       EMPTY

4       EMPTY

5       EMPTY

6       EMPTY

7       EMPTY

8       EMPTY

9       EMPTY

10      EMPTY

## INSERT FUNCTION

We create a funtion to insert the element into the vector array. The first step is to check if the generated hash is available, if its marked empty then, because its nested in a if statement, the function returns the value 1 for success. 

if that location is full, then we envoke the else statement that executes a while loop, incrementing the provided key until we find an "EMPTY" location. 
if the hash location is farther down the array, then we also include an if statement to reset the key to 0 to check for empties. A count is also implemented, so if the entire table size is checked, and no elmements are available, we break the while loop and return 0 for success. 

```c++
int insertElement(vector<Record> &record, int keys, string values, int tableSize){

int home = keys;
int recordCount = 0;
    if(record[keys].value == "EMPTY"){
    record[keys].key = keys;
        record[keys].value = values;
  
    } else {
    while(record[keys].value != "EMPTY"){
        if(recordCount == tableSize){
            break;
        }
        if(record[keys].value == "EMPTY"){
            record[keys].key = keys;
            record[keys].value = values;
   
            break;
        
        } else {

        if(keys == (tableSize-1)){
            keys = 0;
        } else {
keys++;

        }
        
    }
   
}
    }

   cout << "Value :" << values << "\nHome position: " << home << "\nActual position: " << keys << endl;
return keys;


}
```
Current full Code: 

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Record {
    int key;
    string value;
};
   int tableSize = 11; 
   vector<Record> record(tableSize);
int hashFunction(int key, int tableSize);
int insertElement(vector<Record> &record, int keys, string values, int tableSize);



int main(){


    
   for(int i = 0; i < tableSize; i++){

    record[i].key = i;
    record[i].value = "EMPTY";

   }

    
 
insertElement(record, hashFunction(555223, tableSize), "555223", tableSize);
insertElement(record, hashFunction(555980, tableSize), "555980", tableSize);
insertElement(record, hashFunction(555000, tableSize), "555000", tableSize);
insertElement(record, hashFunction(555890, tableSize), "555890", tableSize);
insertElement(record, hashFunction(555225, tableSize), "555225", tableSize);
insertElement(record, hashFunction(555982, tableSize), "555982", tableSize);
insertElement(record, hashFunction(555004, tableSize), "555004", tableSize);
insertElement(record, hashFunction(555897, tableSize), "555897", tableSize);
insertElement(record, hashFunction(555899, tableSize), "555899", tableSize);
insertElement(record, hashFunction(555892, tableSize), "555892", tableSize);
insertElement(record, hashFunction(555791, tableSize), "555791", tableSize);

for(int i = 0; i < tableSize; i++){
  cout <<  record[i].key << '\t' << record[i].value << endl;
}

    /*    cout << hashFunction(555980, tableSize) << endl;
    cout << hashFunction(555000, tableSize) << endl;
    cout << hashFunction(555890, tableSize) << endl;
   */ 
    
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
//insert

int insertElement(vector<Record> &record, int keys, string values, int tableSize){

int home = keys;
int recordCount = 0;
    if(record[keys].value == "EMPTY"){
    record[keys].key = keys;
        record[keys].value = values;
  
    } else {
    while(record[keys].value != "EMPTY"){
        if(recordCount == tableSize){
            break;
        }
        if(record[keys].value == "EMPTY"){
            record[keys].key = keys;
            record[keys].value = values;
   
            break;
        
        } else {

        if(keys == (tableSize-1)){
            keys = 0;
        } else {
keys++;

        }
        
    }
   
}
    }

   cout << "Value :" << values << "\nHome position: " << home << "\nActual position: " << keys << endl;
return keys;


}
```

