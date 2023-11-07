#include <iostream>
#include "dhash.h" 
using namespace std;


void search(dhash table, int searchValue){
  if (table.search(searchValue)) {
      cout << searchValue << " found in the table." << endl;
  } else {
      cout << searchValue << " not found in the table." << endl;
  }
}
int main() {
    dhash table(10); 

  
    table.doubleHashing(5);
    table.doubleHashing(15);
    table.doubleHashing(25);
    table.doubleHashing(35);
    table.doubleHashing(45);

   
    cout << "Hash table:" << endl;
    table.print();

    search(table, 15);
    
    table.deleteElement(25);

    // updated hash table
    cout << "Hash table:" << endl;
    table.print();
     search(table, 25);
    return 0;
}
