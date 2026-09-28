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