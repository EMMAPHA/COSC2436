#include <iostream>
#include "word.h"
using namespace std;

void word::insertatbeg(char x) {
  //create
  onechar *newNode = new onechar;

  newNode->prev = newNode->next = nullptr;
  //fill
  newNode->l = x;

  if (isEmpty()) {
    newNode->next = head;
    head = newNode;
  } else {
    onechar *temp = head;
    newNode->next = temp;
    head = newNode;
    temp->prev = head;
  }
}

void word::del_c(char x) {
  if (isEmpty()) {
    return;
  }
  
  onechar *curr = head;
  onechar *prev = nullptr;
  
  while (curr != nullptr) {
    if (curr->l == x) {
      if (prev != nullptr) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      } else {
        head = curr->next;
        delete curr;
        curr = head;
      }
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}

void word::print(onechar *curr) {
  if (isEmpty()) {
    return;
  } else {
    while (curr != nullptr) {
      cout << curr->l;
      curr = curr->next;
    }
  }
}

void word::recPrint(onechar *curr) {
  if (curr == nullptr) { //returns nothing is there is a nullptr
    return;
  }
  cout << curr->l;
  recPrint(curr->next);
}

void word::reversePrint(onechar *curr) {
  onechar* end = new onechar;
  
  if (curr == nullptr) {
    return;
  }
  cout << curr->l;
  curr = curr->prev;
  reversePrint(curr->prev);
}