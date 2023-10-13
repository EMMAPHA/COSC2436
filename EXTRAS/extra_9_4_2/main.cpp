//THIS WILL RUN ON REPLIT
#include <iostream>
#include "word.h"
using namespace std;

int main() {
  word list;
  list.insertatbeg('m');
  list.insertatbeg('o');
  list.insertatbeg('n');
  list.insertatbeg(' ');
  list.insertatbeg('t');
  list.insertatbeg('a');
  list.insertatbeg('c');
  list.insertatbeg(' ');
  list.insertatbeg('m');
  list.insertatbeg('o');
  list.insertatbeg('n');
  list.insertatbeg(' ');
  list.insertatbeg('g');
  list.insertatbeg('o');
  list.insertatbeg('d');
  //why does this run slow every time I add asomething new to insert at beg
  list.del_c('q');
  list.print(list.getHead());
  cout << endl;
  list.recPrint(list.getHead());
  // list.reversePrint(list.getHead());

  
}