# Implementing Hash Tables

## Implementing the Hash Function. 
For this hashing function, we will start by add all the numbers together. 

```c++
int makeHash(int key) {
int addHash = 0;
for(int i = 0; i < 6; i++){
addHash += key % 10;
key /= 10;
}
return addHash %= 10;
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
