# Data Structures

## Create 100 elements in C++:
```C++
numbers[100];

for(int i = 0; i < 100; i++){
int[i] = i;
}
```
Use ```for``` loop in a C++ program to make an array of 100 elements
## Get the size of of the int element in the array. 

Use the ```sizeof()``` function

```C++
std::cout << sizeof(numbers) << " bytes" << std::endl;
```
## Number of steps for the following operations:
  • Reading: For reading an individual element in an array, it only takes 1 step. 
  
  • Searching: a value depends on where it is located to determine the number of steps. If the value being searched
  is at index 50, then it will take 50 steps to find it.
  
  • Insertion at the beginning: This will take, per our array above, 100 steps to shift each of the indices to the next indice and then 1 step to add the new element at the beginning. 
  
  • Insertion at the end, this should only take 1 step. 
  
  • Deletion depends on where the element is located. If its the last element, then only one step because no shifting is required. If its at the beginning, then there will be 100 steps because each element will have to shift down an index. 

## Multiple Search operations

The number of steps in our search will be N steps based on the number of elements in the array. We are not finding "apple"s and then stopping, we are checking each individual element so if its an array with 100 elements, each containing fruit names, then we will be checking all elements until the end of the array.  

## Find the memory address of a location

This is as simple as, especially in C, using the ```&``` operator to display the memory location. When you run ```&arr``` you are only viewing the memory address of the first element, not the entire array. We would need to use a  ```for``` loop if we wanted to display every single memory address

```C++
for(int i = 0; i < 100; i++){
cout << &arr[i] << endl;
}
```

## Complete C++ Code 
```C++
#include <iostream>
using namespace std;
int main() {

//CREATE AN ARRAY TO INT

//declare the array variable
int arr[100];

//initialize and assign to the individual array element indices
for(int i = 0; i < 100; i++){

arr[i] = i;
cout << arr[i] << endl;
}


//get the byte size of an individual element in the array for an int
cout << sizeof(arr[0]) << " Bytes" << endl;

//get memory address of the base element of the arr, add & to the array.

cout << &arr << " memory location" << endl;
cout << &arr[1] << " memory location" << endl;

//loop to see every single array element memory address
for(int i = 0; i < 100; i++){
cout << &arr[i] << endl;
}


return 0;


}
```
