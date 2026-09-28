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
