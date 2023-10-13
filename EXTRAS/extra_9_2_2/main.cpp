//RUNS ON REPLIT
#include <iostream>
#include "line.h"
using namespace std;

int main() {
  line green;
  int v1, v2;
  green.insertatbeg(7,11);
  green.insertatbeg(5,55);

  cout << "Original List: ";
    green.display();
  
  green.delfrombeg(v1,v2);
  cout << " I just deleted " << v1 << " and " << v2 <<endl;

  cout << "Updated List: ";
  green.display();
  
  green.insertatbeg(v1,v2);

  return 0;
}