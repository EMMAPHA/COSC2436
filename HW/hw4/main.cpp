#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

void linearProbing(int table[], int size, int x){  //checks out
    int index = 0;
    for(int i = 0; i < size; i++){
        index = ((x % size) + i) % size; //change to int index
        if(table[index] == -1){ //
            table[index] = x;
            break;
        }
    }   
}

void quadraticProbing(int table[], int size, int x){ //checks out
    int index = 0;
    for(int i = 0; i < size; i++){
        index = ((x % size) + (3 * i + 5 * i * i)) % size;
        if(table[index] == -1){ 
            table[index] = x;
            break;
        }
    }
}

bool checkDuplicate(int hashTable[], int hashTableSize, int valueFromInput){
  for(int i = 0; i < hashTableSize; i++){
    if(valueFromInput == hashTable[i]){
      return true;
    }
  }
  return false;
}

void heapify(int arr[],int n, int i){ //checks out
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] < arr[smallest]){
        smallest = l;
    }

    if(r < n && arr[r] < arr[smallest]){
        smallest = r;
    }

    if(smallest != i){
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr, n, smallest);
    }

}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    int tableSize = 0;
    string hashType, listOfNums= "";

    ifs >> tableSize;
    ifs.ignore();
    getline(ifs, hashType);
    getline(ifs, listOfNums);

    istringstream listNum(listOfNums);
    string numsStr;
    int dataValues[tableSize];
    int hashTable[tableSize];
    

    for(int i = 0; i < tableSize; i++){
        hashTable[i] = -1; //empty cells
    }

while(getline(listNum, numsStr, ',')){ //
    int num = stoi(numsStr);

    if(checkDuplicate(hashTable, tableSize, num)){
        continue;
    }

 if (hashType.find("Linear probing") != -1) {

    linearProbing(hashTable, tableSize, num);

 }
 else if (hashType.find("Quadratic probing") != -1) {

     quadraticProbing(hashTable, tableSize, num);
 }

}//
bool flag = false;
for(int i = 0; i < tableSize;i++){
    // if(i > 0){
    //     ofs << ',';
    // }
    // if(hashTable[i] != -1){
    // ofs << hashTable[i];
    // } 

    if(hashTable[i]==-1){
        continue;
    }
    else if(flag == false){
        ofs << hashTable[i];
        flag = true;
    }
    else if(flag == true){
        ofs << "," << hashTable[i];
    }
}
ofs << endl;
// for(int i = 0; i < tableSize; i++){
//   dataValues[i] = hashTable[i];
// for(int j = tableSize/2-1;j>=0;j--){ 
//         heapify(hashTable, i + 1, j); /////
// }
// }
// flag = false;
// for(int i = 0; i < tableSize;i++){
//     if(hashTable[i]==-1){
//         continue;
//     }
//     else if(flag == false){
//         ofs << hashTable[i];
//         flag = true;
//     }
//     else if(flag == true){
//         ofs << "," << hashTable[i];
//     }//changed to hashTable
// } 
int newSize = 0;
for(int i = 0; i < tableSize; i++){
	if(hashTable[i] != -1){
       newSize++;
    }
}
int *newArr = new int[newSize];
int j = 0;
for(int i = 0; i < tableSize; i++){
	if(hashTable[i] != -1){
		newArr[j] = hashTable[i];
		j++;
	}
}
 
for(int i = 0; i < newSize; i++){
	for(int k = newSize / 2 - 1; k >= 0; k--){
		heapify(newArr, i + 1, k);
	}
}
 
for(int i = 0; i < newSize;i++){
    if(i > 0){
        ofs << ',';
    }
	ofs << newArr[i];
}

ofs << endl;

    ifs.close();
    ofs.close();
    return 0;
}  