#include <iostream>
using namespace std;

struct node {
    int number;
    node* next;
};

class dhash {
private:
    node** elt; 
    int size;

    int h1(int x) {
        return x % size;
    }

    int h2(int x) {
        return 3 - (x % 3);
    }

public:
  dhash(int s = 10) {
        size = s;
        elt = new node*[size];
        for (int i = 0; i < size; i++) {
            elt[i] = nullptr; 
        }
    }

    void doubleHashing(int x) {
        int index = h1(x);
        int step = h2(x);
        int i = 0;

        while (elt[index] != nullptr) {
            i++;
            index = (index + i * step) % size;
        }

        node* newNode = new node;
        newNode->number = x;
        newNode->next = nullptr;

        if (elt[index] == nullptr) {
            elt[index] = newNode;
        }
    }

bool search(int x) {
    int index = h1(x);
    int step = h2(x);
    int i = 0;

    while (elt[index] != nullptr) {
        if (elt[index]->number == x) {
            return true; 
        }
        i++;
        index = (index + i * step) % size;
    }

    return false;
}


void deleteElement(int x) {
    int index = h1(x);
    int step = h2(x);
    int i = 0;

    while (elt[index] != nullptr) {
        if (elt[index]->number == x) {
            cout << "deleting " << x << " from index " << index << endl;
            delete elt[index];
            elt[index] = nullptr;
            return;
        }
        i++;
        index = (index + i * step) % size;
    }
}


void print() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        if (elt[i] != nullptr) {
            node* current = elt[i];
            while (current != nullptr) {
                cout << current->number << " ";
                current = current->next;
            }
        }
        cout << endl;
    }
}
};
