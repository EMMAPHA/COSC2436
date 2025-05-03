#ifndef doublyLL_h
#define doublyLL_h

#include <iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;

    node(int _data) {
        this->prev = this->next = nullptr;
        this->data = _data;
    }
};

class doublyLL {
private:
    node* head;
    int size;

public:
    doublyLL() {
        head = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        int size = 0;
        node* cur = head;
        while (cur != nullptr) {
            size++;
            cur = cur->next;
        }
        return size;
    }

    void append(int _data) {
        node* newNode = new node(_data);
        size++;

        if (isEmpty()) {
            head = newNode;
            return;
        }

        if (getSize() == 1) {
            head->next = newNode;
            newNode->prev = head;
        } else {
            node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
            newNode->prev = cur;
        }
    }

    void display(ostream& os) {
        node* cur = head;
        os << "[";
        while (cur != nullptr) {
            os << cur->data;
            if (cur->next) {
                os << ",";
            }
            cur = cur->next;
        }
        os << "]" << endl;
    }

    node* getHead() {
        return head;
    }

    // maybe some stuff here if needed
};

#endif
