#include "s.h"
#include <stdexcept>
using namespace std;

template <class T>
Stack<T>::Stack() {
    top = nullptr;
}

template <class T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <class T>
void Stack<T>::push(const T& item) {
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

template <class T>
void Stack<T>::pop() {
    if (isEmpty()) {
        return; // Stack is empty, nothing to pop
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;
}

template <class T>
T& Stack<T>::peek() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return top->data;
}

template <class T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template class Stack<char>;  // Instantiate the Stack template with char type

