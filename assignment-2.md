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
