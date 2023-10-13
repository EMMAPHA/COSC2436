//RUNS ON REPLIT
#include <iostream>
using namespace std;
#include "necklace.h"


int main() {
  necklace birthday;
  birthday.insertpearl(2, 7);
  birthday.insertpearl(4, 44);
  birthday.insertpearl(5,50);

  birthday.print();

  return 0;
  
  }