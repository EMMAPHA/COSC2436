#include <iostream>
#include "stacki.h"
//extra 10_1_2 write a function to reverse a stack
//recursively

template <typename T>
void reverse_stack(stacki<T>& mystack, stacki<T>& yourstack) {
    if (mystack.isEmpty()) {
        return;
    } else {
        T v = mystack.peek();
        mystack.pop();
        yourstack.push(v);
        reverse_stack(mystack, yourstack);
    }
}
//function to try to do it with one parameter for stack
template <typename T>
void reverseStackv2(stacki<T>& stack){
  if(stack.isEmpty()){
    return;
  }

  T k = stack.peek();
  stack.pop();
  reverseStackv2(stack);

  stacki<T> tempStack;
  while(!stack.isEmpty()){
    tempStack.push(stack.peek());
    stack.pop();
  }
  stack.push(k);
  while(!tempStack.isEmpty()){
    stack.push(tempStack.peek());
    tempStack.pop();
  }
}

template <typename T>
void insertAtBot(stacki<T>& stack, T k)
{
  if (stack.isEmpty()){
    stack.push(k);
  }
  else{
    //all items are held in the call stack until the end of stack is reached and the item is inserted at the bottom

    T a = stack.peek();
    stack.pop();
    insertAtBot(stack, k);

    //push all items held in call stack
    //once item is inserted at the bottom
    stack.push(a);
  }
}

template <typename T>
void reverseOne(stacki<T>& stackeroo){
  if (!stackeroo.isEmpty()){

    //hold all items in function
    //call stack until end of stack
    T a = stackeroo.peek();
    stackeroo.pop();
    reverseOne(stackeroo);

    insertAtBot(stackeroo, a);
  }
  return;
}



int main(){
  stacki<int> stack1;
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);
  stacki<int> stackrev;

  cout << "this is the stack: ";
  stack1.print();
  cout << endl;
  reverse_stack(stack1, stackrev);
  cout <<"this is the stack reversed: " << endl;
  stackrev.print();

  while(!stackrev.isEmpty()){
    stackrev.pop();
  }
  cout<< "now "; stackrev.print();

  stacki<char> stacka;
  stacka.push('c');
  stacka.push('b');
  stacka.push('a');
  cout << endl << "this is another stack: ";
  stacka.print();
  cout << endl;
  reverseStackv2(stacka);
  cout <<"this is the stack reversed: ";
  stacka.print();

  while(!stacka.isEmpty()){
    stacka.pop();
    }
  cout << " now "; stacka.print();
  cout << endl << "now trying to reverse a stack recursively with only the stack itself" << endl;
  stacki<double> onerecur;
  onerecur.push(5);
  onerecur.push(4);
  onerecur.push(9);
  cout << "this is the stack: "; 
  onerecur.print();
  reverseOne(onerecur);
  cout << endl << "this is the stack reversed: ";
  onerecur.print();
}







  
