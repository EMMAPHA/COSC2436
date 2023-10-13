#ifndef MyStackLL_h
#define MyStackLL_h

#include <iostream>
using namespace std; 

template <typename T>

struct node{
    T data;
    node<T>* next = nullptr;

};

template <typename T>
class MyStackLL{


private:
    node<T> *top;

public:
    MyStackLL(){
        top = nullptr;
    }

    ~MyStackLL(){
        while(!isEmpty()){
            pop();
        }
    }

    bool isEmpty(){
        return top == nullptr;
    }

    T peek(){ 
        if(!isEmpty()){
        return top->data;
        }
       return T();
    }

    void push(T v){
        node<T>* newThing = new node<T>();
        newThing->data = v;
        if(isEmpty()){
            top = newThing;
        }
        else{
            newThing->next = top;
            top = newThing;
        }
    }

    void pop(){
        if(!isEmpty()){
            node<T>* temp = top;
            top = top -> next;
            delete temp;
        }
    }
/* void printTail(){

    if(top == nullptr){
        return;
    }
    node<T>* current = top; //have to start from somewhere which is the head

    while(current != nullptr){ //stop at last node
        cout << current->data << " "; //
        current = current->next;
    }
    cout << endl;
    if(current == nullptr){
        return;
    } 
}  */

};

#endif 