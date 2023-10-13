#include <iostream>
using namespace std;

template <class T>
struct node{
T one;
node <T> *next;
};

template <class T>
class stacki{
  private:
    node <T> * top;
  public:
    stacki(){
    top = nullptr;
}
node <T>gettop(){
  return top;
}
void pop(){
  if (!isEmpty()){
    node<T> *temp = top;
    top = top->next;
    delete temp;
  }
}

T peek(){
  if (!isEmpty()){
    return top->one;
  }
}
void push(T k){
  node<T> *newNode = new node<T>();
  newNode->one = k;

  if(isEmpty()){
    top = newNode;
  }

  else
  {
    newNode -> next = top;
    top = newNode;
  }

  }

bool isEmpty(){
  return top == nullptr;
}

void print()
{
  if (isEmpty())
  {
    cout <<"stack is empty" << endl;
    return;
  }
  else{
    node<T>* current = top;

    while(current!=nullptr)
      {
        cout << current->one << " ";
        current = current->next;
      }
  }
}


};