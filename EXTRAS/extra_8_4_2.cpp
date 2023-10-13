#include <iostream>
using namespace std;
int main() {//cant ask complier where u put a
  int a; //static allocation - cannot be deleted from memory
  a=10;
  cout << a;

  int *p;
  p=&a;
  cout << *p; //=10
// dont need a bc they have same name?
  float *q;
  q=new float;           // dynamic allocation
  *q=14.6;

  cout << *q;
  delete q; 

  int *ptr=new int;
  
  *ptr=10;
  cout << *ptr/2; //find half

  delete ptr; //delete allocation and get more space
  
  
  return 0;
}

//p=new int
//1.allocate
//2.put allocation in p

//diff between a and p is their speed(p is faster?)

//delete p; deletes &p
//p stays gc wipes &p

//heap is dynaic allocation memory
//so we need BIG memory

//when do we use new int??