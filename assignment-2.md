# Searching

# Linear Search
It would take 4 comparisons. 

In a linear search, it will compare until it compares in index order until the element is found. So when Element 8 was found, it took 4 comparisons: index: 0,1,2,3. 

## Binary Search
It would take 1 comparisons

as we continue to break down the list, we are comparing > < to modified front and big indices and small indices. If a match is not made, then the comparison elements inherit the current values. 8 just happened to be the whole number: (L+R)/2; in this array (round down to the nearest whole number.

## Linear search for 100,000 elements

log_10(100,000)/(log_10(2)) ≈ 16.6096 = O(17)

## Linear and Binary Search Program

```C++
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
int n = 100000;
int L = 0;
int R = n-1;
int m = 0;
int T = 8;
int found = 0;
int count = 0;
int index = 0;

//create array
vector<int> cache(n);

for(int i = 0; i < n; i++){
cache[i] = i;
}



//linear search


while(index <= (n-1)){

if(cache[index] == T){
    cout << " Linear search found target element at: " << index << endl;
    cout << " Linear search did this many comparisons: " << (count+1) << endl;
    count++;
    found = 1;
    break;
}  else {
    ++index;
    ++count;
} 
}

if(found == 0){
    cout << "Linear search unsucessfull\n";
}




//start binary search

count = 0;
found = 0;
while(L <= R){

m = (L+R)/2;
if(cache[m] == T){
    found = 1;
    count++;
    break;

}else if(L > R){
cout << "Search Unsuccessful\n";
break;
}else if(cache[m] < T){
    L = m+1;
    ++count;
} else {
    R = m-1;
    ++count;
}

}

if(found == 0){
    cout << "Not found in Binary Search" << endl;
} else {
    cout << "Binary search found at index number: " << m << ".\n It took this many comparisons: " << count << endl;
}


}
```
The worst case time complexity for linear search is O(100000). The reason is after each comparison, you have only removed 1 element from the search space. 

The worst case time complexity for the binary search is O(17). The program compares greater than and less then and basically divides in half the remaining space until it finds the target element. 

Binary Data needs to be sorted so that we can accurately find the target result, because it is in order and needs to be compared greater or less than to the target item, to narrow the space block left. 

## Random Searching

### PSEUDOCODE
```
n = 100,000

1. for() create database with n members
2. generate random number
3. while target != database[n]
    check random number
    if ok - compare with database and terminate
    if not ok - return to 2.
4. return result
```

### Complexity Analysis

Best: O(1)
Average: 0(N)
Worst: 0(N)

### Implementation

```c++
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(){

//make dataset

int n = 100000;
int i = 0;
int target = 45987;
int count = 0;
int found = 0;
int random = 0;

vector<int> database(n);
vector<int> used_indices(n, -1);

for(int i = 0; i < n; i++){
    database[i] = i;
}

random_device rd;
mt19937 gen(rd());

uniform_int_distribution<int> distrib(0, n - 1);

while(found == 0){

  
    random = distrib(gen);

    bool already_used = false;

    for(int j = 0; j < i; j++){
        if(used_indices[j] == random){
            already_used = true;
            break;
        }
    }

    if(already_used){
        continue;
    }

    used_indices[i] = random;
    i++;

  
    count++;

    if(database[random] == target){
        found = 1;

        cout << "Random search found target element: "
             << database[random] << endl;

        cout << "Random search found target element at index: "
             << random << endl;

        cout << "Random search did this many comparisons: "
             << count << endl;
    }
}

return 0;
}


```

